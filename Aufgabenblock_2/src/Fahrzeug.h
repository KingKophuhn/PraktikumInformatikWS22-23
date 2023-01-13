/*
 * Fahrzeug.h
 */
#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_

extern double dGlobaleZeit;
#pragma once
#include <string>
#include<iomanip>
#include <iostream>
#include <limits>
#include "Simulationsobject.h"


using namespace std;

class Weg;
class Verhalten;
class Fahren;
class Parken;

class Fahrzeug :public Simulationsobject{

protected:
	double p_dGesamtStrecke=0,p_dgesamtZeit=0,p_dMaxGeschwindigkeit=0,p_dStreckenAbschnitt=0,p_dStartZeit=0; // deklarieren von var.
	Verhalten *p_pVerhalten;
	//shared_ptr<Verhalten> p_pVerhalten;


public:
	Fahrzeug();
	Fahrzeug(string name);
	Fahrzeug(string name, double maxGeschw,bool createMsg=false,bool deleteMsg=false);

	Fahrzeug(const Fahrzeug &fahrzeug)=delete; //?

	virtual ~Fahrzeug();

	void printId();

	virtual void vAusgeben();
	//virtual void vAusgeben(ostream& o);

	static void vKopf();

	virtual void vSimulieren();

	virtual double dTanken(double dMenge = numeric_limits<double>::infinity());

	virtual double dGeschwindigkeit();

	virtual void vAusgeben(ostream&);

	bool operator <(const Fahrzeug& fahrzeug);

	Fahrzeug& operator =(const Fahrzeug& fahrzeug);

	virtual void vNeueStrecke(Weg&);
	virtual void vNeueStrecke(Weg&,double dStartZeit);

	double getStreckenAbschnitt();
	double getstartZeit() const {return p_dStartZeit;};

	void setAbschnittStrecke(double dAStreckemAbschnitt) { p_dStreckenAbschnitt = dAStreckemAbschnitt; };
	void setZeit(double dZeit){ p_dZeit = dZeit; }

	virtual void vZeichnen(Weg&){};
};
#endif /* FAHRZEUG_H_ */
ostream& operator<<(ostream&, Fahrzeug& fahrzeug);
