//file_read_write.cpp
//Funktionsdefinitioner för att läsa och skriva till fil.
//Simon
//2015-12-09
//--------------------------------------------------

#include "file_read_write.h"

//--------------------------------------------------


//--------------------------------------------------
//write_list
//--------------------------------------------------
// Uppgift: Skriva listan på fil
// Indata : Vektor som innehåller namnlistan
// Utdata : inget
//--------------------------------------------------
void write_list(vector <Person> v)
{
	string fileName, outStr;
	int key_en = 0;

	cout << "Skriv in filnamn: ";
	getline(cin, fileName);
	ofstream outFile(fileName);						//Skapar en fil och sätter ett namn på den

	cout << "Skall filen krypteras? (y/n): ";
	char a = cin.get();
	cin.get();										//Läser bort ENTER
	if (a == 'Y' || a == 'y')
	{
		cout << "Ange krypteringsnyckel: ";
		cin >> key_en;
	}


	for (auto idx : v)								//Skriver data till fil
	{
		ostringstream oss;							//Skapa ett oss-objekt
		oss << idx.firstName << DELIM << idx.lastName << DELIM << idx.sign << DELIM << idx.length;
		outStr = oss.str();
		outStr = encrypt(outStr, key_en);

		outFile << outStr << endl;

	}
	outFile.close();								//Stänger filen
}


//--------------------------------------------------
//read_list
//--------------------------------------------------
// Uppgift: Läsa lista från fil
// Indata : Vektor som innehåller namnlistan
// Utdata : Vector som innehåller den inlästa vektorn
//--------------------------------------------------
vector <Person> read_list(vector <Person> v)
{
	string fileName, rad_str;
	Person temp_person;
	int key_de = 0;

		
	cout << "Skriv in filnamn: ";
	getline(cin, fileName);
	ifstream inFile(fileName);						//Öppnar en fil

	v.clear();										//Rensar vektorn med namnlistan

	//Kryptering
	cout << "\x8Er filen som skall l\x84sas in krypterad? (y/n) ";
	char b = cin.get();
	cin.get();										//Läser bort ENTER
	if (b == 'Y' || b == 'y')
	{
		cout << "Ange krypteringsnyckel: ";
		cin >> key_de;
	}

	//Läser in filen och lägger in datan på rätt plats i strukten Person och sen in i vektorn
	while (getline(inFile, rad_str)) //Läs fram till DELIM
	{
		rad_str = decrypt(rad_str, key_de);
		
		istringstream iss(rad_str);
		getline(iss, temp_person.firstName, DELIM);
		getline(iss, temp_person.lastName, DELIM);
		getline(iss, temp_person.sign, DELIM);
		iss >> temp_person.length;
		
		v.push_back(temp_person);					//Lägg in personen i vectorn
	}

	inFile.close();									//Stänger filen

	return v;
}


//--------------------------------------------------
//encrypt
//--------------------------------------------------
// Uppgift: Kryptera en sträng
// Indata : string med text, int med krypteringsnyckel
// Utdata : string med krypterad text
//--------------------------------------------------
string encrypt(string str, int key)
{

	for (string::size_type i = 0; str.size() >= i; i++)
	{
		str[i] = str[i] + key;
	}
	return str;
}


//--------------------------------------------------
//decrypt
//--------------------------------------------------
// Uppgift: Dekryptera en sträng
// Indata : string med text, int med krypteringsnyckel
// Utdata : string med dekrypterad text
//--------------------------------------------------
string decrypt(string str, int key)
{
	for (string::size_type i = 0; str.size() >= i; i++)
	{
		str[i] = str[i] - key;
	}
	return str;
}
