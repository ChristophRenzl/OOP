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


//vector <vector<shared_ptr<Materials>>> Einlagern(unsigned ID, unsigned ArtikelNr, string Bezeichnung, unsigned FachNr)
//{
//	vector <vector<shared_ptr<Materials>>> FIFO;
//
//	if(FIFO)
//	FIFO[FachNr][i]->Artikelnummer = ArtikelNr;
//	FIFO[FachNr][i]->ID = ID;
//	FIFO[FachNr][i]->Bezeichnung = Bezeichnung;
//
//	return FIFO;
//}


void Einlagern(vector <vector<shared_ptr<Materials>>> &LIFO,unsigned id, unsigned artikelnr, string bezeichnung, unsigned fachnr)
{
	vector<shared_ptr<Materials>> fach;
	auto tmp = make_shared<Materials>();
	tmp->Artikelnummer = artikelnr;
	tmp->Bezeichnung = bezeichnung;
	tmp->ID = id;

	fach.push_back(tmp);

	LIFO.push_back(fach);
}

vector <vector<shared_ptr<Materials>>> Entnehmen(unsigned FachNr, vector <vector<shared_ptr<Materials>>> &LIFO)
{
	LIFO[FachNr].pop_back();
	return LIFO;
}

void printLagerbestand(vector <vector<shared_ptr<Materials>>> &LIFO)
{
	int help = 0;

	for (int i = 0; i < LIFO.size(); i++)
	{	
		
		//cout << "Fach Nr:" << i << endl;
		for (int j = 0; j < LIFO[i].size(); j++)
		{
			cout << "ID: " << LIFO[i][j]->ID << "   ArtNr:" << LIFO[i][j]->Artikelnummer << "   Bezeichnung: " << LIFO[i][j]->Bezeichnung << endl<<endl;
			help++;
		}
	}
	cout << "Es befinden sich " << help << "Artikel im Lager" << endl<<endl;
}

int main()
{
	vector <vector<shared_ptr<Materials>>> LIFO; //[Fachn Nr][Material]
	//Ich verwende für den LIFO einen 2dim-vector, da ich beliebig viele Materials & Fächer erstellen kann (dynamischer Speicher)


	//Einlagern(ID,ArtikelNr,Bezeichnung,FachNr)

	Einlagern(LIFO,001, 111, "Fach0-1", 0);
	Einlagern(LIFO, 111, 222, "Fach1-1", 1);
	Einlagern(LIFO, 211, 333, "Fach2-1", 2);
	Einlagern(LIFO, 311, 444, "Fach3-1", 3);
	Einlagern(LIFO, 411, 555, "Fach4-1", 4);
	Einlagern(LIFO, 021, 666, "Fach0-2", 0);
	Einlagern(LIFO, 121, 777, "Fach1-2", 1);
	Einlagern(LIFO, 221, 888, "Fach2-2", 2);
	Einlagern(LIFO, 321, 999, "Fach3-2", 3);
	Einlagern(LIFO, 421, 000, "Fach4-2", 4);

	printLagerbestand(LIFO);

	//Entnehmen(ArtikelNr)
	LIFO = Entnehmen(1, LIFO);

	printLagerbestand(LIFO);

	return 0;
}

