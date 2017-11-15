#ifndef UTILITIES_H_
#define UTILITIES_H_

#include<string>
#include<iostream>
#include<sstream>
#include<vector>
#include<map>

using namespace std;

const string CLEAR_SCREEN="\033[2J\033[1;1H";

string get_string(const string& message);

string get_line(const string& message);

size_t select_from_pairs(const vector<pair<string,char>>& list);

//pair_list is passed by value because it is alter in the implementation
string* select_from_list(vector<string>& string_list,vector<pair<string,char>> pair_list,int& return_code);

template <class T>
T* select_from_list(vector<T>& T_list,vector<pair<string,char>> pair_list,int& return_code){
	for(vector<int>::size_type i = 0; i != T_list.size(); i++){
		pair_list.insert(pair_list.begin()+i,{T_list[i].to_string(),'1'+i});
	}
	size_t result=select_from_pairs(pair_list);
	if(result>=T_list.size()){
		return_code=result-T_list.size();
		return NULL;
	} else {
		return_code=-1;
		return &T_list[result];
	}
}

template <class T,class A>
ostream& operator<<(ostream& os, const vector<T,A>& v){
	os<<"{,";
	for(auto iter=v.begin();;++iter){
		if(iter==v.end()){
			os<<'}';
			break;
		} else {
		os<<*iter<<',';
		}
	}
	return os;
}
template <class A>
istream& operator>>(istream& is, vector<string,A>& v){
	v.clear();
	string value;
	string body;
	char test;
	is>>ws>>test;
	if(test!='{'){
		is.unget();
		is.clear(std::istream::failbit);
		return is;
	}
	is>>ws;
	is>>test;
	if(test!=','){
		is.unget();
		is.clear(std::istream::failbit);
		return is;
	}
	if(!getline(is,body,'}')){
		return is;
	}
	istringstream body_stream{body};
	while(getline(body_stream,value,',')){
		v.push_back(value);
	}
	return is;
} 
 
template <class T,class A>
istream& operator>>(istream& is, vector<T,A>& v){
	v.clear();
	T value;
	string clause;
	char delimiter=',';
	char test;
	is>>ws>>test;
	if(test!='{'){
		is.unget();
		is.clear(std::istream::failbit);
		return is;
	}
	is>>ws;
	is>>test;
	if(test!=','){
		is.unget();
		is.clear(std::istream::failbit);
		return is;
	}
		
	while(getline(is,clause,delimiter)){
		istringstream clause_stream{clause};
		clause_stream>>ws;
		test = clause_stream.peek();
		switch(test){
			case '{':	
				getline(is,clause,'}');
				is.ignore();
				clause_stream.str("{,"+clause+"}");
				break;
			case '}':	is.clear();
				return is;
		default:	break;
		}
		clause_stream>>value;
		if(!clause_stream){
			is.clear(std::istream::failbit);
			return is;
		}
		v.push_back(value);
	}
	return is;
} 

template <class K ,class V>
ostream& operator<<(ostream& os, const map<K,V>& m){
	os<<"{\n";
	for(auto iter=m.begin();;iter++){
		if(iter==m.end()){
			os<<"}";
			break;
		}
		os<<iter->first<<","<<iter->second<<'\n';
	}	
	return os;	
}

template <class V>
istream& operator>>(istream& is, map<string,V>& m){
	m.clear();
	string line;
	string key;
	V value;
	char test;
	is>>ws>>test;
	if(test!='{'){
		is.unget();
		is.clear(std::istream::failbit);
		return is;
	}
	test=0;
	is>>ws;
	while(getline(is,line)){
		istringstream line_stream{line};
		getline(line_stream,key,',');
		if(key!=""){
			line_stream>>value;
			istringstream test_stream{key};
			test_stream>>ws>>test;
			if(test=='}'){
				return is;
			}
			test=0;	//add this to others
			m.insert({key,value});
		}
	}	
	return is;	
}


#endif //UTILITIES_H_
