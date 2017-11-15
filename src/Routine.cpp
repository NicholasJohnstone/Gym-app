#include "Routine.h" 

#include<iostream>
#include<string>
#include<map>

#include "utilities.h"
#include "Exercise.h"
#include "filesystem.h"
 
Routine::Routine(const string& name_input)
:name{name_input} {
	validate();
	filesystem::read_from_file(name+"/exercises.csv",exercise_list);
	filesystem::read_from_file(name+"/pbs.csv",pb_map);
}

void Routine::enter(){
	while(true){
		cout<<"Editing "<<name<<", ";
		int return_index=select_from_pairs({
		{"input scores",'i'},{"view pbs",'v'},{"edit exercises",'e'},{"add user",'a'},{"rename",'r'},{"delete",'d'},{"finished",'f'}
		});
		cout<<CLEAR_SCREEN;
		switch(return_index){
			case 0:	input_scores();
				break;
			case 1: filesystem::open_on_screen(name+"/pbs.csv");
				break;
			case 2: edit_exercises();
				break;
			case 3: add_user();
				break;
			case 4: rename();
				break;
			case 5:	filesystem::remove(name);
				return;
			case 6: return;
		}
	} 
}

string Routine::to_string() const{
		return name;
}

void Routine::validate(){
	filesystem::add_folder(name);
	filesystem::add_folder(name+"/raw_scores");
	filesystem::add_folder(name+"/results");		
}

void Routine::input_scores(){
	write_update_form(name+"/update.csv");
	filesystem::open_on_screen(name+"/update.csv");
	int return_index=select_from_pairs({{"cancel",'c'},{"finished",'f'}});
	if(return_index==0){
		return;
	}
	string session_name=get_string("Enter name of session:");
	map<string,vector<double>> raw_score_map;	
	filesystem::read_from_file(name+"/update.csv",raw_score_map);
	filesystem::write_to_file(name+"/raw_scores/"+session_name+".csv",raw_score_map,exercise_header());
	update_pbs(raw_score_map);
	map<string,vector<double>> result_map=calculate_result(raw_score_map);
	filesystem::write_to_file(name+"/results/"+session_name+".csv",result_map,exercise_header());
}

void Routine::edit_exercises(){
	bool not_done=true;
	while(not_done){
		cout<<"Editing exercises for "<<name<<", ";
		int return_index;
		Exercise* exercise=select_from_list(exercise_list,{{"new",'n'},{"finished",'f'}},return_index);
		cout<<CLEAR_SCREEN;
		switch(return_index){
			case -1:	exercise->enter();
					break;
			case 0: 	{
					Exercise new_exercise;
					new_exercise.enter();
					exercise_list.push_back(new_exercise);	//copy here
					}
					break; 
			case 1: 	not_done=false;
					break;
		}
	}
	filesystem::write_to_file(name+"/exercises.csv",exercise_list,"Exercise details");
}

void Routine::add_user(){
	string user_name = get_line("Enter name:");
	pb_map[user_name];
	filesystem::write_to_file(name+"/pbs.csv",pb_map,exercise_header());
}

void Routine::rename(){
	string old_name=name;
	name=get_string("enter new name:");
	filesystem::rename(old_name,name);
}

vector<string> Routine::exercise_header() const{
	vector<string> header;
	header.push_back("");
	for(auto exercise: exercise_list){
		header.push_back(exercise.to_string());
	}
	return header;
}

void Routine::write_update_form(const string& filename) const{
	vector<string> input_space(exercise_list.size());	
	map<string,vector<string>> input_map;
	for(const auto& entry:pb_map){
		input_map.insert({entry.first,input_space});
	}
	filesystem::write_to_file(filename,input_map,exercise_header());
}

void Routine::update_pbs(const map<string,vector<double>>& raw_score_map){
	for(auto entry:raw_score_map){
		vector<double> score_list=entry.second;
		vector<double>& pb_list=pb_map[entry.first];
		for(size_t i=0;i<score_list.size();i++){
			if(i<pb_list.size()){
				if(pb_list[i]<score_list[i]){
					pb_list[i]=score_list[i];
				}
			} else{
				pb_list.push_back(score_list[i]);
			}
		}
	}
	filesystem::write_to_file(name+"/pbs.csv",pb_map,exercise_header());
}

map<string,vector<double>> Routine::calculate_result(const map<string,vector<double>>& raw_score_map) {
	map<string,vector<double>> result_map;
	for(const auto& entry:raw_score_map){
		const vector<double>& user_scores=entry.second;
		const vector<double>& user_pbs=pb_map[entry.first];
		vector<double> user_results;
		for(size_t i=0;i<user_scores.size() && i<user_pbs.size() && i<exercise_list.size();i++){
			double result=exercise_list[i].get_score(user_scores[i],user_pbs[i]);
			user_results.push_back(result);
		}
		result_map[entry.first]=user_results;
	}
	return result_map;	
}
