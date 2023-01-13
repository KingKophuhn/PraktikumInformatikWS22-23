/*
 * Weg.h
 *
 *  Created on: 09.01.2023
 *      Author: mickey
 */

#ifndef SRC_WEG_H_
#define SRC_WEG_H_

#pragma once
#include <list>
#include <string>
#include <limits>
#include<memory>
#include "Simulationsobject.h"
#include "Fahrzeug.h"
#include "Tempolimit.h"
#include "vertagt_liste - Vorlage.h"
using namespace std;



class Fahrzeug;
class Fahrausnahme;
class Kreuzung;


typedef vertagt::VListe<unique_ptr<Fahrzeug>>::iterator vIterator;


class Weg:public Simulationsobject {
private:
	double p_dLanenge=0;
	//list<Fahrzeug*> p_pFahrzeuge; //XXX
	//list<unique_ptr<Fahrzeug>> p_pFahrzeuge;
	vertagt::VListe<unique_ptr<Fahrzeug>> p_pFahrzeuge;
	Tempolimit p_eTempolimit=Tempolimit::Autobahn;

	weak_ptr<Weg> p_pRueckWeg;
	const weak_ptr<Kreuzung> p_pKreuzung;
	bool p_bUeberholverbot=true;

public:
	Weg();
	Weg(string name, double laenge, Tempolimit geschwLimit = Tempolimit::Autobahn, bool bUeberholverbot = true);
	Weg(string name, double laenge, weak_ptr<Kreuzung> pKreuzung ,Tempolimit geschwLimit = Tempolimit::Autobahn, bool bUeberholverbot = true);
	virtual ~Weg();
	Weg(const Weg &weg)=delete;

	double getTempolimit();
	virtual void vSimulieren() override;
	virtual void vAusgaben();
	virtual void vAusgeben(ostream&) override;
	static void vKopf();
	double getLaenge();

	virtual void vAnnahme(unique_ptr<Fahrzeug>);
	virtual void vAnnahme(unique_ptr<Fahrzeug>,double dStartZeit);

	unique_ptr<Fahrzeug> pAbgabe(const Fahrzeug&);


	shared_ptr<Weg>getRueckweg();
	shared_ptr<Kreuzung> getKreuzung();

	vertagt::VListe<unique_ptr<Fahrzeug>>* getFahrzeugListe();
	void setRueckweg(shared_ptr<Weg> pRueckweg);
};

#endif /* SRC_WEG_H_ */
//ostream& operator<<(ostream&, Weg& weg);
