#include<iostream>

#include "utilities.h"
#include "filesystem.h"
#include "Routine.h"

void int_vector_test(){
	vector<int> origional={1,2,3,3};
	vector<int> read_back;
	stringstream stream;
	stream<<origional;
	stream>>read_back;
	cout<<"int vector test-"<<endl;
	cout<<"initial:\n"<<origional<<endl;
	cout<<"read back:\n"<<read_back<<endl;
	cout<<endl;	
}

void string_to_int_vector_test(){
	vector<int> origional={1,2,3,3};
	vector<string> read_back;
	stringstream stream;
	stream<<origional;
	stream>>read_back;
	cout<<"string to int vector test-"<<endl;
	cout<<"initial:\n"<<origional<<endl;
	cout<<"read back:\n"<<read_back<<endl;
	cout<<endl;		
}

void string_vector_test(){
	vector<string> origional={"","sfsd  gf","dd","dad"};
	vector<string> read_back;
	stringstream stream;
	stream<<origional;
	stream>>read_back;
	cout<<"string vector test-"<<endl;
	cout<<"initial:\n"<<origional<<endl;
	cout<<"read back:\n"<<read_back<<endl;
	cout<<endl;	
}
void exercise_test(){
	Exercise origional;
	Exercise read_back;
	stringstream stream;
	stream<<origional;
	stream>>read_back;
	cout<<"exercise test-"<<endl;
	cout<<"initial:\n"<<origional<<endl;
	cout<<"read back:\n"<<read_back<<endl;
	cout<<endl;
}

void exercise_vector_test(){
	vector<Exercise> origional(3);
	vector<Exercise> read_back;
	stringstream stream;
	stream<<origional;
	stream>>read_back;
	cout<<"exercise vector test-"<<endl;
	cout<<"initial:\n"<<origional<<endl;
	cout<<"read back:\n"<<read_back<<endl;
	cout<<endl;
}

void vector_vector_test(){
	vector<vector<int>> origional{{1,2,3},{4,5,6}};
	vector<vector<int>> read_back;
	stringstream stream;
	stream<<origional;
	stream>>read_back;
	cout<<"vector vector test-"<<endl;
	cout<<"initial:\n"<<origional<<endl;
	cout<<"read back:\n"<<read_back<<endl;
	cout<<endl;
}

void int_map_test(){
	map<string,int> origional{
		{"test1",1},{"test2",2},{"test3",3}
	};
	map<string,int> read_back;
	stringstream stream;
	stream<<origional;
	stream>>read_back;
	cout<<"int map test-"<<endl;
	cout<<"initial:\n"<<origional<<endl;
	cout<<"read back:\n"<<read_back<<endl;
	cout<<endl;
}

void map_with_empty_test(){
	map<string,int> origional{
		{"",1},{"test2",2},{"test3",3}
	};
	map<string,int> read_back;
	stringstream stream;
	stream<<origional;
	stream>>read_back;
	cout<<"int map test-"<<endl;
	cout<<"initial:\n"<<origional<<endl;
	cout<<"read back:\n"<<read_back<<endl;
	cout<<endl;
}



int main(int argc, char** argv)
{
	int_vector_test();
	string_to_int_vector_test();
	string_vector_test();
	exercise_test();
	exercise_vector_test();
	vector_vector_test();
	int_map_test();
	map_with_empty_test();
}	

      
