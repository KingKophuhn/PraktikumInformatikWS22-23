/*
 * Simulationsobject.cpp
 *
 *  Created on: 09.01.2023
 *      Author: mickey
 */

#include "Simulationsobject.h"


int Simulationsobject::p_MaxID { 0 }; //Max ID auf 0 setzen (sollte engentlich schon 0 sein!)
Simulationsobject::Simulationsobject() :p_iID(generateId()){}


Simulationsobject::Simulationsobject(string name,bool createMsg,bool deleteMsg) :p_iID(generateId()){
	this->p_sName = name;
	this->p_bcreateMsg=createMsg;
	this->p_bdeleteMsg=deleteMsg;
}

Simulationsobject::~Simulationsobject() {
	// TODO Auto-generated destructor stub
	if(p_bdeleteMsg==true)cout <<"Fahrzeug: Name: "<< p_sName <<"\t->\tID. "<< p_iID <<"\tdeleted!"<< endl;
}

int Simulationsobject::generateId() {
	return ++Simulationsobject::p_MaxID; //für große projekte ist eine zufällig generierte ID inclusive liste besser geeignet.
}

void Simulationsobject::vSimulieren(){}

ostream& operator<<(ostream& o, Simulationsobject& simulationsobject){
	simulationsobject.vAusgeben(o);
	return o;
}



