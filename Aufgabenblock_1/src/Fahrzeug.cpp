/*
 * Fahrzeug.cpp
 */
#include "Fahrzeug.h"
using namespace std;

Fahrzeug::Fahrzeug():p_iID(generateId()){
	//default constructor
	//this->p_iID = generateId();	geht nur ohne const!
	//cout << "Fahrzeug: Name: "<< p_sName <<"\t->\tID: "<< p_iID <<"\t\tMaxGeschwindigkeit: "<< p_dMaxGeschwindigkeit << endl;
}

Fahrzeug::Fahrzeug(string name):p_iID(generateId()) {
	// TODO Auto-generated constructor stub
	this->p_sName = name;
	//this->p_iID = generateId();	geht nur ohne const!
	cout << "Fahrzeug: Name: "<< p_sName <<"\t->\tID: "<< p_iID <<"\t\tMaxGeschwindigkeit: "<< p_dMaxGeschwindigkeit << endl;
}

Fahrzeug::Fahrzeug(string name, double maxGeschw): p_iID(generateId()){
	this->p_sName = name;
	//this->p_iID = generateId();	geht nur ohne const!
	this->p_dMaxGeschwindigkeit = maxGeschw>=0? maxGeschw : -1*maxGeschw;
	if(maxGeschw < 0) {cout << "Die eingegebene maxGeschwindigkeit ist negative! Die geschwindigkeit für "+p_sName+" wird auf "<<-1*maxGeschw<<" gesetzt!\n";}; //zusätzliche ausgabe für den benutzen.
	//cout << "Fahrzeug: Name: "<< p_sName <<"\t->\tID: "<< p_iID <<"\t\tMaxGeschwindigkeit: "<< p_dMaxGeschwindigkeit <<endl;
}


Fahrzeug::~Fahrzeug() {
	// TODO Auto-generated destructor stub
	cout <<"Fahrzeug: Name: "<< p_sName <<"\t->\tID. "<< p_iID <<"\tdeleted!"<< endl;
}


int Fahrzeug::generateId() {
	return ++Fahrzeug::p_MaxID; //für große projekte ist eine zufällig generierte ID inclusive liste besser geeignet.
}


void Fahrzeug::vSimulieren(){
	if(dGlobaleZeit == p_dZeit) return;
	p_dGesamtStrecke += dGeschwindigkeit()*(dGlobaleZeit - p_dZeit);//this->p_dMaxGeschwindigkeit * (dGlobaleZeit - this->p_dZeit); // s = v * t
	p_dgesamtZeit += (dGlobaleZeit-p_dZeit);
	p_dZeit = dGlobaleZeit; // p_dZeit auf den aktuellen zeitwert setzen
}

double Fahrzeug::dTanken(double dMenge){
	return 0;
}

double Fahrzeug::dGeschwindigkeit(){return p_dMaxGeschwindigkeit;}

int Fahrzeug::p_MaxID { 0 }; //Max ID auf 0 setzen (sollte engentlich schon 0 sein!)


ostream& operator<<(ostream& o, Fahrzeug& fahrzeug){
	fahrzeug.vAusgeben(o);
	return o;
}

bool Fahrzeug::operator<(const Fahrzeug& f){
	return (p_dGesamtStrecke < f.p_dGesamtStrecke);
}

Fahrzeug& Fahrzeug::operator =(const Fahrzeug &fahrzeug){
	p_sName = fahrzeug.p_sName; //die ID kann ich nicht kopieren!! höchstens eine neu definieren
	p_dGesamtStrecke = fahrzeug.p_dGesamtStrecke;
	p_dMaxGeschwindigkeit = fahrzeug.p_dMaxGeschwindigkeit;
	p_dgesamtZeit = fahrzeug.p_dgesamtZeit;
	p_dZeit = fahrzeug.p_dZeit;
	return *this;
}
