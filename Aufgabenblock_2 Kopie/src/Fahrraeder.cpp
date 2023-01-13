/*
 * Fahrraeder.cpp
 *
 *  Created on: 01.12.2022
 *      Author: mickey
 */

#include "Fahrraeder.h"
#include <math.h>
#include"Weg.h"
#include "SimuClient.h"

Fahrraeder::Fahrraeder(): Fahrzeug() {
	// TODO Auto-generated constructor stub

}
Fahrraeder::Fahrraeder(string name, double maxGeschw,bool createMsg,bool deleteMsg): Fahrzeug(name, maxGeschw,createMsg,deleteMsg) {
}

Fahrraeder::~Fahrraeder() {
	// TODO Auto-generated destructor stub
}

double Fahrraeder::dGeschwindigkeit(){
	int iPow=(int)(p_dGesamtStrecke / 20);
		double dGeschwindigkeit = p_dMaxGeschwindigkeit*pow(0.9,iPow);
		if (dGeschwindigkeit < 12) dGeschwindigkeit = 12;
		return dGeschwindigkeit;
}

void Fahrraeder::vZeichnen(Weg& weg){
	double dGeschwind = dGeschwindigkeit();
	double dLaenge = weg.getLaenge();
	double realPosition = p_dStreckenAbschnitt / dLaenge;
	string tmp = weg.getName();
	const char *sWegname = tmp.c_str();
//	string tem = weg.getName();
	bZeichneFahrrad(p_sName, sWegname, realPosition, dGeschwind);
}

