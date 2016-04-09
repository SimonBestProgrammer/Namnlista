//sort_random.cpp
//Funktionsdefinitioner för att sortera listan.
//Simon
//2015-12-09
//--------------------------------------------------

#include "sort_random.h"

//--------------------------------------------------


//--------------------------------------------------
//sort_list
//--------------------------------------------------
// Uppgift: Sorterar listan på namn, signatur eller längd
// Indata : Vektor som innehåller namnlistan, enum hur sorteringen skall gå till
// Utdata : Returnerar en vektor med namlistan som är sorterad
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
// Uppgift: Göra en jämförelse på två namn
// Indata : Strukt Person med ena namnet, strukt Person med andra namnet
// Utdata : Returnerar om jämförelsen är sann eller ej
//--------------------------------------------------
bool name_sort(const Person& a, const Person& b)		//Sorterar på namn
{
	string name_a, name_b;	
	name_a = to_germaner(a.lastName) + to_germaner(a.firstName);
	name_b = to_germaner(b.lastName) + to_germaner(b.firstName);

	return name_a < name_b;
}

//--------------------------------------------------
//sign_sort
//--------------------------------------------------
// Uppgift: Göra en jämförelse på två signatur
// Indata : Strukt Person med ena signaturen, strukt Person med andra signaturen
// Utdata : Returnerar om jämförelsen är sann eller ej
//--------------------------------------------------
bool sign_sort(const Person& a, const Person& b)		//Sorterar på signatur
{
	return a.sign < b.sign;
}

//--------------------------------------------------
//length_sort
//--------------------------------------------------
// Uppgift: Göra en jämförelse på två längder
// Indata : Strukt Person med ena längden, strukt Person med andra längden
// Utdata : Returnerar om jämförelsen är sann eller ej
//--------------------------------------------------
bool length_sort(const Person& a, const Person& b)		//Sorterar på längd
{
	return a.length > b.length;
}

//--------------------------------------------------
//random_list
//--------------------------------------------------
// Uppgift: Slumpa ordningen av listan
// Indata : Vektor som innehåller namnlistan
// Utdata : Returnerar en vektor med namlistan som har slumpad ordning
//--------------------------------------------------
vector <Person> random_list(vector <Person> v)
{
	random_shuffle(v.begin(), v.end());
	return v;
}
