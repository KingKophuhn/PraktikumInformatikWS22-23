/*
 * PKW.cpp
 *
 *  Created on: 01.12.2022
 *      Author: mickey
 */

#include "PKW.h"

PKW::PKW(): Fahrzeug(){
	cout<< "trest";
}
PKW::PKW(string name): Fahrzeug(name){
	//cout << "Fahrzeug: Name: "<< p_sName <<"\t->\tID: "<< p_iID <<"\t\tMaxGeschwindigkeit: "<< p_dMaxGeschwindigkeit << endl;
}

PKW::PKW(string name, double maxGeschw): Fahrzeug(name, maxGeschw){
	//cout << "Fahrzeug: Name: "<< p_sName <<"\t->\tID: "<< p_iID <<"\t\tMaxGeschwindigkeit: "<< p_dMaxGeschwindigkeit <<endl;
}

PKW::PKW(string name, double maxGeschw, double verbrauch, double tankVolumen):Fahrzeug(name, maxGeschw),p_dVerbrauch(verbrauch),
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
	p_dTankinhalt = p_dTankinhalt < 0?0 : p_dTankinhalt;
}


