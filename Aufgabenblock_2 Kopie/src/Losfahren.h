/*
 * Losfahren.h
 *
 *  Created on: 11.01.2023
 *      Author: mickey
 */

#ifndef SRC_LOSFAHREN_H_
#define SRC_LOSFAHREN_H_

#include "Fahrausnahme.h"

class Losfahren:public Fahrausnahme {
public:
	Losfahren(Fahrzeug& aFzg, Weg& weg);
	virtual ~Losfahren();
	Losfahren(const Losfahren &other)=delete;

	virtual void vBearbeiten() override;
};

#endif /* SRC_LOSFAHREN_H_ */
