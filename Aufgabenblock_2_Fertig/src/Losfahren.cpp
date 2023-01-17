/*
 * Losfahren.cpp
 *
 *  Created on: 11.01.2023
 *      Author: mickey
 */

#include "Losfahren.h"
#include "Fahrzeug.h"
#include "Weg.h"

Losfahren::Losfahren(Fahrzeug& aFzg, Weg& weg):Fahrausnahme(aFzg,weg){vBearbeiten();} //XXX XXX XXX

Losfahren::~Losfahren() {
	// TODO Auto-generated destructor stub
}

void Losfahren::vBearbeiten(){
	cout<<p_pFahrzeug.getName()<< " fährt jetzt auf "<< p_pWeg.getName()<<". Startzeit: "<<p_pFahrzeug.getstartZeit()<<endl;

	unique_ptr<Fahrzeug> pf = p_pWeg.pAbgabe(p_pFahrzeug);
	p_pWeg.vAnnahme(move(pf));
}

