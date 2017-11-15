#ifndef ROUTINE_H_
#define ROUTINE_H_

#include<string>
#include<vector>
#include<map>

#include "Exercise.h"
using namespace std;

class Routine{
	public:
		Routine(const string& name_input);
		void enter();
		string to_string() const;
	private:
		void validate();
		void input_scores();
		void edit_exercises();
		void add_user();
		void rename();
		
		vector<string> exercise_header() const;
		void write_update_form(const string& filename) const;
		void update_pbs(const map<string,vector<double>>& raw_score_map);
		map<string,vector<double>> calculate_result(const map<string,vector<double>>& raw_score_map) ;

		string name;
		map<string,vector<double>> pb_map;
		vector<Exercise> exercise_list;
};

#endif //ROUTINE_H_
 
