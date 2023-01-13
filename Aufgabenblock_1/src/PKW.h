/*
 * PKW.h
 *
 *  Created on: 01.12.2022
 *      Author: mickey
 */

#ifndef PKW_H_
#define PKW_H_

#include "Fahrzeug.h"


class PKW : public Fahrzeug { //PKW erweiterte klasse von Fahrzeug

	private:
		double p_dVerbrauch=0,p_dTankvolumen=55,p_dTankinhalt=p_dTankvolumen/2;

	public:



		PKW();
		PKW(string name);
		PKW(string name, double maxGeschw);
		PKW(string name, double maxGeschw, double verbrauch, double tankVolumen=55);
		virtual void vAusgeben() override;
		virtual double dTanken(double dMenge = numeric_limits<double>::infinity()) override; //es würde auch das Maxtankvolumen reichen...
		virtual void vSimulieren() override;

		virtual void vAusgeben(ostream&) override;

		virtual ~PKW();
};

#endif /* PKW_H_ */
