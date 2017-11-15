#include "filesystem.h"

#include<iostream>
#include<string>
#include<vector>

#include <boost/filesystem.hpp>
static const string OPEN_COMMAND="xdg-open ";
static const string SUPPRESS_OUTPUT_COMMAND="  > /dev/null 2>/dev/null";

namespace fs = boost::filesystem;
namespace filesystem{

vector<string> read_folders(){
	fs::path p(data_directory);
	vector<string> folder_list;
	if(fs::exists(p)){
		try{
			for(fs::directory_iterator itr(p); itr!=fs::directory_iterator(); ++itr){
				fs::path temp_path=itr->path();
				if(is_directory(temp_path)) {
					folder_list.push_back(temp_path.filename().string());
				}
			}
		} catch(...){
		}
	}
	return folder_list;
}

void add_folder(const string& foldername)
{
	try{
		fs::path dir(data_directory+foldername);
		if(!fs::exists(dir)){
			fs::create_directory(dir);
		}
	} catch(...){
		cout<<"couldn't add folder \n";
	}
}

void remove(const string& filename){ 
	try{
		fs::remove_all(data_directory+filename);
	} catch(...) {
		cout<<"couldn't remove file, maybe in use \n";
	}
	
}

void rename(const string& old_name,const string& new_name){
	try{
		fs::rename(data_directory+old_name,data_directory+new_name);
	} catch(...){
		cout<<"couldn't rename file, maybe in use\n";
	}	
}

void open_on_screen(const string& filename){		
	if(!fs::exists(fs::path(data_directory+filename))){
	} else{
		system((OPEN_COMMAND+data_directory+filename+SUPPRESS_OUTPUT_COMMAND).c_str());
	}
}

}	//namespace filesystem


