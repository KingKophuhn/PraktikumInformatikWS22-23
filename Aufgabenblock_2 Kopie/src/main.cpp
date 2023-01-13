/*
 * main.cpp
 */
#include <iostream>
#include <vector>
#include <memory> // für make_unique usw.
#include <iomanip> //Input-Output-Manipulatoren der Standard C++ Bibliothek
#include <random>

#include "Weg.h"
#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrraeder.h"
#include "SimuClient.h"
#include "vertagt_aktion - Vorlage.h"
#include "Kreuzung.h"

using namespace std;

double dGlobaleZeit {0}; //globale uhr!


int vAufgabe_1(){

	Fahrzeug* fahrzeug_dyn_1 = new Fahrzeug("otto"),* fahrzeug_dyn_2 = new Fahrzeug("VW", 120),* fahrzeug_dyn_3 = new Fahrzeug("Opel",-9); //dynamisch erzeugt

	Fahrzeug fahrzeug_4 {"toolBox"}, fahrzeug_5 {"Ford"}; // statisch (Deklaration)

	unique_ptr<Fahrzeug> fahrzeug_ptr_6 = make_unique<Fahrzeug>("Audi"), fahrzeug_ptr_7 = make_unique<Fahrzeug>("Hundai");

	shared_ptr<Fahrzeug> fahrzeug_ptr_8 = make_shared<Fahrzeug>("Ferari"), fahrzeug_ptr_9 = make_shared<Fahrzeug>("Porsche");
	shared_ptr<Fahrzeug> fahrzeug_ptr_9_shared = fahrzeug_ptr_9;

	//shared_ptr<Fahrzeug> fahrzeug_ptr_6_shared = fahrzeug_ptr_6;			error: conversion from ‘std::unique_ptr<Fahrzeug>’ to non-scalar type ‘std::shared_ptr<Fahrzeug>’ requested
	// klappt natürlich nicht!

	//cout << "fahrzeug_ptr_9.use_count() = " << fahrzeug_ptr_9.use_count() << endl;

	vector<unique_ptr<Fahrzeug>> fahrzeug_vector_unique;	// Der besitzwechsel wird durch move() angegeben. In diesen vector kann man nur unique ptr fahrzeuge speichen!
	fahrzeug_vector_unique.push_back(move(fahrzeug_ptr_6));
	fahrzeug_vector_unique.push_back(move(fahrzeug_ptr_7));


	vector<shared_ptr<Fahrzeug>> fahrzeug_vector_shared;	// In diesem vector kann man nur shared ptr fahrzeuge speichen!
	fahrzeug_vector_shared.push_back(move(fahrzeug_ptr_8));	//durch das move ist der usecount von fahrzeug_ptr_8=0. D.h. der besitzer wurde gewechselt!
	fahrzeug_vector_shared.push_back(fahrzeug_ptr_9); // bei dem fahrzeug 9 wurde eine weitere referenz erzeugt. use count = 3


	//cout << "fahrzeug_ptr_8.use_count() = " << fahrzeug_ptr_8.use_count() << endl;
	//cout << "fahrzeug_ptr_9.use_count() = " << fahrzeug_ptr_9.use_count() << endl;

	fahrzeug_4.vAusgeben();
	fahrzeug_dyn_1->vAusgeben();
	fahrzeug_ptr_6->vAusgeben();

	fahrzeug_vector_unique.clear(); //fahrzeug_ptr_6 und fahrzeug_ptr_7 werden gelöscht.
	fahrzeug_vector_shared.clear(); // nur fahrzeug_ptr_8 wird gelöscht!! da fahrzeug_ptr_9 noch andere referenzen hat
	delete fahrzeug_dyn_1;	// del Fahrzeug obj.
	delete fahrzeug_dyn_2;	//*
	delete fahrzeug_dyn_3;	//*
	return 0;
}

