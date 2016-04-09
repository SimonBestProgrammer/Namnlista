//file_read_write.h
//Funktionsprototyper för att läsa och skriva till fil.
//Simon
//2015-12-09
//--------------------------------------------------

#ifndef file_read_writeH
#define file_read_writeH
	#include <iostream>
	#include <vector>
	#include <fstream>
	#include <string>
	#include <sstream>
	using namespace std;
	#include "constants.h"
	
	void write_list(vector <Person> v);
	vector <Person> read_list(vector <Person> v);
	string encrypt(string str, int key);
	string decrypt(string str, int key);

#endif