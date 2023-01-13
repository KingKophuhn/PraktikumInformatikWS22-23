/*
 * main.cpp
 */
#include <iostream>
#include <vector>
#include <memory> // für make_unique usw.
#include <iomanip> //Input-Output-Manipulatoren der Standard C++ Bibliothek


#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrraeder.h"

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

		Fahrzeug* ofPKW=new PKW("Auto", 333, 12, 60);
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

}

int main() { // Globale Zeit festlegen. Start bei 00:00 (0)
	//vAufgabe_1();
	//vAufgabe_1a();
	//vAufgabe_2();
	//vAufgabe_3(); //naja...

	return 0;
}



