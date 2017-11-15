#ifndef EXERCISE_H_
#define EXERCISE_H_

#include<string>
#include<iostream>

#include "Text_field.h"

using namespace std;
class Exercise{
	public:
		Exercise(){}
		Exercise(const Exercise& e);
		void enter();
		string to_string() const;
		double get_score(double score,double pb) const;
		friend ostream& operator<<(ostream& os, const Exercise& e);
		friend istream& operator>>(istream& is, Exercise& e);
	private:
		void initiate();
		void edit();

		String_field name_field{"name",{}};
		String_field score_type={"scores relative to",{{"personal best",'p'},{"reference score",'r'}}};
		Double_field reference_score{"reference score"};
		vector<Text_field*> field_list={&name_field,&score_type,&reference_score};
		bool initiated=false;

};

#endif //EXERCISE_H_
