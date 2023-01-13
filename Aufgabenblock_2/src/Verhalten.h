/*
 * Verhalten.h
 *
 *  Created on: 11.01.2023
 *      Author: mickey
 */

#ifndef SRC_VERHALTEN_H_
#define SRC_VERHALTEN_H_

class Fahrzeug;
class Weg;

class Verhalten {
protected: Weg* p_pWeg=0;
public:
	Verhalten(Weg& weg);
	Verhalten();
	virtual ~Verhalten();
	Verhalten(const Verhalten &other)=delete;

	virtual Weg* getWeg();

	virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall)=0;
};

#endif /* SRC_VERHALTEN_H_ */
