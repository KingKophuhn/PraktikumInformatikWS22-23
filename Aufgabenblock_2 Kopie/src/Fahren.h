/*
 * Fahren.h
 *
 *  Created on: 11.01.2023
 *      Author: mickey
 */

#ifndef SRC_FAHREN_H_
#define SRC_FAHREN_H_
#include "Verhalten.h"

class Fahren: public Verhalten {
public:
	Fahren();
	Fahren(Weg&);
	virtual ~Fahren();
	Fahren(const Fahren &other)=delete;

	virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) override;
};

#endif /* SRC_FAHREN_H_ */
