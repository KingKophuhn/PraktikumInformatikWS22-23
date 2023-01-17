/*
 * Weg.cpp
 *
 *  Created on: 09.01.2023
 *      Author: mickey
 */

#include "Weg.h"
#include "Fahrausnahme.h"
#include "SimuClient.h"

Weg::Weg():Simulationsobject() {}

Weg::Weg(string name, double laenge, Tempolimit geschwLimit, bool bUeberholverbot) :
	Simulationsobject(name) {
	p_dLanenge = laenge;
	p_eTempolimit = geschwLimit;
	p_bUeberholverbot = bUeberholverbot;
	cout<< "Die Strecke "<< name<< " wurde erstellt: geschw: "<<static_cast<double>(geschwLimit) <<" länge: "<< to_string(laenge)<<endl;
}

Weg::Weg(string name, double laenge, weak_ptr<Kreuzung> pKreuzung, Tempolimit geschwLimit, bool bUeberholverbot) :
	Simulationsobject(name),p_pKreuzung(pKreuzung) {
	p_dLanenge = laenge;
	p_eTempolimit = geschwLimit;
	p_bUeberholverbot = bUeberholverbot;
	cout<< "Die Strecke "<< name<< " wurde erstellt: geschw: "<<static_cast<double>(geschwLimit) <<" länge: "<< to_string(laenge)<<endl;
}

Weg::~Weg() {
	// TODO Auto-generated destructor stub
}

double Weg::getTempolimit() {
	return static_cast<double>(p_eTempolimit);
}

void Weg::vSimulieren() {
	p_pFahrzeuge.vAktualisieren();

//	for (auto& f : p_pFahrzeuge) {//funktioniert nicht ordnungsgemäß. Vermutung: Nachdem
//		//cout<<"anfang liste iterieren!"<<endl;
//		try{
//			cout<<"und jetzt (2)"<<endl;
//			cout<<"und jetzt (2)"<<f.get()->getName()<<endl; //f.get() klappt nicht mehr??? cout kann den namen nicht ausgeben! das selbe problem wird auch bei vSimulieren der Fall sein!
//			f.get()->vSimulieren();			//fahrzeuge aus der liste nacheinader simulieren!
//			//cout<<"und jetzt (3)"<<endl;
//			f.get()->vZeichnen(*this);		//~ zeichnen
//		}catch (Fahrausnahme* pFahrausnahme) {
//			//cout<< "test Lebst du noch?"<<endl;
//			pFahrausnahme->vBearbeiten();
//			//cout<< "jetzt auch noch?"<<endl;
//		}
//	}
//	//cout<<"und jetzt?"<<endl;
//	p_pFahrzeuge.vAktualisieren();

		for (vIterator iter = p_pFahrzeuge.begin(); iter != p_pFahrzeuge.end();/*iter++*/){ //ausweich lösung!! //wenn iter in der for-schleife erhöht wird klappt es nicht!! warum?
			try{
				(*iter)->vSimulieren();
				(*iter)->vZeichnen(*this);
				iter++;
			}catch (Fahrausnahme *pFahrausnahme){
				iter++;
				pFahrausnahme->vBearbeiten();
			}
		}
		p_pFahrzeuge.vAktualisieren();
}

double Weg::getLaenge(){
	return p_dLanenge;
}

void Weg::vAnnahme(unique_ptr<Fahrzeug> pFzg){
	pFzg->vNeueStrecke(*this);
	p_pFahrzeuge.push_back(move(pFzg));
	p_pFahrzeuge.vAktualisieren();

}

void Weg::vAnnahme(unique_ptr<Fahrzeug> pFzg,double dStartZeit){
	pFzg->vNeueStrecke(*this ,dStartZeit);
	//cout<<"test neue strecke"<<endl;
	p_pFahrzeuge.push_front(move(pFzg));
	p_pFahrzeuge.vAktualisieren();
}

unique_ptr<Fahrzeug> Weg::pAbgabe(const Fahrzeug& pFzg){
	for (vIterator f = p_pFahrzeuge.begin(); f != p_pFahrzeuge.end(); f++) { // for geht die liste durch bist das letzte element nicht f ist
		if((*f).get()==&pFzg){
			unique_ptr<Fahrzeug> tempPFzg = move(*f);
			p_pFahrzeuge.erase(f);
			p_pFahrzeuge.vAktualisieren();
			return tempPFzg;
		}
	}
	return nullptr;
}


shared_ptr<Weg> Weg::getRueckweg(){return shared_ptr<Weg>(p_pRueckWeg.lock());}

shared_ptr<Kreuzung> Weg::getKreuzung(){return shared_ptr<Kreuzung>(p_pKreuzung.lock());}

vertagt::VListe<unique_ptr<Fahrzeug>>* Weg::getFahrzeugListe(){return &p_pFahrzeuge;}

void Weg::setRueckweg(shared_ptr<Weg> pRueckweg){p_pRueckWeg = pRueckweg;}


