/*
 * Parken.h
 *
 *  Created on: 11.01.2023
 *      Author: mickey
 */

#ifndef SRC_PARKEN_H_
#define SRC_PARKEN_H_

#include "Verhalten.h"

class Parken:public Verhalten {
private: double p_dStartZeit=0;
public:
	Parken();
	Parken(Weg&,double dStartZeit);
	virtual ~Parken();
	Parken(const Parken &other)=delete;

	virtual double dStrecke(Fahrzeug& aFzg, double dZeitIntervall) override;
};

#endif /* SRC_PARKEN_H_ */
