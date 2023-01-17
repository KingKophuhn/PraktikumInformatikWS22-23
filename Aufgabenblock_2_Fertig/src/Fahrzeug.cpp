/*
 * Fahrzeug.cpp
 */
#pragma once
#include "Fahrzeug.h"
#include "Verhalten.h"
#include "Fahren.h"
#include "Parken.h"
#include <math.h>

using namespace std;

Fahrzeug::Fahrzeug():Simulationsobject(){ // @suppress("Class members should be properly initialized")
}

Fahrzeug::Fahrzeug(string name):Simulationsobject(name){ // @suppress("Class members should be properly initialized")
	cout << "Fahrzeug: Name: "<< p_sName <<"\t->\tID: "<< p_iID <<"\t\tMaxGeschwindigkeit: "<< p_dMaxGeschwindigkeit << endl;
}

Fahrzeug::Fahrzeug(string name, double maxGeschw,bool createMsg,bool deleteMsg):Simulationsobject(name,createMsg,deleteMsg) { // @suppress("Class members should be properly initialized")
	this->p_dMaxGeschwindigkeit = maxGeschw>=0? maxGeschw : -1*maxGeschw;
	if(maxGeschw < 0) {cout << "Die eingegebene maxGeschwindigkeit ist negative! Die geschwindigkeit für "+p_sName+" wird auf "<<-1*maxGeschw<<" gesetzt!\n";}; //zusätzliche ausgabe für den benutzen.
	if(p_bcreateMsg==true)cout << "Fahrzeug: Name: "<< p_sName <<"\t->\tID: "<< p_iID <<"\t\tMaxGeschwindigkeit: "<< p_dMaxGeschwindigkeit <<endl;
}


Fahrzeug::~Fahrzeug() {
	//cout <<"Fahrzeug: Name: "<< p_sName <<"\t->\tID. "<< p_iID <<"\tdeleted!"<< endl;
}


//void Fahrzeug::vSimulieren(){
//	if(dGlobaleZeit == p_dZeit) return;
//	p_dGesamtStrecke += dGeschwindigkeit()*(dGlobaleZeit - p_dZeit);//this->p_dMaxGeschwindigkeit * (dGlobaleZeit - this->p_dZeit); // s = v * t
//	p_dgesamtZeit += (dGlobaleZeit-p_dZeit);
//	p_dZeit = dGlobaleZeit; // p_dZeit auf den aktuellen zeitwert setzen
//}

void Fahrzeug::vSimulieren(){
	cout<<"und jetzt? Fahrzeug::vSinmulieren()"<<endl;
	double dZeitIntervall = fabs(dGlobaleZeit-p_dZeit); //fabs The absolute value
	if(dZeitIntervall<0.0001) return;
	p_dZeit=dGlobaleZeit;
	double gefStrecke = p_pVerhalten->dStrecke(*this,dZeitIntervall);
	//cout<<"teest"<<gefStrecke<<endl;
	p_dGesamtStrecke += gefStrecke;
	p_dgesamtZeit += dZeitIntervall;
	//streckenabschnitt speichern?
	p_dStreckenAbschnitt += gefStrecke;
	//p_dZeit=dGlobaleZeit;

}

double Fahrzeug::dTanken(double dMenge){
	return 0;
}

double Fahrzeug::dGeschwindigkeit(){return p_dMaxGeschwindigkeit;}



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

double Fahrzeug::getStreckenAbschnitt(){
	return p_dStreckenAbschnitt;
}


void Fahrzeug::vNeueStrecke(Weg& weg){
	p_dStreckenAbschnitt=0;
	if(p_pVerhalten){ delete p_pVerhalten;} // wenn ein alter Weg existiert wird dieser gelöscht!
	//cout<<"tefefeefefefefefe"<<endl;
	p_pVerhalten = new Fahren(weg); //new Fahren(weg) oder Verhalten(weg) kann man benutzen! Die Klasse Fahren dient dem verständnis wegen der Klasse Parken.
}

void Fahrzeug::vNeueStrecke(Weg& weg,double dStartZeit){
	p_dStreckenAbschnitt=0;
	if(p_pVerhalten){ delete p_pVerhalten;} // wenn ein alter Weg existiert wird dieser gelöscht!

	p_pVerhalten = new Parken(weg,dStartZeit);
}
