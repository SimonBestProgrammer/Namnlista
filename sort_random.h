//sort_random.h
//Funktionsprototyper för att sortera listan.
//Simon
//2015-12-09
//--------------------------------------------------

#ifndef sort_randomH
#define sort_randomH
	#include <iostream>
	#include <vector>
	#include <algorithm>
	using namespace std;
	#include "constants.h"
	#include "person_add_search_remove.h"

	vector <Person> sort_list(vector <Person> v, enum sort_choice);
	bool name_sort(const Person& a, const Person& b);
	bool sign_sort(const Person& a, const Person& b);
	bool length_sort(const Person& a, const Person& b);
	vector <Person> random_list(vector <Person> v);

#endif