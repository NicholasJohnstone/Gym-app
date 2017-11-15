#ifndef TEXT_FIELD_H_
#define TEXT_FIELD_H_

#include<vector>
#include<string>
#include<utility>
#include<sstream>
#include<iostream>

#include "utilities.h"
using namespace std;

class Text_field{
	public:
		virtual void enter()=0;
		virtual string to_string() const =0;
		virtual string get_string_value() const=0;
		virtual void set_value(const string& in_value)=0;
};

class String_field: public Text_field{
	public:
		String_field(string name_input,vector<pair<string,char>> input_options)
		:name{name_input},option_list{input_options} {}
		void enter() override;
		string to_string() const override;
		string get_string_value() const override;
		void set_value(const string& in_value) override;
	
		string get_value() const;
	private:
		string name;
		string value="default";
		vector<pair<string,char>> option_list;
};

class Double_field:public Text_field{
	public:
		Double_field(string name_input)
		:name{name_input} {}
		void enter() override;
		string to_string() const override;
		string get_string_value() const override;
		void set_value(const string& in_value) override;
		
		double get_value() const;
	private:
		string name;
		double value=0;
};

ostream& operator<<(ostream& os, const Text_field& f);
#endif //TEXT_FIELD_H_
