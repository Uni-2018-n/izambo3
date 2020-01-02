#include "classes.h"

int Object::temp_id=0;

///////////////////////////////////////Object
Object::Object(){
	id= temp_id++;
	cout << "Object just Created!" << endl;
}

Object::~Object(){
	cout << "Object just destroyed!" << endl;
}

string Object::toString(){
	return "Object, id= " + to_string(id) + ", ";
}


int Object::get_id(){
	return id;
}

bool Object::equal(Object& sec){
	if(id == sec.id){
		return true;
	}else{
		return false;
	}
}

bool Object::identical(Object& sec){
	if(this == &sec){
		return true;
	}else{
		return false;
	}
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
Employee::Employee(string nam):
name(nam){
	cout << "Employee just created";
	cout << " Employee ID: " << get_id() << endl;
}

Employee::~Employee(){
	cout << "Employee to be destroyed" << endl;
}

string Employee::toString(){
	string temp;
	temp = temp + Object::toString();
	temp = temp + "Employee, " + name + " , ";

	return temp;
}

///////////////////////////////////////SecurityEmployee
SecurityEmployee::SecurityEmployee(string nam):
Employee(nam){
	cout << "SecurityEmployee just created" << endl;
}

SecurityEmployee::~SecurityEmployee(){
	cout << "SecurityEmployee to be destroyed" << endl;
}

void SecurityEmployee::workOn(CargoBay& work_place){
	cout << "I SecurityEmployee, started working into a Cargo Bay" << endl;
	work_place.process(*this);
}
void SecurityEmployee:: workOn(EquipmentCompartment& work_place){
	cout << "I SecurityEmployee, started working into a Equipment Compartment" << endl;
	work_place.process(*this);
}
void SecurityEmployee::workOn(PassengerCompartment& work_place){
	cout << "I SecurityEmployee, started working into a Passenger Compartment" << endl;
	work_place.process(*this);
}

void SecurityEmployee::report(CargoBay& work_place){
	cout << "SecurityEmployee keep working on CargoBay" << endl;
}
void SecurityEmployee::report(EquipmentCompartment& work_place){
	cout << "SecurityEmployee keep working on EquipmentCompartment" << endl;
}

void SecurityEmployee::report(PassengerCompartment& work_place){
	cout << "SecurityEmployee keep working on PassengerCompartment" << endl;
}

string SecurityEmployee::toString(){
	string temp;
	temp = temp + Employee::toString();
	temp = temp + "SecurityEmployee";
	return temp;
}
///////////////////////////////////////MaintenanceEmployee
MaintenanceEmployee::MaintenanceEmployee(string nam):
Employee(nam){
	cout << "MaintenanceEmployee just created" << endl;
}

MaintenanceEmployee::~MaintenanceEmployee(){
	cout << "MaintenanceEmployee to be destroyed" << endl;
}

void MaintenanceEmployee:: workOn(CargoBay& work_place){
	cout << "I MaintenanceEmployee, started working into a Cargo Bay" << endl;
	work_place.process(*this);
}
void MaintenanceEmployee::workOn(EquipmentCompartment& work_place){
	cout << "I MaintenanceEmployee, started working into a Equipment Compartment" << endl;
	work_place.process(*this);
}

void MaintenanceEmployee::report(CargoBay& work_place){
	cout << "MaintenanceEmployee keep working on CargoBay" << endl;
}
void MaintenanceEmployee::report(EquipmentCompartment& work_place){
	cout << "MaintenanceEmployee keep working on EquipmentCompartment" << endl;
}

string MaintenanceEmployee::toString(){
	string temp;
	temp = temp + Employee::toString();
	temp = temp + "MaintenanceEmployee";
	return temp;
}

///////////////////////////////////////CleaningEployee
CleaningEployee::CleaningEployee(string nam):
Employee(nam){
	cout << "CleaningEployee just created" << endl;
}

CleaningEployee::~CleaningEployee(){
	cout << "CleaningEployee to be destroyed" << endl;
}

void CleaningEployee:: workOn(CargoBay& work_place){
	cout << "I CleaningEployee, started working into a Cargo Bay" << endl;
	work_place.process(*this);
}
void CleaningEployee::workOn(PassengerCompartment& work_place){
	cout << "I CleaningEployee, started working into a Passenger Compartment" << endl;
	work_place.process(*this);
}

void CleaningEployee::report(CargoBay& work_place){
	cout << "CleaningEployee keep working on CargoBay" << endl;
}
void CleaningEployee::report(PassengerCompartment& work_place){

	cout << "CleaningEployee keep working on PassengerCompartment" << endl;
}

string CleaningEployee::toString(){
	string temp;
	temp = temp + Employee::toString();
	temp = temp + "CleaningEployee";
	return temp;
}

///////////////////////////////////////PlaneComponent
PlaneComponent::PlaneComponent(){
	cout << "PlaneComponent just created";
	cout << " PlaneComponent ID: " << get_id() << endl;
}

PlaneComponent::~PlaneComponent(){
	cout << "PlaneComponent to be destroyed" << endl;
}

string PlaneComponent::toString(){
	string temp;
	temp = temp + Object::toString();
	temp = temp + "PlaneComponent, ";
	return temp;
}

///////////////////////////////////////PassengerCompartment
PassengerCompartment::PassengerCompartment(){
	Sub_PassCompartment = NULL;//TODO make this 50/50 chance
	SecWorker= false;
	CleanWorker = false;
	cout << "PassengerCompartment just created" << endl;
}

PassengerCompartment::~PassengerCompartment(){
	cout << "PassengerCompartment to be destroyed" << endl;
}

bool PassengerCompartment::ready_check(){
	if(SecWorker && CleanWorker){
		cout << toString() << endl;
		cout << "PassengerCompartment OK!" << endl;
		if(Sub_PassCompartment != NULL){
			cout << "Sub: ";
			Sub_PassCompartment->ready_check();
		}
		return true;
	}else{
		return false;
	}
}

string PassengerCompartment::toString(){
	string temp;
	temp = temp + PlaneComponent::toString();

	temp = temp + "PassengerCompartment, ";
	if(SecWorker){
		temp = temp + "SecurityEmployee worked here, ";
	}else{
		temp = temp + "Need SecurityEmployee to work here, ";
	}
	if(CleanWorker){
		temp = temp + "CleaningEployee worked here, ";
	}else{
		temp = temp + "Need CleaningEployee to work here, ";
	}
	if(Sub_PassCompartment != NULL){
		temp = temp + "Sub_PassCompartment, ";
		temp = temp + Sub_PassCompartment->toString();
	}else{
		temp = temp + "No Sub_PassCompartment. ";
	}
	return temp;
}

void PassengerCompartment::process(SecurityEmployee& worker){
	SecWorker= true;
}

void PassengerCompartment::process(CleaningEployee& worker){
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
		cout << toString() << endl;
		cout << "PrivateCompartment OK!" << endl;
		return true;
	}else{
		return false;
	}
}

