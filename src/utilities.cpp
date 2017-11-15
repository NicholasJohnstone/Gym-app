#include "utilities.h"

#include<iostream>

#include "filesystem.h"
string get_string(const string& message){
	cout<<message<<"\n>";
	string word;
	cin>>word;
	cout<<CLEAR_SCREEN;
	return word;
}

string get_line(const string& message){
	string line;
	while(line==""){
		cout<<message<<"\n>";
		getline(cin,line);
		cout<<CLEAR_SCREEN;
	}
	cout<<CLEAR_SCREEN;
	return line;
}

size_t select_from_pairs(const vector<pair<string,char>>& list){
	cout<<"select option-\n";
	for(auto x:list){
		cout<<x.second<<" : "<<x.first<<endl;
	}
	char response;
	while(true){ 
		cout<<">";
		cin>>response;
		for(size_t i = 0; i != list.size(); i++){
			if(response==list[i].second){
				cin.ignore();		//clear the '\n'
				cout<<CLEAR_SCREEN;
				return i;
			}
		}
	}
}	
		
string* select_from_list(vector<string>& string_list,vector<pair<string,char>> pair_list,int& return_code){
	for(size_t i = 0; i != string_list.size(); i++){
		pair_list.insert(pair_list.begin()+i,{string_list[i],'1'+i});
	}
	size_t result=select_from_pairs(pair_list);
	if(result>=string_list.size()){
		return_code=result-string_list.size();
		return NULL;
	}
	return_code=-1;
	return &string_list[result];
}



 







