//Projekt Namnlista.cpp
//Programmet hanterar personer i en lista.
//Simon
//2015-12-09
//--------------------------------------------------


#include <iostream>
#include <vector>
using namespace std;
#include "constants.h"
#include "print_meny_list.h"
#include "person_add_search_remove.h"
#include "sort_random.h"
#include "file_read_write.h"


//--------------------------------------------------
int main()
{
	//Deklarera konstanter, variabler och vektorer
	int choice;
	vector <string> meny, meny_sort;
	vector <Person> NamnLista;

	meny.push_back("#### Programmeny: ####");
	meny.push_back("1.  L\x84gga till person");
	meny.push_back("2.  Skriv ut listan");
	meny.push_back("3.  S\x94k person");
	meny.push_back("4.  Ta bort person");
	meny.push_back("5.  Sortera listan");
	meny.push_back("6.  Slumpa listan");
	meny.push_back("7.  Spara listan");
	meny.push_back("8.  L\x84sa in listan");
	meny.push_back("9.  Avsluta?");

	meny_sort.push_back("#### Alternativ: ####");
	meny_sort.push_back("1.  Sortera p\x86 namn");
	meny_sort.push_back("2.  Sortera p\x86 signatur");
	meny_sort.push_back("3.  Sortera p\x86 l\x84ngd");


	//Skriver ut meny
	do
	{
		cout << "Antal namn i listan: " << NamnLista.size() << endl;
		choice = print_meny(meny);
		
		switch (choice)
		{
		case 1:
			cout << "# L\x84gg till en person i listan #" << endl;
			NamnLista = add_person(NamnLista);
			break;
		case 2:
			cout << "# Skriver ut listan #" << endl;
			print_list(NamnLista);
			break;
		case 3:
			cout << "# S\x94ker person #" << endl;
			search_person(NamnLista);
			break;
		case 4:
			cout << "# Tar bort person #" << endl;
			NamnLista = remove_person(NamnLista);
			break;
		case 5:
			cout << "# Sortera listan #" << endl;
			do
			{
				choice = print_meny(meny_sort);
							
				switch (choice)
				{
				case 1:
					cout << "# Sorterad p\x86 namn #" << endl << endl;
					NamnLista = sort_list(NamnLista, name);
					break;
				case 2:
					cout << "# Sorterad p\x86 signatur #" << endl << endl;
					NamnLista = sort_list(NamnLista, sign);
					break;
				case 3:
					cout << "# Sorterad p\x86 l\x84ngd #" << endl << endl;
					NamnLista = sort_list(NamnLista, length);
					break;
				default:
					break;
				}
			} while (choice > 3);
			
			break;
		case 6:
			cout << "# Slumpad lista #" << endl << endl;
			NamnLista = random_list(NamnLista);
			break;
		case 7:
			cout << "# Spara listan #" << endl;
			write_list(NamnLista);
			break;
		case 8:
			cout << "# L\x84sa in listan #" << endl;
			NamnLista = read_list(NamnLista);
			break;
		case 9:
			cout << "# Avslutad #" << endl;
			break;
		default:
			
			break;
		}

	} while (choice != 9);

	return 0;
}

