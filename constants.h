//constants.h
//Konstanter som anv�nds i projektet.
//Simon
//2015-12-09
//--------------------------------------------------


#ifndef constantsH
#define constantsH
	const struct Person								//Strukturdefinition
	{
		string firstName;
		string lastName;
		string sign;
		double length;
	};

	const enum sort_choice {name, sign, length};	//Def av sorteringen
	const char DELIM = '|';							//Avgr�nsare

#endif