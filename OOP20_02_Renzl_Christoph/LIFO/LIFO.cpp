#include <iostream>
#include <string>
#include <array>
#include <memory>
#include <vector>

using namespace std;

//LIFO für Lagerverwaltung
//mehrere Fächer, welche beliebeig viele Materialien beinhlten kann

struct Materials {
	unsigned ID;
	unsigned Artikelnummer;
	string Bezeichnung;
};

vector<shared_ptr<Materials>> Einlagern(unsigned ID, unsigned ArtikelNr, string Bezeichnung, unsigned FachNr)
{
	vector<shared_ptr<Materials>> Fach;
	auto tmp = make_shared<Materials>();
	tmp->Artikelnummer = ArtikelNr;
	tmp->Bezeichnung = Bezeichnung;
	tmp->ID = ID;

	Fach.push_back(tmp);

	return Fach;
}

vector <vector<shared_ptr<Materials>>> Entnehmen(unsigned FachNr, vector <vector<shared_ptr<Materials>>> &LIFO)
{
	LIFO[FachNr].pop_back();
	return LIFO;
}

void printLagerbestand(vector <vector<shared_ptr<Materials>>> &LIFO)
{
	for (int i = 0; i < 5; i++)
	{

			Lifo[i]
	}
}

int main()
{
	vector <vector<shared_ptr<Materials>>> LIFO; //[Fachn Nr][Material]
	//Ich verwende für den LIFO einen 2dim-vector, da ich beliebig viele Materials & Fächer erstellen kann (dynamischer Speicher)
	
	auto test = make_shared<Materials>();


	//Einlagern(ID,ArtikelNr,Bezeichnung,FachNr)

	LIFO[0] = Einlagern(001, 111, "Fach0-1", 0);
	LIFO[1] = Einlagern(111, 222, "Fach1-1", 1);
	LIFO[2] = Einlagern(211, 333, "Fach2-1", 2);
	LIFO[3] = Einlagern(311, 444, "Fach3-1", 3);
	LIFO[4] = Einlagern(411, 555, "Fach4-1", 4);
	LIFO[0] = Einlagern(021, 666, "Fach0-2", 0);
	LIFO[1] = Einlagern(121, 777, "Fach1-2", 1);
	LIFO[2] = Einlagern(221, 888, "Fach2-2", 2);
	LIFO[3] = Einlagern(321, 999, "Fach3-2", 3);
	LIFO[4] = Einlagern(421, 000, "Fach4-2", 4);

	//Entnehmen(ArtikelNr)
	LIFO = Entnehmen(1, LIFO);

	printLagerbestand(LIFO);

	return 0;
}