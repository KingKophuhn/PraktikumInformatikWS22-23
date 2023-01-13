/*
 * Fahrraeder.cpp
 *
 *  Created on: 01.12.2022
 *      Author: mickey
 */

#include "Fahrraeder.h"
#include <math.h>

Fahrraeder::Fahrraeder(): Fahrzeug() {
	// TODO Auto-generated constructor stub

}
Fahrraeder::Fahrraeder(string name, double maxGeschw): Fahrzeug(name, maxGeschw) {
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


