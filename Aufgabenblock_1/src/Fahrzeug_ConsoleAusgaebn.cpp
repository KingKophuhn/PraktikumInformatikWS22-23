

#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrraeder.h"

using namespace std;

void Fahrzeug::vKopf(){
	//cout << "ID\tName\tMaxGschwingdigkeit\tGesamtStrecke";
	cout << resetiosflags(ios::left) << "ID" << right <<
							setw(14) << "Name" <<
							setw(28) << "MaxGeschwindigkeit" <<
							setw(25) << "Geschwindigkeit" <<
							setw(23) << "Gesamtstrecke" <<
							setw(25)<< "Gesamtverbrauch" <<
							setw(20) << "Tankinhalt\n" <<
							setfill('-')<< setw(136)<<""<< endl; //setfill(' ') wieder auf den standarf füller stellen?
}

void Fahrzeug::vAusgeben(){
	/*cout << to_string(p_iID)+"\t"+p_sName+"\t\t"+to_string(p_dMaxGeschwindigkeit)+"\t"+to_string(p_dGesamtStrecke);*/
	cout << resetiosflags(ios::right) <<
			setw(0) << this->p_iID <<
			setw(14) << this->p_sName <<
			setw(28) << this->p_dMaxGeschwindigkeit <<
			setw(25)<< this->dGeschwindigkeit() <<
			setw(23) << this->p_dGesamtStrecke ; //<<
			//setw(25) << "0" << setw(20)<< "0";
}

void Fahrzeug::vAusgeben(ostream& o){
	o << setiosflags(ios::right)
		<< setw(6) << this->p_iID
		<< setw(10) << this->p_sName
		<< setw(20) << this->p_dMaxGeschwindigkeit
		<< setw(26) << this->dGeschwindigkeit()
		<< setw(26) << this->p_dGesamtStrecke;
}

void PKW::vAusgeben(){
	Fahrzeug::vAusgeben();
	cout << setw(25) << p_dGesamtStrecke* p_dVerbrauch/ 100 << setw(20) << p_dTankinhalt;
}

void PKW::vAusgeben(ostream& o){
	Fahrzeug::vAusgeben(o);
	o << setw(25) << p_dGesamtStrecke* p_dVerbrauch/ 100 << setw(20) << p_dTankinhalt; //klappt nicht bei der vAufgabe_3()!!
}

void Fahrraeder::vAusgeben(){
	Fahrzeug::vAusgeben();
	cout <<setw(25) << "--" << setw(20)<< "--";
}

void Fahrraeder::vAusgeben(ostream& o){
	Fahrzeug::vAusgeben(o);
	o <<setw(25) << "--" << setw(20)<< "--";
}



void Fahrzeug::printId() {
	cout << this->p_iID << endl;
}
