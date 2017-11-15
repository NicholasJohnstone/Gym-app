#ifndef FILESYSTEM_H_
#define FILESYSTEM_H_

#include<string>
#include<fstream>
#include<vector>
#include<map>
#include<iostream>

#include "utilities.h"

using namespace std;

namespace filesystem{
const string data_directory = "../data/";

vector<string> read_folders();
void add_folder(const string& foldername);
void remove(const string& filename);
void rename(const string& old_name,const string& new_name);

void open_on_screen(const string& filename);

template <class S,class T>
bool write_to_file(const string& filename,const S& body,const T& header){
	string path=data_directory+filename;
	ofstream out_stream{path};
	if(out_stream){
		out_stream<<header<<'\n'<<body;
		return true;
	} else{
		cout<<"failed to write\n";
		return false;
	}		
}

template <class T>
bool read_from_file(const string& filename,T& body){
	string path=data_directory+filename;
	ifstream in_stream{path};
	if(in_stream){
		string header;
		getline(in_stream,header);			//ignore header line
		in_stream>>body;
		return true;
	} else{
		return false;
	}		
}

}	//filesystem

#endif //FILESYSTEM_H_