string PrivateCompartment::toString(){
	string temp;
	temp = temp + PlaneComponent::toString();

	temp =temp + "PrivateCompartment, ";
	if(SecWorker){
		temp = temp + "SecurityEmployee worked here, ";
	}else{
		temp = temp + "Need SecurityEmployee to work here, ";
	}
	if(CleanWorker){
		temp = temp + "CleaningEployee worked here. ";
	}else{
		temp = temp + "Need CleaningEployee to work here. ";
	}
	return temp;
}

void PrivateCompartment::process(SecurityEmployee& worker){
	SecWorker = true;
}

void PrivateCompartment::process(CleaningEployee& worker){
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
		cout << toString() << endl;
		cout << "EquipmentCompartment OK!" << endl;
		return true;
	}else{
		return false;
	}
}

string EquipmentCompartment::toString(){
	string temp;
	temp = temp + PlaneComponent::toString();

	temp =temp + "EquipmentCompartment, ";
	if(SecWorker){
		temp = temp + "SecurityEmployee worked here, ";
	}else{
		temp = temp + "Need SecurityEmployee to work here, ";
	}
	if(MaintWorker){
		temp = temp + "MaintenanceEmployee worked here. ";
	}else{
		temp = temp + "Need MaintenanceEmployee to work here. ";
	}
	return temp;
}
void EquipmentCompartment::process(SecurityEmployee& worker){
	SecWorker= true;
}

void 	EquipmentCompartment::process(MaintenanceEmployee& worker){
	MaintWorker = true;
}

///////////////////////////////////////CargoBay
CargoBay::CargoBay(){
	SecWorker= false;
	CleanWorker= false;
	MaintWorker= false;
	cout << "CargoBay just created" << endl;
	cout<< "creating equipment_space" << endl;
	equipment_space= new EquipmentCompartment();
	cout << "equipment_space created" << endl;
}

CargoBay::~CargoBay(){
	cout << "CargoBay to be destroyed" << endl;;
}

