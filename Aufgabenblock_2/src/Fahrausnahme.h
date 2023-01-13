/*
 * Fahrausnahme.h
 *
 *  Created on: 11.01.2023
 *      Author: mickey
 */

#ifndef SRC_FAHRAUSNAHME_H_
#define SRC_FAHRAUSNAHME_H_

#include <exception>
using namespace std;

class Fahrzeug;
class Weg;

class Fahrausnahme: public exception {
protected:
	Fahrzeug& p_pFahrzeug;
	Weg& p_pWeg;
public:
	Fahrausnahme()=default;
	Fahrausnahme(Fahrzeug& aFzg, Weg& weg);
	virtual ~Fahrausnahme();
	Fahrausnahme(const Fahrausnahme &other)=delete;

	virtual void vBearbeiten()=0;
};

#endif /* SRC_FAHRAUSNAHME_H_ */
