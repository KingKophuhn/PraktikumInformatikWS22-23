/*
 * Kreuzung.cpp
 *
 *  Created on: 12.01.2023
 *      Author: mickey
 */

#include "Kreuzung.h"
#include "Fahrzeug.h"
#include <memory>

Kreuzung::Kreuzung() {}

Kreuzung::Kreuzung(string name,double dVolTankstelle): p_dTankstelle(dVolTankstelle),Simulationsobject(name) {}

Kreuzung::~Kreuzung() {}


void Kreuzung::vTanken(Fahrzeug& pFzg){
	if(p_dTankstelle>0.0)p_dTankstelle-=pFzg.dTanken();
	if(p_dTankstelle<=0) p_dTankstelle=0;
}

void Kreuzung::coutWege(){
	//cout<<p_pHinweg<<endl<<p_pRueckweg<<endl<<endl; //extra ausgabe für die wege der kreutzungen
}

void Kreuzung::vVerbinde(string nameHinweg, string nameRueckweg, double dWegLaenge,
	weak_ptr<Kreuzung> pStartKreuzung, const weak_ptr<Kreuzung> pZielKreuzung,Tempolimit GeschwLimit,bool bUeberholVerbot){

	shared_ptr<Weg> pHinweg = make_shared<Weg>(nameHinweg,dWegLaenge,pZielKreuzung,GeschwLimit,bUeberholVerbot);
	shared_ptr<Weg> pRueckweg = make_shared<Weg>(nameRueckweg,dWegLaenge,pStartKreuzung,GeschwLimit,bUeberholVerbot);

	//cout<<pHinweg<<endl<<pRueckweg<<endl<<endl;

	pHinweg->setRueckweg(pRueckweg);
	pRueckweg->setRueckweg(pHinweg);

	pZielKreuzung.lock()->p_pWege.push_back(pRueckweg);
	pStartKreuzung.lock()->p_pWege.push_back(pHinweg);
}

void Kreuzung::vAnnahme(unique_ptr<Fahrzeug> pFzg, double dZeit){
	vTanken(*pFzg);
	//if(dZeit==0){p_pWege.back()->vAnnahme(move(pFzg));}
	p_pWege.front()->vAnnahme(move(pFzg),dZeit);
}

void Kreuzung::vAnnahme(unique_ptr<Fahrzeug> pFzg){
	vTanken(*pFzg);
	//if(dZeit==0){p_pWege.back()->vAnnahme(move(pFzg));}
	p_pWege.front()->vAnnahme(move(pFzg));
}

void Kreuzung::vSimulieren(){
	list<shared_ptr<Weg>>::iterator it;
	for (it = p_pWege.begin();it != p_pWege.end();it++) {
			(*it)->vSimulieren();
		}
}

shared_ptr<Weg> Kreuzung::pZufaelligerWeg(Weg& wegGekommen){

	if(p_pWege.size()==1)return wegGekommen.getRueckweg();;

	int randInt = rand()%p_pWege.size();

	list<shared_ptr<Weg>>::iterator iter = p_pWege.begin();
	for(int pos = 0;pos<randInt;pos++){iter++;}

	if((*iter).get()->getName() == wegGekommen.getRueckweg()->getName()) return pZufaelligerWeg(wegGekommen); //XXX

	return *iter;
}