int vAufgabe_1a(){
	string name;
	double maxGeschw;
	int erzeugen;
	vector<unique_ptr<Fahrzeug>> Fahrzeuge;
	double dZeittakt;

	cout << "Fahrzeuge erzeugen?(1)\nAbbrechen!(2)";
	cin >> erzeugen;
	if (erzeugen==2) return 0; //programm stoppen!

	while(erzeugen==1){
		cout << "Fahrzeugname: "; // abfragen von name und maxGeschw
		cin >> name;
		cout << "Maximalgeschwindigkeit des Fahrzeugs: ";
		cin >> maxGeschw;
		unique_ptr<Fahrzeug> tempFahrzeug = make_unique<Fahrzeug>(name,maxGeschw); //fahrzeug erzeugen
		Fahrzeuge.push_back(move(tempFahrzeug)); //besitzübergabe...
		cout << "Fahrzeug " + name + " wurde erstellt!\nEin weiteres Fahrzeug hinzufügen? ja(1) nein(2)";
		cin >> erzeugen;
	}
	int sim,simzyclen;

	cout << "Fahrzeuge simulieren?(1)\nAbbrechen(2)";
	cin >> sim;
	if(sim==2) return 0;
	while (sim==1){
	cout << "Geben Sie eine Zahl ein wie oft simuliert werden soll: ";
	cin >> simzyclen;
	cout << "Geben Sie einen Zeittakt an: ";
	cin >> dZeittakt;

	for (int z= 0; z < simzyclen; z++){
		dGlobaleZeit += dZeittakt;
		cout << "\nGlobalzeit = "+to_string(dGlobaleZeit)<< endl<< endl;
		Fahrzeug::vKopf();
		for (int unsigned i = 0;i<Fahrzeuge.size();i++){ //unsined da .size unsigned ist.
			cout << setfill(' ');
			Fahrzeuge[i]->vSimulieren();
			Fahrzeuge[i]->vAusgeben();
			cout << "\t\t·\n";
		}
	}
	cout << "Nochmal simulieren? Ja(1) Nein(2): ";
	cin >> sim;
	if(sim !=1) return 0;
	}
	return 0;
}

int vAufgabe_2(){
		string name;
		double maxGeschw;
		double verbrauch;
		double tankVolumen;
		int erzeugen;
		vector<unique_ptr<Fahrzeug>> Fahrzeuge;
		double dZeittakt;
		int choice;

		cout << "Fahrzeuge erzeugen?(1)\nAbbrechen!(2)";
		cin >> erzeugen;
		if (erzeugen==2) return 0; //programm stoppen!

		while(erzeugen==1){
			cout << "Was wollen Sie erzeugen? PKW(1)\tFahrrad(2)";
			cin >> choice;
			if(choice==1){
			cout << "Fahrzeugname: "; // abfragen von name und maxGeschw
			cin >> name;
			cout << "Maximalgeschwindigkeit des Fahrzeugs: ";
			cin >> maxGeschw;
			cout << "Verbrauch des PKWs: ";
			cin >> verbrauch;
			cout << "Tankvolumen des PKWs: ";
			cin >> tankVolumen;
			unique_ptr<Fahrzeug> tempFahrzeug = make_unique<PKW>(name,maxGeschw,verbrauch,tankVolumen); //fahrzeug erzeugen
			Fahrzeuge.push_back(move(tempFahrzeug)); //besitzübergabe...
			}
			else if(choice==2){
				cout << "Fahrzeugname: "; // abfragen von name und maxGeschw
				cin >> name;
				cout << "Maximalgeschwindigkeit des Fahrzeugs: ";
				cin >> maxGeschw;
				unique_ptr<Fahrzeug> tempFahrzeug = make_unique<Fahrraeder>(name,maxGeschw); //fahrzeug erzeugen
				Fahrzeuge.push_back(move(tempFahrzeug)); //besitzübergabe...
			} else {
				continue;
			}
			cout << "Fahrzeug " + name + " wurde erstellt!\nEin weiteres Fahrzeug hinzufügen? ja(1) nein(2)";
			cin >> erzeugen;
		}
		int sim,simzyclen;

		cout << "Fahrzeuge simulieren?(1)\nAbbrechen(2)";
		cin >> sim;
		if(sim==2) return 0;
		while (sim==1){
		cout << "Geben Sie eine Zahl ein wie oft simuliert werden soll: ";
		cin >> simzyclen;
		cout << "Geben Sie einen Zeittakt an: ";
		cin >> dZeittakt;

		for (int z= 0; z < simzyclen; z++){
			dGlobaleZeit += dZeittakt;
			cout << "\nGlobalzeit = "+to_string(dGlobaleZeit)<< endl<< endl;
			Fahrzeug::vKopf();
			//int indexTanken[Fahrzeuge.size()+1]; versuch...
			for (int unsigned i = 0;i<Fahrzeuge.size();i++){ //unsined da .size unsigned ist.
				cout << setfill(' ');
				if(dGlobaleZeit==3.) Fahrzeuge[i]->dTanken(); //double zuahl mit einem int (Funktion f ̈ur den Absolutbetrag std::fabs() <cmath>) falls nötig.
				Fahrzeuge[i]->vSimulieren();
				Fahrzeuge[i]->vAusgeben();
				cout << "\t\t·\n";
			}
		}
		cout << "Nochmal simulieren? Ja(1) Nein(2): ";
		cin >> sim;
		if(sim !=1) return 0;
		}
		return 0;
}

