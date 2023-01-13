/*
 * Fahren.cpp
 *
 *  Created on: 11.01.2023
 *      Author: mickey
 */

#include "Fahren.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Streckenende.h"

Fahren::Fahren() {}

Fahren::Fahren(Weg& weg):Verhalten(weg){}

Fahren::~Fahren() {}

double Fahren::dStrecke(Fahrzeug& aFzg, double dZeitIntervall){
	if(dZeitIntervall==0) return 0;

	double gesStrecke_Zeit=aFzg.dGeschwindigkeit()*dZeitIntervall;
	double dStreckenAbschnitt = aFzg.getStreckenAbschnitt();
	double wegLaengeRest = p_pWeg->getLaenge() - dStreckenAbschnitt;

	//cout<<"testtteteetetettee"<<endl;

//	if(wegLaengeRest<=gesStrecke_Zeit){
//		cout << aFzg.getName()<< " ist am ende von der Strecke "<<p_pWeg->getName()<<" angekommen!"<<endl;
//		return wegLaengeRest;
//	}

	if (wegLaengeRest <0.01)
		{
			throw new Streckenende(aFzg, *p_pWeg);
			return 0;
		}
	double dFahrbarLaenge = min(wegLaengeRest,gesStrecke_Zeit);
	return dFahrbarLaenge;
}

