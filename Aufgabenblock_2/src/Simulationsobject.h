/*
 * Simulationsobject.h
 *
 *  Created on: 09.01.2023
 *      Author: mickey
 */

#ifndef SRC_SIMULATIONSOBJECT_H_
#define SRC_SIMULATIONSOBJECT_H_
#pragma once
#include <string>
#include<iomanip>
#include <iostream>
#include <limits>
using namespace std;

class Simulationsobject {
private:
	static int p_MaxID; // Hochzählende ID variable (int)
protected:
	string p_sName;
	const int p_iID;
	int generateId();
	double p_dZeit=0;

	bool p_bdeleteMsg=false;
	bool p_bcreateMsg=false;

public:



	Simulationsobject();
	Simulationsobject(string name,bool createMsg=false,bool deleteMsg=false);
	Simulationsobject(Simulationsobject &simulationsobject)= delete;
	virtual ~Simulationsobject();

	virtual void vAusgeben();
	virtual void vSimulieren();

	virtual void vAusgeben(ostream&);


	string getName() const	{return p_sName;}

	//Simulationsobject operator == ();
};

#endif /* SRC_SIMULATIONSOBJECT_H_ */
ostream& operator<<(ostream&, Simulationsobject& simulationsobject);