bool CargoBay::ready_check(){
	if(SecWorker && CleanWorker && MaintWorker){
		cout << toString() << endl;
		cout << "CargoBay OK!" << endl;
		return true;
	}else{
		return false;
	}
}

string CargoBay::toString(){
	string temp;
	temp = temp + PlaneComponent::toString();

	temp =temp + "CargoBay, ";
	if(SecWorker){
		temp = temp + "SecurityEmployee worked here, ";
	}else{
		temp = temp + "Need SecurityEmployee to work here, ";
	}
	if(CleanWorker){
		temp = temp + "CleaningEployee worked here, ";
	}else{
		temp = temp + "Need CleaningEployee to work here, ";
	}
	if(MaintWorker){
		temp = temp + "MaintenanceEmployee worked here. ";
	}else{
		temp = temp + "Need MaintenanceEmployee to work here. ";
	}
	return temp;
}

void CargoBay::process(SecurityEmployee& worker){
	SecWorker = true;
}

void CargoBay::process(CleaningEployee& worker){
	CleanWorker = true;
}

void CargoBay::process(MaintenanceEmployee& worker){
	MaintWorker = true;
}


///////////////////////////////////////Plane
Plane::Plane(string titl, int ma_pl):
title(titl), max_pl(ma_pl){
	cout << "Plane just created";
	cout << " Plane with ID: " << get_id() << endl;
	cargo = new CargoBay();
	e1= new EquipmentCompartment();
	e2= new EquipmentCompartment();
	e3= new EquipmentCompartment();

	if(max_pl % 10 == 0){
		pl_PassComp= new PassengerCompartment*[max_pl/50];
		for(int i=0;i<max_pl/50;i++){
			pl_PassComp[i]= new PassengerCompartment;
		}
	}
}

Plane::~Plane(){
	delete cargo;
	delete e1;
	delete e2;
	delete e3;
	for(int i=0;i<max_pl/50;i++){
		delete pl_PassComp[i];
	}
	delete[] pl_PassComp;

	cout << "Plane to be destroyed" << endl;
}

bool Plane::ready_check(){
	if(!cargo->ready_check()){
		return false;
	}
	if(!e1->ready_check()){
		return false;
	}
	if(!e2->ready_check()){
		return false;
	}
	if(!e3->ready_check()){
			return false;
	}
	int temp=max_pl/50;
	for(int i=0;i<temp;i++){
		if(!pl_PassComp[i]->ready_check()){
			return false;
		}
	}
	return true;

}

string Plane::toString(){
	string temp;
	temp = Object::toString();
	temp = temp + "Plane, title= " + title + ", max_pl= " + to_string(max_pl) + ", ";
	temp = temp + "Parts: {";
	temp = temp + cargo->toString() + "\n" + e1->toString() + "\n" + e2->toString() + "\n" + e3->toString();
	for(int i=0;i<4;i++){
		temp = temp + "\n" + pl_PassComp[i]->toString();
	}
	temp = temp + "}";

	return temp;
}

void Plane::process(SecurityEmployee& worker){//explain oti apo to lists
	if(!cargo->ready_check()){
		worker.workOn(*cargo);
		worker.report(*cargo);
	}
	if(!e1->ready_check()){
		worker.workOn(*e1);
		worker.report(*e1);
	}
	if(!e2->ready_check()){
		worker.workOn(*e2);
		worker.report(*e2);
	}
	if(!e3->ready_check()){
		worker.workOn(*e3);
		worker.report(*e3);
	}
	for(int i=0;i<4;i++){
		if(!pl_PassComp[i]->ready_check()){
			worker.workOn(*pl_PassComp[i]);
			worker.report(*pl_PassComp[i]);
		}
	}
}

void Plane::process(MaintenanceEmployee& worker){
	if(!cargo->ready_check()){
		worker.workOn(*cargo);
		worker.report(*cargo);
	}
	if(!e1->ready_check()){
		worker.workOn(*e1);
		worker.report(*e1);
	}
	if(!e2->ready_check()){
		worker.workOn(*e2);
		worker.report(*e2);
	}
	if(!e3->ready_check()){
		worker.workOn(*e3);
		worker.report(*e3);
	}
}
void Plane::process(CleaningEployee& worker){
	if(!cargo->ready_check()){
		worker.workOn(*cargo);
		worker.report(*cargo);
	}
	for(int i=0;i<4;i++){
		if(!pl_PassComp[i]->ready_check()){
			worker.workOn(*pl_PassComp[i]);
			worker.report(*pl_PassComp[i]);
		}
	}
}
