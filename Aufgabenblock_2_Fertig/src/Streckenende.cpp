/*
 * Streckenende.cpp
 *
 *  Created on: 11.01.2023
 *      Author: mickey
 */

#include "Streckenende.h"
#include "Fahrzeug.h"
#include "Weg.h"
#include "Kreuzung.h"
#include "memory"

unique_ptr<Fahrzeug> f;

Streckenende::Streckenende(Fahrzeug& aFzg, Weg& weg):Fahrausnahme(aFzg,weg) {}
Streckenende::~Streckenende(){}

void Streckenende::vBearbeiten(){
		cout<<p_pFahrzeug.getName()<< " ist am Streckenende von "<< p_pWeg.getName()<<" angekommen!"<<endl;
		//p_pWeg.pAbgabe(p_pFahrzeug);

		shared_ptr<Kreuzung> kreuzung = p_pWeg.getKreuzung();
		shared_ptr<Weg> neuweg = kreuzung->pZufaelligerWeg(p_pWeg);

		//kreuzung->vTanken(p_pFahrzeug);
		//neuweg->vAnnahme(move(p_pWeg.pAbgabe(p_pFahrzeug)));

		vertagt::VListe<unique_ptr<Fahrzeug>>* fzgList = p_pWeg.getFahrzeugListe();

		vIterator it;
			for (it = fzgList->begin(); it != fzgList->end(); it++)
			{
				if ((*it).get() == &p_pFahrzeug)
				{
					fzgList->erase(it);
					kreuzung->vTanken(p_pFahrzeug);
					neuweg->vAnnahme(move(*it));
					break;
				}
			}

		fzgList->vAktualisieren();
		cout << "ZEIT     " << ":" << dGlobaleZeit << endl;
		cout << "KREUZUNG " << ":" << kreuzung->getName() << " " << kreuzung->getVolTankstelle() << endl;
		cout << "WECHSEL  " << ":" << p_pWeg.getName() << " -> " << neuweg->getName() << endl;
		cout << "FAHRZEUG " << ":" << p_pFahrzeug.getName() << endl<<endl;
}

