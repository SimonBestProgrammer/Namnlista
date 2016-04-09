//print_meny_list.cpp
//Funktionsdefinitioner för utskrift av meny och listan
//Simon
//2015-12-09
//--------------------------------------------------

#include "print_meny_list.h"

//--------------------------------------------------

//--------------------------------------------------
//print_meny
//--------------------------------------------------
// Uppgift: Skriver ut menyn och skickar tillbaka valt allternativ
// Indata : Vektor som inehåller menytext
// Utdata : Returnerar vilket menyalternativ som är valt som en int
//--------------------------------------------------
int print_meny(vector <string> v)
{
	int a;

	for (auto idx : v)
	{
		cout << idx << endl;
	}

	cin >> a;
	cin.get();										//Rensar bort ENTER

	return a;
}


//--------------------------------------------------
//print_list
//--------------------------------------------------
// Uppgift: Skriva ut listan
// Indata : Vektor som innehåller namnlistan
// Utdata : inget
//--------------------------------------------------
void print_list(vector <Person> v)
{
	//Skriver ut rubrik
	cout << "Antal personer i listan: " << v.size() << endl;
	cout << "Nr.  Signatur    Namn                      L\x84ngd [m]" << endl;
	cout << "---  ---------   --------                  ----------" << endl;

	//Skriver ut själva listan
	int i = 1;
	for (auto idx : v)
	{

		cout << right << setw(2) << i << "." << "  ";
		cout << left << setw(12) << idx.sign;
		cout << setw(27) << idx.firstName + " " + idx.lastName;
		cout << right << setw(5) << fixed << setprecision(2) << idx.length << endl;
		if (i % 20 == 0)
		{
			system("PAUSE");						//Tryck på valfri tangent för att visa mer av listan...
		}
		i++;

	}
	cout << endl;
}
