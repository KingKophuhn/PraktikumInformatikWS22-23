/*
 * PKW.cpp
 *
 *  Created on: 01.12.2022
 *      Author: mickey
 */

#include "PKW.h"
#include "Verhalten.h"
#include "Weg.h"
#include "SimuClient.h"

PKW::PKW(): Fahrzeug(){
	cout<< "trest";
}
PKW::PKW(string name): Fahrzeug(name){
	//cout << "Fahrzeug: Name: "<< p_sName <<"\t->\tID: "<< p_iID <<"\t\tMaxGeschwindigkeit: "<< p_dMaxGeschwindigkeit << endl;
}

PKW::PKW(string name, double maxGeschw): Fahrzeug(name, maxGeschw){
	//cout << "Fahrzeug: Name: "<< p_sName <<"\t->\tID: "<< p_iID <<"\t\tMaxGeschwindigkeit: "<< p_dMaxGeschwindigkeit <<endl;
}

PKW::PKW(string name, double maxGeschw, double verbrauch, double tankVolumen,bool createMsg,bool deleteMsg):Fahrzeug(name, maxGeschw,createMsg,deleteMsg),p_dVerbrauch(verbrauch),
																				p_dTankinhalt(tankVolumen/2),p_dTankvolumen(tankVolumen){

}

PKW::~PKW() {
	// TODO Auto-generated destructor stub
}

double PKW::dTanken(double dMenge){
	dMenge > (p_dTankvolumen-p_dTankinhalt) ? ({
		dMenge = p_dTankvolumen-p_dTankinhalt;
		p_dTankinhalt = p_dTankvolumen;
		return dMenge;
	}):({
		p_dTankinhalt += dMenge;
		return dMenge;
	});
	return 0;
}

void  PKW::vSimulieren(){
	if (p_dTankinhalt <= 0){
		p_dZeit = dGlobaleZeit;
		return;
	}
	double vsGesStrecke = p_dGesamtStrecke;
	Fahrzeug::vSimulieren();
	p_dTankinhalt -= p_dVerbrauch / 100 *(p_dGesamtStrecke - vsGesStrecke); // tankinhalt um die zuletzt gefahren strecke leeren
	//p_dTankinhalt = p_dTankinhalt < 0?0 : p_dTankinhalt;
	if(p_dTankinhalt<0) {p_dTankinhalt=0; cout<<getName()<<" hat den tank leer gefahren!";}; //bTankLeermsg=true

}

double PKW::dGeschwindigkeit(){
	if(!p_pVerhalten)return 0; //sollte zwar immer da sein dennoch überprüfen ist besser!

	double dTempo = p_pVerhalten->getWeg()->getTempolimit(); //Tempolimit abfragen.. Funktion getWeg hinzugefürgt um auf Weg zugreifen zu können!
	if(dTempo < p_dMaxGeschwindigkeit) return dTempo; else return p_dMaxGeschwindigkeit;
}

void PKW::vZeichnen(Weg &weg){
	double dGeschwind = dGeschwindigkeit();
	double dLaenge = weg.getLaenge();
	double realPosition = p_dStreckenAbschnitt / dLaenge;
	bZeichnePKW(p_sName, weg.getName(), realPosition, dGeschwind, p_dTankinhalt);
}



