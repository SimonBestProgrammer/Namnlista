//person_add_search_remove.cpp
//Funktionsdefinitioner f�r att l�gga till, s�ka och ta bort person i listan. �ven n�gra extra funktioner finns h�r.
//Simon
//2015-12-09
//--------------------------------------------------

#include "person_add_search_remove.h"

//--------------------------------------------------


//--------------------------------------------------
//add_person
//--------------------------------------------------
// Uppgift: L�gga till en person p� listan
// Indata : Vektor som inneh�ller namnlistan
// Utdata : Returnerar en vektor med namlistan med ett namn tillagt
//--------------------------------------------------
vector <Person> add_person(vector <Person> v)
{
	Person tmpv;									//Tempor�r strukt f�r att spara undan persondata
	bool unique = false, cancel = false;
	int alt = 0;
	
	//K�r loopen s� l�nge personen INTE �r unik, f�rusatt att anv�ndaren inte avbryter inmatningen
	while (!unique)
	{
		unique = true;
		cout << "F\x94rnamn: ";						//L�ser in personen
		getline(cin, tmpv.firstName);
		cout << "Efternamn: ";
		getline(cin, tmpv.lastName);
		cout << "L\x84ngd: ";
		cin >> tmpv.length;
		cin.get();									//Tar bort ENTER

		tmpv.length = round(tmpv.length);			//Rundar av till tv� decimaler


		//Kolla om personen �r unik
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
					cin.get();							//Rensar bort ENTER
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


	//Om personen �r unik l�gger till l�pnummer
	if (unique && !cancel)
	{

		tmpv.sign = generate_sign(tmpv.firstName, tmpv.lastName);

		//L�gger till ett l�pnummer
		int leap_no_int = 1;
		tmpv.sign = add_leap_no(tmpv.sign, leap_no_int); //L�gger till l�pnummer

		string new_sign = tmpv.sign;

		//Kollar om signaturen redan finns annars �ndrar l�pnummret
		bool found = true;
		while (found)
		{
			auto pred = [new_sign](const Person & item) {	//Plockar ut sign ur struct
				return item.sign == new_sign;
			};

			found = (find_if(v.begin(), v.end(), pred) != v.end());	//S�ker med signaturen
			if (found)									//Om signaturen redan finns l�ggs ett nytt l�pnummer
			{
				leap_no_int++;
				tmpv.sign = add_leap_no(tmpv.sign, leap_no_int); //L�gger till ett annat l�pnummer
				new_sign = tmpv.sign;
			}
		}

	
		v.push_back(tmpv);								//L�gg in personen i vectorn
	}
	cout << endl;

	return v;
}


//--------------------------------------------------
//generate_sign
//--------------------------------------------------
// Uppgift: Generera en signatur f�r personen
// Indata : string med f�rnamn och string med efternamn
// Utdata : string med signaturen
//--------------------------------------------------
string generate_sign(string firstName, string lastName)
{
	string first_germ, last_germ, sign;
	first_germ = to_germaner(firstName);			//Namn till germaner
	last_germ = to_germaner(lastName);

	if (first_germ.size() > 2)						//Namn med minst 3 bokst�ver
	{
		first_germ = first_germ.substr(0, 3);
	}
	else if (first_germ.size() == 2)				//Namn med 2 bokst�ver l�gger till ett x
	{
		first_germ = first_germ.append("x");
	}
	else if (first_germ.size() == 1)				//Namn med 1 bokst�ver l�gger till tv� x
	{
		first_germ = first_germ.append("xx");
	}


	if (last_germ.size() > 2)						//Namn med minst 3 bokst�ver
	{
		last_germ = last_germ.substr(0, 3);
	}
	else if (last_germ.size() == 2)					//Namn med 2 bokst�ver l�gger till ett x
	{
		last_germ = last_germ.append("x");
	}
	else if (last_germ.size() == 1)					//Namn med 1 bokst�ver l�gger till tv� x
	{
		last_germ = last_germ.append("xx");
	}

	sign = first_germ.append(last_germ);			//S�ttersamman signaturen

	return sign;
}


//--------------------------------------------------
//to_germaner
//--------------------------------------------------
// Uppgift: Omvandlar text till germaner
// Indata : string med text
// Utdata : string med samma text som skickades in men som bara inneh�ller germaner
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
// Uppgift: L�gga till ett l�pnummet till en str�ng
// Indata : string som skall ha ett l�pnummer, int med sj�lva l�pnummret
// Utdata : string med text och l�pnummer
//--------------------------------------------------
string add_leap_no(string s, int leap_no_int)
{
	ostringstream oss;								//Skapa ett oss-objekt
	oss << leap_no_int;								//Konvertera fr�n tal till str�ng
	string leap_no = oss.str();						//Kopiera oss-bufferten till leap_no
	
	if (leap_no_int < 10)							//L�gger till "0" om talet �r mellan 1 och 9
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
	else											//L�gger till l�pnummret om det �r st�rre eller lika med 10
	{
		s.replace(6, 8, leap_no);
	}
	return s;
}


//--------------------------------------------------
//round
//--------------------------------------------------
// Uppgift: Avrundar l�ngden till tv� decimaler
// Indata : double som skall avrundas
// Utdata : double som �r avrundad
//--------------------------------------------------
double round(double value)
{
	return floor(value * 100 + 0.5) / 100;
}


//--------------------------------------------------
//search_person
//--------------------------------------------------
// Uppgift: S�k efter en person p� listan
// Indata : Vektor som inneh�ller namnlistan
// Utdata : Inget
//--------------------------------------------------
void search_person(vector <Person> v)
{
	//Daklarerar variabler
	string search_sign;

	//Skriver in s�kt person
	cout << "S\x94k efter en person i listan:" << endl;
	cout << "Signatur: ";
	getline(cin, search_sign);
	
	//S�ker
	auto pred = [search_sign](const Person & item) { //Plockar ut sign ur struct
		return item.sign == search_sign;
	};

	auto it = find_if(v.begin(), v.end(), pred);	//S�ker med signaturen
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
// Uppgift: Tar bort �nskad person ur listan
// Indata : Vektor som inneh�ller namnlistan
// Utdata : Vektor som inte inneh�ller den borttagna personen
//--------------------------------------------------
vector <Person> remove_person(vector <Person> v)
{
	//Daklarerar variabler
	string remove_sign;

	//Skriver in s�kt person
	cout << "Skriv in person du vill ta bort fr\x86n listan:" << endl;
	cout << "Signatur: ";
	getline(cin, remove_sign);

	//S�ker
	auto pred = [remove_sign](const Person & item) { //Plockar ut sign ur struct
		return item.sign == remove_sign;
	};
	
	auto it = find_if(v.begin(), v.end(), pred); //S�ker med signaturen och raderar om personen finns i listan
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







