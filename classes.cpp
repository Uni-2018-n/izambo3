#include "classes.h"


string Object::toString(){
	return id + " ";
}

///////////////////////////////////////String
String::String(string temp):
txt(temp){

}

int String::length(){
	return txt.length();
}

void String::clear(){
	txt.clear();
}

void String::concat(String sec){
	txt = txt+ sec.txt;
}

char String::at(int pos){
	return txt[pos];
}

void String::updateAt(int pos, char rep){
	txt[pos]=rep;
}

void String::print(){
	cout << txt << endl;
}



///////////////////////////////////////Employee
Employee::Employee(){
	cout << "Employee just created" << endl;
}

Employee::~Employee(){
	cout << "Employee to be destroyed" << endl;
}

void Employee::workOn(){

}
bool Employee::report(){
	return false;
}
///////////////////////////////////////SecurityEmployee
SecurityEmployee::SecurityEmployee(){
	cout << "SecurityEmployee just created" << endl;
}

SecurityEmployee::~SecurityEmployee(){
	cout << "SecurityEmployee to be destroyed" << endl;
}

///////////////////////////////////////MaintenanceEmployee
MaintenanceEmployee::MaintenanceEmployee(){
	cout << "MaintenanceEmployee just created" << endl;
}

MaintenanceEmployee::~MaintenanceEmployee(){
	cout << "MaintenanceEmployee to be destroyed" << endl;
}

///////////////////////////////////////CleaningEployee
CleaningEployee::CleaningEployee(){
	cout << "CleaningEployee just created" << endl;
}

CleaningEployee::~CleaningEployee(){
	cout << "CleaningEployee to be destroyed" << endl;
}

///////////////////////////////////////PlaneComponent
PlaneComponent::PlaneComponent(){
	cout << "PlaneComponent just created" << endl;
}

PlaneComponent::~PlaneComponent(){
	cout << "PlaneComponent to be destroyed" << endl;
}


///////////////////////////////////////PassengerCompartment
PassengerCompartment::PassengerCompartment(){
	Sub_PassCompartment = NULL;
	SecWorker= false;
	CleanWorker = false;
	cout << "PassengerCompartment just created" << endl;
}

PassengerCompartment::~PassengerCompartment(){
	cout << "PassengerCompartment to be destroyed" << endl;
}

bool PassengerCompartment::ready_check(){ //TIS READY_CHECK PREPEI NA PERASOUN OLOI GIA NA EINAI READY
	if(SecWorker && CleanWorker){
		//toString();
		cout << "PassengerCompartment OK!" << endl;
		if(Sub_PassCompartment != NULL)
		cout << "Sub: ";
		Sub_PassCompartment->ready_check();
		return true;
	}else{
		return false;
	}
}

void PassengerCompartment::process(SecurityEmployee worker){
	SecWorker= true;
}

void PassengerCompartment::process(CleaningEployee worker){
	CleanWorker=true;
}

///////////////////////////////////////PrivateCompartment
PrivateCompartment::PrivateCompartment(){
	SecWorker= false;
	CleanWorker= false;
	cout << "PrivateCompartment just created" << endl;
}

PrivateCompartment::~PrivateCompartment(){
	cout << "PrivateCompartment to be destroyed" << endl;
}

bool PrivateCompartment::ready_check(){
	if(SecWorker && CleanWorker){
		//toString();
		cout << "PrivateCompartment OK!" << endl;
		return true;
	}else{
		return false;
	}
}

void PrivateCompartment::process(SecurityEmployee worker){
	SecWorker = true;
}

void PrivateCompartment::process(CleaningEployee worker){
	CleanWorker = true;
}

///////////////////////////////////////EquipmentCompartment
EquipmentCompartment::EquipmentCompartment(){
	SecWorker= false;
	MaintWorker= false;
	cout << "EquipmentCompartment just created" << endl;
}

EquipmentCompartment::~EquipmentCompartment(){
	cout << "EquipmentCompartment to be destroyed" << endl;
}

bool EquipmentCompartment::ready_check(){
	if(SecWorker && MaintWorker){
		//toString();
		cout << "EquipmentCompartment OK!" << endl;
		return true;
	}else{
		return false;
	}
}

void EquipmentCompartment::process(SecurityEmployee worker){
	SecWorker= true;
}

void 	EquipmentCompartment::process(MaintenanceEmployee worker){
	MaintWorker = true;
}

///////////////////////////////////////CargoBay
CargoBay::CargoBay(){
	SecWorker= false;
	CleanWorker= false;
	MaintWorker= false;
	cout << "CargoBay just created" << endl;
}

CargoBay::~CargoBay(){
	cout << "CargoBay to be destroyed";
}

bool CargoBay::ready_check(){
	if(SecWorker && CleanWorker && MaintWorker){
		//toString();
		cout << "CargoBay OK!" << endl;
		return true;
	}else{
		return false;
	}
}

void CargoBay::process(SecurityEmployee worker){
	SecWorker = true;
}

void CargoBay::process(CleaningEployee worker){
	CleanWorker = true;
}

void CargoBay::process(MaintenanceEmployee worker){
	MaintWorker = true;
}


///////////////////////////////////////Plane
Plane::Plane(string titl, int cur_pl, int ma_pl):
title(titl), max_pl(ma_pl), curr_pl(cur_pl){
	cout << "Plane just created" << endl;
}

Plane::~Plane(){
	cout << "Plane to be destroyed" << endl;
}
