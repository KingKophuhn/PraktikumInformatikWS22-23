/*
 * Kreuzung.h
 *
 *  Created on: 12.01.2023
 *      Author: mickey
 */

#ifndef SRC_KREUZUNG_H_
#define SRC_KREUZUNG_H_

#include "Simulationsobject.h"
#include "Weg.h"
#include <list>
#include<memory>




class Kreuzung:public Simulationsobject {
public:

	Kreuzung();
	Kreuzung(string name, double dVolTankstelle = 0);
	virtual ~Kreuzung();
	Kreuzung(const Kreuzung &other)=delete;

	static void vVerbinde(string nameHinweg, string nameRueckweg,double dWegLaenge,
			weak_ptr<Kreuzung> pStartKreuzung, const weak_ptr<Kreuzung> pZielKreuzung, Tempolimit GeschwLimit = Tempolimit::Autobahn, bool bUeberholVerbot=true);

	void vTanken(Fahrzeug& pFzg);
	void vAnnahme(unique_ptr<Fahrzeug>,double dZeit);
	void vAnnahme(unique_ptr<Fahrzeug>);
	void vSimulieren();

	double getVolTankstelle(){return p_dTankstelle;}

	shared_ptr<Weg> pZufaelligerWeg(Weg&);
	void coutWege();
private:
	//shared_ptr<Weg>* p_pHinweg,p_pRueckweg;
	double p_dTankstelle;
	list<shared_ptr<Weg>> p_pWege;
};

#endif /* SRC_KREUZUNG_H_ */
