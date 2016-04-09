//print_meny_list.h
//Funktionsprototyper för utskrift av meny och listan
//Simon
//2015-12-09
//--------------------------------------------------

#ifndef print_meny_listH
#define print_meny_listH
	#include <iostream>
	#include <string>
	#include <vector>
	#include <iomanip>
	using namespace std;
	#include "constants.h"

	int print_meny(vector <string> v);
	void print_list(vector <Person> v);

#endif

