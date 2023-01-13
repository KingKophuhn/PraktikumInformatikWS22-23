/*
 * Streckenende.h
 *
 *  Created on: 11.01.2023
 *      Author: mickey
 */

#ifndef SRC_STRECKENENDE_H_
#define SRC_STRECKENENDE_H_

#include "Fahrausnahme.h"

class Streckenende:public Fahrausnahme {
public:
	Streckenende(Fahrzeug& aFzg, Weg& weg);
	virtual ~Streckenende();
	Streckenende(const Streckenende &other)=delete;

	virtual void vBearbeiten() override;
};

#endif /* SRC_STRECKENENDE_H_ */
