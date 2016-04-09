//person_add_search_remove.h
//Funktionsprototyper för att lägga till, söka och ta bort person i listan. Även några extra funktioner finns här.
//Simon
//2015-12-09
//--------------------------------------------------

#ifndef person_add_search_removeH
#define person_add_search_removeH
	#include <iostream>
	#include <iterator>
	#include <vector>
	#include <string>
	#include <sstream>
	#include <algorithm>
	#include <iomanip>
	using namespace std;
	#include "constants.h"

	vector <Person> add_person(vector <Person> v);
	string generate_sign(string firstName, string lastName);
	string to_germaner(string name);
	string add_leap_no(string s, int i);
	double round(double value);
	void search_person(vector <Person> v);
	vector <Person> remove_person(vector <Person> v);

#endif