//double dEpsilon = 0.001;
//void vAufgabe_AB1() {
//
//    int l = 0; // Laufindex für gezielte AUsgabe
//    vector<int> ausgabe{13};
//    double dTakt = 0.4;
//
//    std::vector<unique_ptr<Fahrzeug>> vecFahrzeuge;
//    vecFahrzeuge.push_back(make_unique <PKW>("Audi", 231, 11.4));
//    vecFahrzeuge.push_back(make_unique <Fahrraeder>("BMX", 19.8));
//    for (dGlobaleZeit = 0; dGlobaleZeit < 10; dGlobaleZeit += dTakt)
//    {
//        auto itL = find(ausgabe.begin(), ausgabe.end(), l);
//        if (itL != ausgabe.end()) {
//            cout << std::endl << l <<  " Globalezeit = " << dGlobaleZeit << std::endl;
//            Fahrzeug::vKopf();
//        }
//
//        for (int i = 0; i < (int) vecFahrzeuge.size(); i++)
//        {
//            vecFahrzeuge[i]->vSimulieren();
//            if (fabs(dGlobaleZeit - 3.0) < dTakt/2)
//            {
//                vecFahrzeuge[i]->dTanken();
//            }
//            if (itL != ausgabe.end()) {
//                cout << *vecFahrzeuge[i] << endl;
//            }
//        }
//        l++;
//    }
//    char c;
//    std::cin >> c;
//}

int vAufgabe_3(){
	cout << "Aufgabenblock 1, Aufgabe 3: " << endl;

		Fahrzeug* ofPKW=new PKW("Auto", 333, 12, 60,false,false);
		Fahrzeug* ofFahrrad=new Fahrraeder("Fahrrad", 50);

		dGlobaleZeit = 0;
		for(int i = 0 ; i <7; i++){
		dGlobaleZeit++;
		ofPKW->vSimulieren();
		ofFahrrad->vSimulieren();

		Fahrzeug::vKopf();
		cout << setfill(' ');
		cout << *ofPKW << endl;
		cout << *ofFahrrad << endl;
		cout << endl;
		}

		ofPKW < ofFahrrad? cout << "Das Fahrrad ist weiter" << endl:cout << "Das Auto ist weiter" << endl;

		Fahrraeder fahrrad("Die Omi", 100);

			Fahrzeug::vKopf();
			cout << setfill(' ');

			Fahrzeug newbike;
			newbike = fahrrad;

			cout << fahrrad << endl;
			cout << newbike << endl;
			cout << endl;
			return 0;
}

int vAufgabe_4(){
	Weg Weg1("WEG",100);
	Weg::vKopf();
	cout<< Weg1<<endl;
	return 0;
}

int vAufgabe_5(){

	Weg weg1("WEG",300);

	unique_ptr<Fahrzeug> f1 = make_unique<PKW>("Audi",300,7,60);
	unique_ptr<Fahrzeug> f2 = make_unique<PKW>("BMW",200,6,50);
	unique_ptr<Fahrzeug> f3 = make_unique<PKW>("VW",325,8,60);

	weg1.vAnnahme(move(f1));
	weg1.vAnnahme(move(f2));
	weg1.vAnnahme(move(f3));

	Weg::vKopf();
	cout<< weg1 << endl;

	dGlobaleZeit=1;
	weg1.vSimulieren();
	return 0;
}

int vAufgabe_6(){

	Weg innerOrts("InnerOrts",500000,Tempolimit::Innerorts);
	Weg ausserOrts("AußerOrts",500000,Tempolimit::Landstrasse);

	unique_ptr<Fahrzeug> f1 = make_unique<PKW>("Audi",300,7,60);
	unique_ptr<Fahrzeug> f2 = make_unique<PKW>("BMW",200,6,50);
	unique_ptr<Fahrzeug> f3 = make_unique<PKW>("VW",325,8,60);
	unique_ptr<Fahrzeug> f4 = make_unique<PKW>("VW",25,2,20);


	innerOrts.vAnnahme(move(f1));
	innerOrts.vAnnahme(move(f2),3.0);
	ausserOrts.vAnnahme(move(f3));
	ausserOrts.vAnnahme(move(f4),3.0);

	bInitialisiereGrafik(800, 500);
		int koordinaten[4] = { 700, 250, 100, 250 };
		string s2 = ausserOrts.getName();
		const char* sWegname2 = s2.c_str();
		bZeichneStrasse("innerOrts", "ausserOrts", 500000, 2, koordinaten);

	Weg::vKopf();
	cout<< innerOrts<< endl<<ausserOrts << endl;


	for(dGlobaleZeit=0 ; dGlobaleZeit<6 ; dGlobaleZeit += 0.25){
		cout << "GlobaleZeit:" << dGlobaleZeit << endl;
		innerOrts.vSimulieren();
		ausserOrts.vSimulieren();

	}


	return 0;
}

