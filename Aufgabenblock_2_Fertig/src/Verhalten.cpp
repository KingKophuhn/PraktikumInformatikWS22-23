/*
 * Verhalten.cpp
 *
 *  Created on: 11.01.2023
 *      Author: mickey
 */

#include "Verhalten.h"
#include "Weg.h"
#include "Fahren.h"
#include "Streckenende.h"

Verhalten::Verhalten() {}

Verhalten::Verhalten(Weg& weg) {
	p_pWeg= &weg;
}

Verhalten::~Verhalten() {
}

//double Verhalten::dStrecke(Fahrzeug& aFzg, double dZeitIntervall){
//
//	double wegLaenge = p_pWeg->getLaenge()-aFzg.getStreckenAbschnitt();
//	double gesStrecke_Zeit=aFzg.dGeschwindigkeit()*dZeitIntervall;
//	double dAbschnittstreche = aFzg.getStreckenAbschnitt();
//
//	if(gesStrecke_Zeit>=p_pWeg->getLaenge()){
//		Streckenende(aFzg,*p_pWeg);
//		//cout << aFzg.getName()<< "ist am ende von"<<p_pWeg->getName()<<"angekommen!"<<endl;
//		return wegLaenge;
//	}
//	return gesStrecke_Zeit;
//}

Weg* Verhalten::getWeg(){
	return p_pWeg;
}

