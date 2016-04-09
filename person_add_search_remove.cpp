//person_add_search_remove.cpp
//Funktionsdefinitioner för att lägga till, söka och ta bort person i listan. Även några extra funktioner finns här.
//Simon
//2015-12-09
//--------------------------------------------------

#include "person_add_search_remove.h"

//--------------------------------------------------


//--------------------------------------------------
//add_person
//--------------------------------------------------
// Uppgift: Lägga till en person på listan
// Indata : Vektor som innehåller namnlistan
// Utdata : Returnerar en vektor med namlistan med ett namn tillagt
//--------------------------------------------------
vector <Person> add_person(vector <Person> v)
{
	Person tmpv;					//Temporär strukt för att spara undan persondata
	bool unique = false, cancel = false;
	int alt = 0;
	
	//Kör loopen så länge personen INTE är unik, förusatt att användaren inte avbryter inmatningen
	while (!unique)
	{
		unique = true;
		cout << "F\x94rnamn: ";			//Läser in personen
		getline(cin, tmpv.firstName);
		cout << "Efternamn: ";
		getline(cin, tmpv.lastName);
		cout << "L\x84ngd: ";
		cin >> tmpv.length;
		cin.get();				//Tar bort ENTER

		tmpv.length = round(tmpv.length);	//Rundar av till två decimaler


		//Kolla om personen är unik
		for (auto idx : v)
		{
			if (to_germaner(idx.firstName) == to_germaner(tmpv.firstName) && to_germaner(idx.lastName) == to_germaner(tmpv.lastName) && idx.length == tmpv.length)
			{
				cout << "Namnet finns redan i listan!" << endl;
				do
				{
					cout << "# Alternativ #" << endl;
					cout << "1. Skriv in personen igen" << endl;
					cout << "2. Avbryt inmatningen" << endl;
					cin >> alt;
					cin.get();	//Rensar bort ENTER
				} while (alt != 1 && alt != 2);

				if (alt == 1)
				{
					unique = false;
				}
				else if (alt == 2)
				{
					cancel = true;
				}

			}
		}
	}


	//Om personen är unik lägger till löpnummer
	if (unique && !cancel)
	{

		tmpv.sign = generate_sign(tmpv.firstName, tmpv.lastName);

		//Lägger till ett löpnummer
		int leap_no_int = 1;
		tmpv.sign = add_leap_no(tmpv.sign, leap_no_int); //Lägger till löpnummer

		string new_sign = tmpv.sign;

		//Kollar om signaturen redan finns annars ändrar löpnummret
		bool found = true;
		while (found)
		{
			auto pred = [new_sign](const Person & item) {	//Plockar ut sign ur struct
				return item.sign == new_sign;
			};

			found = (find_if(v.begin(), v.end(), pred) != v.end());	//Söker med signaturen
			if (found)			//Om signaturen redan finns läggs ett nytt löpnummer
			{
				leap_no_int++;
				tmpv.sign = add_leap_no(tmpv.sign, leap_no_int); //Lägger till ett annat löpnummer
				new_sign = tmpv.sign;
			}
		}

	
		v.push_back(tmpv);			//Lägg in personen i vectorn
	}
	cout << endl;

	return v;
}


//--------------------------------------------------
//generate_sign
//--------------------------------------------------
// Uppgift: Generera en signatur för personen
// Indata : string med förnamn och string med efternamn
// Utdata : string med signaturen
//--------------------------------------------------
string generate_sign(string firstName, string lastName)
{
	string first_germ, last_germ, sign;
	first_germ = to_germaner(firstName);		//Namn till germaner
	last_germ = to_germaner(lastName);

	if (first_germ.size() > 2)			//Namn med minst 3 bokstäver
	{
		first_germ = first_germ.substr(0, 3);
	}
	else if (first_germ.size() == 2)		//Namn med 2 bokstäver lägger till ett x
	{
		first_germ = first_germ.append("x");
	}
	else if (first_germ.size() == 1)		//Namn med 1 bokstäver lägger till två x
	{
		first_germ = first_germ.append("xx");
	}


	if (last_germ.size() > 2)			//Namn med minst 3 bokstäver
	{
		last_germ = last_germ.substr(0, 3);
	}
	else if (last_germ.size() == 2)			//Namn med 2 bokstäver lägger till ett x
	{
		last_germ = last_germ.append("x");
	}
	else if (last_germ.size() == 1)			//Namn med 1 bokstäver lägger till två x
	{
		last_germ = last_germ.append("xx");
	}

	sign = first_germ.append(last_germ);		//Sättersamman signaturen

	return sign;
}