int vAufgabe_6_2(){
		unique_ptr<Weg> weg1 = make_unique<Weg>("Weg1", 500, Tempolimit::Autobahn);
		unique_ptr<Weg> weg2 = make_unique<Weg>("Weg2", 500, Tempolimit::Innerorts);

		unique_ptr<Fahrzeug> f1 = make_unique<PKW>("F1", 50, 3.6, 70);
		unique_ptr<Fahrzeug> f2 = make_unique<PKW>("F2", 290, 5, 60);
		unique_ptr<Fahrzeug> f3 = make_unique<PKW>("F3", 250, 7, 10);
		unique_ptr<Fahrzeug> f4 = make_unique<Fahrraeder>("Fahrrad1", 30);
		unique_ptr<Fahrzeug> f5 = make_unique<Fahrraeder>("Fahrrad2", 20);

		weg1->vAnnahme(move(f1),0.5);
		weg1->vAnnahme(move(f2), 3.0);
		weg1->vAnnahme(move(f3));
		weg1->vAnnahme(move(f4));
		weg1->vAnnahme(move(f5),2);



		unique_ptr<Fahrzeug> b1 = make_unique<PKW>("BMW1", 50, 3.6, 70);
		unique_ptr<Fahrzeug> b2 = make_unique<PKW>("BMW2", 300, 5, 60);
		unique_ptr<Fahrzeug> b3 = make_unique<Fahrraeder>("Fahrrad3", 20);

		weg2->vAnnahme(move(b1));
		weg2->vAnnahme(move(b2),0.7);
		weg2->vAnnahme(move(b3));

		Weg::vKopf();
		cout << *weg1 << endl<<*weg2<< endl;

		bInitialisiereGrafik(800, 500);
		int koordinaten[4] = { 700, 250, 100, 250 };
		string s2 = weg2->getName();
		const char* sWegname2 = s2.c_str();
		bZeichneStrasse(weg1->getName(), sWegname2, weg1->getLaenge(), 2, koordinaten);

		for (dGlobaleZeit =0; dGlobaleZeit < 5; dGlobaleZeit += 0.25){

			vSetzeZeit(dGlobaleZeit);

			cout << "GlobaleZeit:" << dGlobaleZeit << endl;
			weg1->vSimulieren();
			weg2->vSimulieren();
			cout << endl;

			vSleep(800);
		}
		vBeendeGrafik();
		return 0;
}

int vAufgabe_6a(){

	vertagt::VListe<int> vList;

	static mt19937 device(0);
	uniform_int_distribution<int> dist(1, 10);
	//int zuf = dist(device); // zufallszahl

	typedef vertagt::VListe<int>::iterator vLit;

	//liste mit zahlen füllen
	for(int i=0; i<10; i++){
		vList.push_back(dist(device));
	}
	vList.vAktualisieren(); //aaaaaaaaaaaaaaaahhhhh!!
	//cout << "test3"<<endl;
	//vLit it = vList.begin();
	//it++;
	//cout << *it <<endl;

//	for(vLit iter = vList.begin(); iter != vList.end(); iter++){
//		cout<< (*iter) <<endl;
//	}

	for(auto i : vList){	//schönere variante
		cout<<i<<endl;
	}
	cout<<endl;

	for(vLit iter = vList.begin(); iter != vList.end(); iter++){
		if(*iter>5) vList.erase(iter);
		continue;
	}

	for(auto i : vList) cout<<i<<endl;
	cout<<endl;

	vList.vAktualisieren();

	for(auto i : vList) cout<<i<<endl;
	cout<<endl;

	vList.push_front(4);
	vList.push_back(6);

	vList.vAktualisieren();

	for(auto i : vList) cout<<i<<endl;
	cout<<endl;

	return 0;
}

