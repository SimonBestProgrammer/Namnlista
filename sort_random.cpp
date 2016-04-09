//sort_random.cpp
//Funktionsdefinitioner f�r att sortera listan.
//Simon
//2015-12-09
//--------------------------------------------------

#include "sort_random.h"

//--------------------------------------------------


//--------------------------------------------------
//sort_list
//--------------------------------------------------
// Uppgift: Sorterar listan p� namn, signatur eller l�ngd
// Indata : Vektor som inneh�ller namnlistan, enum hur sorteringen skall g� till
// Utdata : Returnerar en vektor med namlistan som �r sorterad
//--------------------------------------------------
vector <Person> sort_list(vector <Person> v, enum sort_choice sort_val)
{ 

	if (sort_val == name)
	{
		sort(v.begin(), v.end(), name_sort);
	}
	else if (sort_val == sign)
	{
		sort(v.begin(), v.end(), sign_sort);
	}
	else if (sort_val == length)
	{
		sort(v.begin(), v.end(), length_sort);

	}

	return v;
}

//--------------------------------------------------
//name_sort
//--------------------------------------------------
// Uppgift: G�ra en j�mf�relse p� tv� namn
// Indata : Strukt Person med ena namnet, strukt Person med andra namnet
// Utdata : Returnerar om j�mf�relsen �r sann eller ej
//--------------------------------------------------
bool name_sort(const Person& a, const Person& b)		//Sorterar p� namn
{
	string name_a, name_b;	
	name_a = to_germaner(a.lastName) + to_germaner(a.firstName);
	name_b = to_germaner(b.lastName) + to_germaner(b.firstName);

	return name_a < name_b;
}

//--------------------------------------------------
//sign_sort
//--------------------------------------------------
// Uppgift: G�ra en j�mf�relse p� tv� signatur
// Indata : Strukt Person med ena signaturen, strukt Person med andra signaturen
// Utdata : Returnerar om j�mf�relsen �r sann eller ej
//--------------------------------------------------
bool sign_sort(const Person& a, const Person& b)		//Sorterar p� signatur
{
	return a.sign < b.sign;
}

//--------------------------------------------------
//length_sort
//--------------------------------------------------
// Uppgift: G�ra en j�mf�relse p� tv� l�ngder
// Indata : Strukt Person med ena l�ngden, strukt Person med andra l�ngden
// Utdata : Returnerar om j�mf�relsen �r sann eller ej
//--------------------------------------------------
bool length_sort(const Person& a, const Person& b)		//Sorterar p� l�ngd
{
	return a.length > b.length;
}

//--------------------------------------------------
//random_list
//--------------------------------------------------
// Uppgift: Slumpa ordningen av listan
// Indata : Vektor som inneh�ller namnlistan
// Utdata : Returnerar en vektor med namlistan som har slumpad ordning
//--------------------------------------------------
vector <Person> random_list(vector <Person> v)
{
	random_shuffle(v.begin(), v.end());
	return v;
}