//--------------------------------------------------
//to_germaner
//--------------------------------------------------
// Uppgift: Omvandlar text till germaner
// Indata : string med text
// Utdata : string med samma text som skickades in men som bara innehåller germaner
//--------------------------------------------------
string to_germaner(string name)
{
	for (size_t i = 0; i < name.size(); i++)
	{
		if (name[i] >= 'A' && name[i] <= 'Z')
		{
			name[i] = name[i] + 32;
		}

	}
	return name;

}


//--------------------------------------------------
//add_leap_no
//--------------------------------------------------
// Uppgift: Lägga till ett löpnummet till en sträng
// Indata : string som skall ha ett löpnummer, int med själva löpnummret
// Utdata : string med text och löpnummer
//--------------------------------------------------
string add_leap_no(string s, int leap_no_int)
{
	ostringstream oss;				//Skapa ett oss-objekt
	oss << leap_no_int;				//Konvertera från tal till sträng
	string leap_no = oss.str();			//Kopiera oss-bufferten till leap_no
	
	if (leap_no_int < 10)				//Lägger till "0" om talet är mellan 1 och 9
	{
		if (s.size() < 7)
		{
			s.append("0");
			s.append(leap_no);
		}
		else
		{
			s.replace(6, 7, "0");
			s.replace(7, 8, leap_no);
		}
	}
	else						//Lägger till löpnummret om det är större eller lika med 10
	{
		s.replace(6, 8, leap_no);
	}
	return s;
}


//--------------------------------------------------
//round
//--------------------------------------------------
// Uppgift: Avrundar längden till två decimaler
// Indata : double som skall avrundas
// Utdata : double som är avrundad
//--------------------------------------------------
double round(double value)
{
	return floor(value * 100 + 0.5) / 100;
}


//--------------------------------------------------
//search_person
//--------------------------------------------------
// Uppgift: Sök efter en person på listan
// Indata : Vektor som innehåller namnlistan
// Utdata : Inget
//--------------------------------------------------
void search_person(vector <Person> v)
{
	//Daklarerar variabler
	string search_sign;

	//Skriver in sökt person
	cout << "S\x94k efter en person i listan:" << endl;
	cout << "Signatur: ";
	getline(cin, search_sign);
	
	//Söker
	auto pred = [search_sign](const Person & item) { //Plockar ut sign ur struct
		return item.sign == search_sign;
	};

	auto it = find_if(v.begin(), v.end(), pred);	//Söker med signaturen
	bool found = (it != v.end());

	if (found)
	{
		
		cout << "Signatur    Namn                      L\x84ngd [m]" << endl;
		cout << "---------   --------                  ----------" << endl;
		cout << left << setw(12) << it->sign;
		cout << setw(27) << it->firstName + " " + it->lastName;
		cout << right << setw(5) << fixed << setprecision(2) << it->length << endl;
		cout << endl;
	}
	else
	{
		cout << "Personen finns inte i listan!" << endl << endl;
	}

}


//--------------------------------------------------
//remove_person
//--------------------------------------------------
// Uppgift: Tar bort önskad person ur listan
// Indata : Vektor som innehåller namnlistan
// Utdata : Vektor som inte innehåller den borttagna personen
//--------------------------------------------------
vector <Person> remove_person(vector <Person> v)
{
	//Daklarerar variabler
	string remove_sign;

	//Skriver in sökt person
	cout << "Skriv in person du vill ta bort fr\x86n listan:" << endl;
	cout << "Signatur: ";
	getline(cin, remove_sign);

	//Söker
	auto pred = [remove_sign](const Person & item) { //Plockar ut sign ur struct
		return item.sign == remove_sign;
	};
	
	auto it = find_if(v.begin(), v.end(), pred); //Söker med signaturen och raderar om personen finns i listan
	bool found = (it != v.end());
	

	
	if (found)
	{
		v.erase(it);
		cout << "Personen \x84r borttagen fr\x86n listan!" << endl << endl;
	}
	else
	{
		cout << "Finns inte i listan \x94verhuvudtaget!" << endl << endl;
	}

	return v;
}

