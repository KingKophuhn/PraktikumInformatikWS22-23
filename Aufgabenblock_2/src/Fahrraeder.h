/*
 * Fahrraeder.h
 *
 *  Created on: 01.12.2022
 *      Author: mickey
 */

#ifndef FAHRRAEDER_H_
#define FAHRRAEDER_H_
#include "Fahrzeug.h"

class Fahrraeder : public Fahrzeug {
public:
	Fahrraeder();
	Fahrraeder(string name, double maxGeschw,bool createMsg=false,bool deleteMsg=false);
	virtual ~Fahrraeder();

	virtual double dGeschwindigkeit() override;
	virtual void vAusgeben() override;
	virtual void vAusgeben(ostream&) override;
	virtual void vZeichnen(Weg&) override;
};

#endif /* FAHRRAEDER_H_ */

