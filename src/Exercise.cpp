#include "Exercise.h"

#include<string>
#include<iostream>
#include <sstream>

#include "Text_field.h"
#include "utilities.h"

Exercise::Exercise(const Exercise& e){
	name_field=e.name_field;
	score_type=e.score_type;
	reference_score=e.reference_score;
	field_list={&name_field,&score_type,&reference_score};
	initiated=e.initiated;
}

void Exercise::enter(){
	if(initiated){
		edit();
	} else{		
		initiate();
	}
}

string Exercise::to_string() const{
	return name_field.get_value();
}

double Exercise::get_score(double score,double pb) const{
	if(score_type.get_value()=="personal best"){
		return score/pb;
	} else if(score_type.get_value()=="reference score"){
		return score/reference_score.get_value();
	} else{
		return -1;
	}
}

void Exercise::initiate(){
	for(auto& field:field_list){
		field->enter();
	}
	initiated=true;
}

void Exercise::edit(){
	while(true){
		cout<<"Editing "<<to_string()<<", ";
		int return_index;	
		vector<string> selection_list;
		for(Text_field* field:field_list){
			selection_list.push_back(field->to_string());
		}
		string* selection=select_from_list(selection_list,{{"finished",'f'}},return_index);
		cout<<CLEAR_SCREEN;
		switch(return_index){
			case -1:	for(Text_field* field:field_list){
						if(field->to_string()==*selection){
							field->enter();
						}
					}
					break;
			case 0: 	return;
		}
	}
}
		
ostream& operator<<(ostream& os, const Exercise& e){
	string text;
	vector<string> text_list;
	for(auto iter=e.field_list.begin();iter!=e.field_list.end();++iter){
		stringstream stream;
		if(iter==e.field_list.begin()){
			stream<<'\n';
		}
		stream<<**iter;
		text=stream.str();
		text_list.push_back(text);
	}
	os<<text_list;
	return os;
}
		
istream& operator>>(istream& is, Exercise& e){
	string text;
	vector<string> text_list;
	is>>text_list;
	if(text_list.size()!=e.field_list.size()){
		is.clear(std::istream::failbit);
		return is;
	}
	text_list[0].erase(0,1);
	for(size_t i=0;i<text_list.size();i++){
		e.field_list[i]->set_value(text_list[i]);
		
	}
	e.initiated=true;
	return is;
}	
