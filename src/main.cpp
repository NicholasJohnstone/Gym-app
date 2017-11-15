#include<iostream>

#include "utilities.h"
#include "filesystem.h"
#include "Routine.h"

int main(int argc, char** argv)
{
	while(true){
		cout<<CLEAR_SCREEN;
		cout<<"Choosing routine, ";
		vector<string> routine_list=filesystem::read_folders();
		int return_index=0;
		string* routine_name=select_from_list(routine_list,{{"new",'n'},{"finished",'f'}},return_index);
		switch(return_index){
			case 0:		{
					Routine selected_routine{get_line("Enter name of new routine")};
					selected_routine.enter();
					}
					break;				
			case -1:  	{
					Routine selected_routine(*routine_name);
					selected_routine.enter();
					}
				 	break;
			case 1: 	return 0;
		}
	}  
}	

      
