#include "Text_field.h"

#include<iostream>
#include<sstream>
#include<iomanip>


#include "utilities.h"

void String_field::enter(){
	if(!option_list.empty()){
		cout<<name<<":\n";
		int result=select_from_pairs(option_list);
		value=option_list[result].first;
	} else{
		string in=get_line("enter value for "+name+":");
		value=in;
	}
}

string String_field::to_string() const{
			return name+" = "+value;
		}

string String_field::get_string_value() const{
	return value;
}

string String_field::get_value() const{
	return value;
}

void String_field::set_value(const string& in_value){
	value=in_value;
}

void Double_field::enter(){
	cout<<"enter value for "<<name<<":\n>";
	string throw_away;
	while(!(cin>>value)){
		cin.clear();
		getline(cin,throw_away);
		cout<<CLEAR_SCREEN<<"enter value for "+name<<":\n (Must be a number)\n>";
	}
	cin.ignore();
	cout<<CLEAR_SCREEN;
}

string Double_field::to_string() const{
			ostringstream stream;
			stream<<name<<" = "<<value;
			return stream.str();
	}

string Double_field::get_string_value() const{
	ostringstream stream;
	stream<<value;
	return stream.str();
}

void Double_field::set_value(const string& in_value){
	istringstream stream{in_value};
	stream>>value;
}

double Double_field::get_value() const{
			return value;
		}
ostream& operator<<(ostream& os, const Text_field& f){
	os<<f.get_string_value();
	return os;
}

