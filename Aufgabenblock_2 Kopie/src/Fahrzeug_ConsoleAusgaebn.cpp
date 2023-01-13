#include "Fahrzeug.h"
#include "PKW.h"
#include "Fahrraeder.h"
#include "Simulationsobject.h"
#include "Weg.h"

using namespace std;

void Simulationsobject::vAusgeben(){
	cout << resetiosflags(ios::right) <<
				setw(0) << this->p_iID <<
				setw(14) << this->p_sName ;
}

void Simulationsobject::vAusgeben(ostream& o){
	o << setiosflags(ios::right)
		<< setw(0) << this->p_iID
		<< setw(14) << this->p_sName;
}

//-------------------------------------------

void Weg::vKopf(){
	cout << resetiosflags(ios::left) << "ID" << right <<
								setw(14) << "Name" <<
								setw(14) << "Laenge" <<
								setw(20) << "Fahrzeuge" <<endl<<
								setfill('-')<< setw(80)<<""<<setfill(' ')<< endl;
}

void Weg::vAusgaben(){
	string fahrzeugNames;
	list<int> numbersss = {1,4,5,8};
	for(auto i : numbersss){ //list test
		cout << i<<endl;
	}
	for (auto const& i : p_pFahrzeuge) {
				fahrzeugNames+=i.get()->getName()+" "; //namen aller fahrzeuge zusammen in einen string
		}
	Simulationsobject::vAusgeben();
	cout<<setw(12)<< p_dLanenge<<setw(14)<<"("<<fahrzeugNames<<")";
}

void Weg::vAusgeben(ostream& o){
	string fahrzeugNames;

	for (auto const& i : p_pFahrzeuge) {
			fahrzeugNames+=i.get()->getName()+" "; //namen aller fahrzeuge zusammen in einen string
	}
	Simulationsobject::vAusgeben(o);
	cout<<setw(12)<< p_dLanenge<<setw(14)<<"("<<fahrzeugNames<<")";
}

//---------------------

void Fahrzeug::vKopf(){
	//cout << "ID\tName\tMaxGschwingdigkeit\tGesamtStrecke";
	cout << resetiosflags(ios::left) << "ID" << right <<
							setw(14) << "Name" <<
							setw(28) << "MaxGeschwindigkeit" <<
							setw(25) << "Geschwindigkeit" <<
							setw(23) << "Gesamtstrecke" <<
							setw(25)<< "Gesamtverbrauch" <<
							setw(20) << "Tankinhalt\n" <<
							setfill('-')<< setw(136)<<""<< endl<<setfill(' '); //setfill(' ') wieder auf den standarf füller stellen?
}

void Fahrzeug::vAusgeben(){
	/*cout << to_string(p_iID)+"\t"+p_sName+"\t\t"+to_string(p_dMaxGeschwindigkeit)+"\t"+to_string(p_dGesamtStrecke);*/
	Simulationsobject::vAusgeben();
	cout << setw(28) << this->p_dMaxGeschwindigkeit <<
			setw(25)<< this->dGeschwindigkeit() <<
			setw(23) << this->p_dGesamtStrecke ; //<<
			//setw(25) << "0" << setw(20)<< "0";
}

void Fahrzeug::vAusgeben(ostream& o){
	Simulationsobject::vAusgeben(o);
	o	<< setw(20) << this->p_dMaxGeschwindigkeit
		<< setw(26) << this->dGeschwindigkeit()
		<< setw(26) << this->p_dGesamtStrecke;
}

//------------------

void PKW::vAusgeben(){
	Fahrzeug::vAusgeben();
	cout << setw(25) << p_dGesamtStrecke* p_dVerbrauch/ 100 << setw(20) << p_dTankinhalt;
}

void PKW::vAusgeben(ostream& o){
	Fahrzeug::vAusgeben(o);
	o << setw(25) << p_dGesamtStrecke* p_dVerbrauch/ 100 << setw(20) << p_dTankinhalt; //klappt nicht bei der vAufgabe_3()!!
}

//------------------------

void Fahrraeder::vAusgeben(){
	Fahrzeug::vAusgeben();
	cout <<setw(25) << "--" << setw(20)<< "--";
}

void Fahrraeder::vAusgeben(ostream& o){
	Fahrzeug::vAusgeben(o);
	o <<setw(25) << "--" << setw(20)<< "--";
}

//------------------------


void Fahrzeug::printId() {
	cout << this->p_iID << endl;
}
