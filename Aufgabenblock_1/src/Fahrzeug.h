/*
 * Fahrzeug.h
 */
#ifndef FAHRZEUG_H_
#define FAHRZEUG_H_

extern double dGlobaleZeit;

#include <string>
#include<iomanip>
#include <iostream>
#include <limits>
using namespace std;

class Fahrzeug {
private:
	static int p_MaxID; // Hochzählende ID variable (int)


protected:
	double p_dGesamtStrecke=0,p_dgesamtZeit=0,p_dZeit=0,p_dMaxGeschwindigkeit=0; // deklarieren von var.
	string p_sName;
	const int p_iID;
	int generateId();
public:
	Fahrzeug();
	Fahrzeug(string name);
	Fahrzeug(string name, double maxGeschw);

	Fahrzeug(const Fahrzeug &fahrzeug) = delete; //?

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


};
#endif /* FAHRZEUG_H_ */
ostream& operator<<(ostream&, Fahrzeug& fahrzeug);
