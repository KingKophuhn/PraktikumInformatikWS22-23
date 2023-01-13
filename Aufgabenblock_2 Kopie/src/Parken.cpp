/*
 * Parken.cpp
 *
 *  Created on: 11.01.2023
 *      Author: mickey
 */

#include "Parken.h"
#include "Fahrzeug.h"
#include "Losfahren.h"

extern double dGlobaleZeit;

Parken::Parken() {}
Parken::Parken(Weg& weg,double dStartZeit):Verhalten(weg) {
	p_dStartZeit = dStartZeit;
}

Parken::~Parken() {}


double Parken::dStrecke(Fahrzeug& aFzg, double dZeitIntervall){
	if(dGlobaleZeit >= p_dStartZeit){
		aFzg.setZeit(p_dStartZeit);
		Losfahren(aFzg, *p_pWeg);
		//cout<<"Parken-> losfahren!"<<endl;
	}
	//cout<< "Die Startzeit von "<< aFzg.getName()<<" wurde erreicht!"<<endl;
	return 0;
}