int vAufgabe_7(){
	bInitialisiereGrafik(1000, 1000);

	vSleep(5000);

	shared_ptr<Kreuzung> kr1 = make_shared<Kreuzung>("kr1");
	shared_ptr<Kreuzung> kr2 = make_shared<Kreuzung>("kr2",100);
	shared_ptr<Kreuzung> kr3 = make_shared<Kreuzung>("kr3");
	shared_ptr<Kreuzung> kr4 = make_shared<Kreuzung>("kr4");

	kr1->vVerbinde("W12", "W21", 40, kr1, kr2, Tempolimit::Innerorts, true); //mit "schlecht" und "gut" ist das Überholverbot gemient??
	kr2->vVerbinde("W23a", "W32a", 115, kr2, kr3, Tempolimit::Autobahn, false);
	kr2->vVerbinde("W23b", "W32b", 40, kr2, kr3, Tempolimit::Innerorts, true);
	kr2->vVerbinde("W24", "W42", 55, kr2, kr4, Tempolimit::Innerorts, true);
	kr3->vVerbinde("W34", "W43", 85, kr3, kr4, Tempolimit::Autobahn, false);
	kr4->vVerbinde("W44a", "W44b", 130, kr4, kr4, Tempolimit::Landstrasse, false);

	unique_ptr<Fahrzeug> f1 = make_unique<PKW>("F1", 45, 4, 60,false,false);
	unique_ptr<Fahrzeug> f2 = make_unique<PKW>("F2", 100, 5, 60,false,false);
	unique_ptr<Fahrzeug> f3 = make_unique<PKW>("F3", 200, 7, 60,false,false);
	unique_ptr<Fahrzeug> Fahrad = make_unique<Fahrraeder>("Fahrad1",30,true,true);

	Fahrzeug& sf1 = *f1;
	Fahrzeug& sf2 = *f2;
	Fahrzeug& sf3 = *f3;
	Fahrzeug& sFahrad = *Fahrad;



	int strasse1[] = { 680, 40, 680, 300 };
	int strasse2[] = { 680, 300, 850, 300, 970, 390, 970, 500, 850, 570, 680, 570 };
	int strasse3[] = { 680, 300, 680, 570 };
	int strasse4[] = { 680, 300, 320, 300 };
	int strasse5[] = { 680, 570, 500, 570, 350, 510, 320, 420, 320, 300 };
	int strasse6[] = { 320, 300, 170, 300, 70, 250, 80, 90, 200, 60, 320, 150, 320, 300 };

	bZeichneStrasse("W12", "W21", 40, 2, strasse1);
	bZeichneStrasse("W23a", "W32a", 115, 6, strasse2);
	bZeichneStrasse("W23b", "W32b", 40, 2, strasse3);
	bZeichneStrasse("W24", "W42", 55, 2, strasse4);
	bZeichneStrasse("W34", "W43", 85, 5, strasse5);
	bZeichneStrasse("W44a", "W44b", 130, 7, strasse6);

	bZeichneKreuzung(680, 40);
	bZeichneKreuzung(680, 300);
	bZeichneKreuzung(680, 570);
	bZeichneKreuzung(320, 300);

	kr1->vAnnahme(move(f1),3);
	kr1->vAnnahme(move(f2));
	kr1->vAnnahme(move(f3));
	kr1->vAnnahme(move(Fahrad));

	Weg::vKopf();
	kr1->coutWege();
	kr2->coutWege();
	kr3->coutWege();
	kr4->coutWege();

	for (dGlobaleZeit =0; dGlobaleZeit < 5; dGlobaleZeit += 0.1){
		vSetzeZeit(dGlobaleZeit);
		cout << "GlobaleZeit:" << static_cast<double>(dGlobaleZeit) << endl<<endl;

		kr1->vSimulieren();
		kr2->vSimulieren();
		kr3->vSimulieren();
		kr4->vSimulieren();
		//f1->vSimulieren();

		Fahrzeug::vKopf();
		cout<<sf1<<endl<<sf2<<endl<<sf3<<endl<<sFahrad<<endl<<endl;

		vSleep(800);
	}
	vBeendeGrafik();
	return 0;
}

int main() { // Globale Zeit festlegen. Start bei 00:00 (0)
	//vAufgabe_1();
	//vAufgabe_1a();
	//vAufgabe_2();
	//vAufgabe_3(); //naja...
	//vAufgabe_4();
	//vAufgabe_5();
	//vAufgabe_6();
	//vAufgabe_6_2();
	//vAufgabe_6a();
	vAufgabe_7();

	return 0;
}



