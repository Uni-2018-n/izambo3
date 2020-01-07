#include "classes.h"

//#define DEBUG

int Object::temp_id=0;

///////////////////////////////////////Object
Object::Object(){
	id= temp_id++;
	#ifndef DEBUG
	cout << "Object just Created!" << endl;
	#endif
}

Object::~Object(){
	#ifndef DEBUG
	cout << "Object just destroyed!" << endl;
	#endif
}

String Object::toString(){
	String temp("Object, id= " + to_string(id) + ", ");
	return temp;
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

void Object::clone(Object& sec){
	temp_id=sec.temp_id;
	id=sec.id;
}

///////////////////////////////////////String
String::String(string temp):
txt(temp){
	#ifndef DEBUG
	//cout << "String just Created!" << endl;
	#endif
}

String::~String(){
	#ifndef DEBUG
	//cout << "String just destroyed!" << endl;
	#endif
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

string String::get_txt(){
	return txt;
}

///////////////////////////////////////Employee
Employee::Employee(String nam):
name(nam){
	#ifndef DEBUG
	cout << "Employee just created";
	#endif
	cout << " Employee ID: " << get_id() << endl;
}

Employee::~Employee(){
	#ifndef DEBUG
	cout << "Employee to be destroyed" << endl;
	#endif
}

String Employee::toString(){
	String temp(Object::toString().get_txt() + "Employee, " + name.get_txt() + " , ");
	return temp;
}

bool Employee::equal(Employee& sec){
	if(Object::equal(sec)){
		if(name.get_txt() ==sec.name.get_txt()){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}

void Employee::clone(Employee& sec){
	Object::clone(sec);
	name = sec.name;
}

///////////////////////////////////////SecurityEmployee
SecurityEmployee::SecurityEmployee(String nam):
Employee(nam){
	#ifndef DEBUG
	cout << "SecurityEmployee just created" << endl;
	#endif
}

SecurityEmployee::~SecurityEmployee(){
	#ifndef DEBUG
	cout << "SecurityEmployee to be destroyed" << endl;
	#endif
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

String SecurityEmployee::toString(){
	String temp(Employee::toString().get_txt() + "SecurityEmployee");
	return temp;
}

bool SecurityEmployee::equal(SecurityEmployee& sec){
	if(Employee::equal(sec)){
		return true;
	}else{
		return false;
	}
}

void SecurityEmployee::clone(SecurityEmployee& sec){
	Employee::clone(sec);
}

///////////////////////////////////////MaintenanceEmployee
MaintenanceEmployee::MaintenanceEmployee(String nam):
Employee(nam){
	#ifndef DEBUG
	cout << "MaintenanceEmployee just created" << endl;
	#endif
}

MaintenanceEmployee::~MaintenanceEmployee(){
	#ifndef DEBUG
	cout << "MaintenanceEmployee to be destroyed" << endl;
	#endif
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

String MaintenanceEmployee::toString(){
	String temp(Employee::toString().get_txt() + "MaintenanceEmployee");
	return temp;
}

bool MaintenanceEmployee::equal(MaintenanceEmployee& sec){
	if(Employee::equal(sec)){
		return true;
	}else{
		return false;
	}
}

void MaintenanceEmployee::clone(MaintenanceEmployee& sec){
	Employee::clone(sec);
}
///////////////////////////////////////CleaningEployee
CleaningEployee::CleaningEployee(String nam):
Employee(nam){
	#ifndef DEBUG
	cout << "CleaningEployee just created" << endl;
	#endif
}

CleaningEployee::~CleaningEployee(){
	#ifndef DEBUG
	cout << "CleaningEployee to be destroyed" << endl;
	#endif
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

String CleaningEployee::toString(){
	String temp(Employee::toString().get_txt() + "CleaningEployee");
	return temp;
}

bool CleaningEployee::equal(CleaningEployee& sec){
	if(Employee::equal(sec)){
		return true;
	}else{
		return false;
	}
}

void CleaningEployee::clone(CleaningEployee& sec){
	Employee::clone(sec);
}

///////////////////////////////////////PlaneComponent
PlaneComponent::PlaneComponent(){
	#ifndef DEBUG
	cout << "PlaneComponent just created";
	#endif
	cout << " PlaneComponent ID: " << get_id() << endl;
}

PlaneComponent::~PlaneComponent(){
	#ifndef DEBUG
	cout << "PlaneComponent to be destroyed" << endl;
	#endif
}

String PlaneComponent::toString(){
	String temp(Object::toString().get_txt() + "PlaneComponent, ");
	return temp;
}

bool PlaneComponent::equal(PlaneComponent& sec){
	if(Object::equal(sec)){
		return true;
	}else{
		return false;
	}
}

void PlaneComponent::clone(PlaneComponent& sec){
	Object::clone(sec);
}

///////////////////////////////////////PassengerCompartment
PassengerCompartment::PassengerCompartment(){
	SecWorker= false;
	CleanWorker = false;
	#ifndef DEBUG
	cout << "PassengerCompartment just created" << endl;
	if(rand() % 3 == 0){
		cout << "Sub PassengerCompartment about to be created:" << endl;
		Sub_PassCompartment = new PassengerCompartment();
	}else{
		Sub_PassCompartment = NULL;
	}
	#endif
}

PassengerCompartment::~PassengerCompartment(){
	#ifndef DEBUG
	cout << "PassengerCompartment to be destroyed" << endl;
	#endif
	delete Sub_PassCompartment;
}

bool PassengerCompartment::ready_check(){
	if(Sub_PassCompartment != NULL){
		if(!(Sub_PassCompartment->ready_check())){
			return false;
		}
	}
	if(SecWorker && CleanWorker){
		//toString().print();
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

String PassengerCompartment::toString(){
	String temp(PlaneComponent::toString().get_txt() + "PassengerCompartment, ");
	if(SecWorker){
		String temp2("SecurityEmployee worked here, ");
		temp.concat(temp2);
	}else{
		String temp2("Need SecurityEmployee to work here, ");
		temp.concat(temp2);
	}
	if(CleanWorker){
		String temp2("CleaningEployee worked here, ");
		temp.concat(temp2);
	}else{
		String temp2("Need CleaningEployee to work here, ");
		temp.concat(temp2);
	}
	if(Sub_PassCompartment != NULL){
		String temp2("\n	{Sub_PassCompartment, " + Sub_PassCompartment->toString().get_txt() + "}");
		temp.concat(temp2);
	}else{
		String temp2("No Sub_PassCompartment.");
		temp.concat(temp2);
	}
	return temp;
}

void PassengerCompartment::process(SecurityEmployee& worker){
	if(Sub_PassCompartment != NULL){
		cout << "{Sub PassengerCompartment: ";
		worker.workOn(*Sub_PassCompartment);
		worker.report(*Sub_PassCompartment);
		cout << "}" << endl;
	}
	SecWorker= true;
}

void PassengerCompartment::process(CleaningEployee& worker){
	if(Sub_PassCompartment != NULL){
		cout << "{Sub PassengerCompartment: ";
		worker.workOn(*Sub_PassCompartment);
		worker.report(*Sub_PassCompartment);
		cout << "}" << endl;
	}
	CleanWorker=true;
}

bool PassengerCompartment::equal(PassengerCompartment& sec){
	if(PlaneComponent::equal(sec)){
		if(SecWorker == sec.SecWorker && CleanWorker == sec.CleanWorker){
			if(Sub_PassCompartment != NULL && sec.Sub_PassCompartment != NULL){
				return Sub_PassCompartment->equal(*(sec.Sub_PassCompartment));
			}else{
				return true;
			}
		}
	}
	return false;
}

void PassengerCompartment::clone(PassengerCompartment& sec){
	// if(Sub_PassCompartment != NULL && sec.Sub_PassCompartment != NULL){
	// 	Sub_PassCompartment->clone(*(sec.Sub_PassCompartment));
	// }else
	if(Sub_PassCompartment != NULL){
		delete Sub_PassCompartment;
	}
	if(sec.Sub_PassCompartment != NULL){
		Sub_PassCompartment= new PassengerCompartment;
		Sub_PassCompartment->clone(*(sec.Sub_PassCompartment));
	}
	SecWorker = sec.SecWorker;
	CleanWorker = sec.CleanWorker;
	PlaneComponent::clone(sec);
}

///////////////////////////////////////PrivateCompartment
PrivateCompartment::PrivateCompartment(){
	SecWorker= false;
	CleanWorker= false;
	#ifndef DEBUG
	cout << "PrivateCompartment just created" << endl;
	#endif
}

PrivateCompartment::~PrivateCompartment(){
	#ifndef DEBUG
	cout << "PrivateCompartment to be destroyed" << endl;
	#endif
}

bool PrivateCompartment::ready_check(){
	if(SecWorker && CleanWorker){
		//toString().print();
		cout << "PrivateCompartment OK!" << endl;
		return true;
	}else{
		return false;
	}
}

String PrivateCompartment::toString(){
	String temp(PlaneComponent::toString().get_txt() + "PrivateCompartment, ");
	if(SecWorker){
		String temp2("SecurityEmployee worked here, ");
		temp.concat(temp2);
	}else{
		String temp2("Need SecurityEmployee to work here, ");
		temp.concat(temp2);
	}
	if(CleanWorker){
		String temp2("CleaningEployee worked here. ");
		temp.concat(temp2);
	}else{
		String temp2("Need CleaningEployee to work here, ");
		temp.concat(temp2);
	}
	return temp;
}

void PrivateCompartment::process(SecurityEmployee& worker){
	SecWorker = true;
}

void PrivateCompartment::process(CleaningEployee& worker){
	CleanWorker = true;
}

bool PrivateCompartment::equal(PrivateCompartment& sec){
	if(PlaneComponent::equal(sec)){
		if(SecWorker == sec.SecWorker && CleanWorker == sec.CleanWorker){
			return true;
		}
	}
	return false;
}

void PrivateCompartment::clone(PrivateCompartment& sec){
	SecWorker = sec.SecWorker;
	CleanWorker = sec.CleanWorker;
	PlaneComponent::clone(sec);
}

///////////////////////////////////////EquipmentCompartment
EquipmentCompartment::EquipmentCompartment(){
	SecWorker= false;
	MaintWorker= false;
	#ifndef DEBUG
	cout << "EquipmentCompartment just created" << endl;
	#endif
}

EquipmentCompartment::~EquipmentCompartment(){
	#ifndef DEBUG
	cout << "EquipmentCompartment to be destroyed" << endl;
	#endif
}

bool EquipmentCompartment::ready_check(){
	if(SecWorker && MaintWorker){
		//toString().print();
		cout << "EquipmentCompartment OK!" << endl;
		return true;
	}else{
		return false;
	}
}

String EquipmentCompartment::toString(){
	String temp(PlaneComponent::toString().get_txt() + "EquipmentCompartment, ");
	if(SecWorker){
		String temp2("SecurityEmployee worked here, ");
		temp.concat(temp2);
	}else{
		String temp2("Need SecurityEmployee to work here, ");
		temp.concat(temp2);
	}
	if(MaintWorker){
		String temp2("MaintenanceEmployee worked here. ");
		temp.concat(temp2);
	}else{
		String temp2("Need MaintenanceEmployee to work here. ");
		temp.concat(temp2);
	}
	return temp;
}
void EquipmentCompartment::process(SecurityEmployee& worker){
	SecWorker= true;
}

void 	EquipmentCompartment::process(MaintenanceEmployee& worker){
	MaintWorker = true;
}

bool EquipmentCompartment::equal(EquipmentCompartment& sec){
	if(PlaneComponent::equal(sec)){
		if(SecWorker == sec.SecWorker && MaintWorker == sec.MaintWorker){
			return true;
		}
	}
	return false;
}

void EquipmentCompartment::clone(EquipmentCompartment& sec){
	SecWorker = sec.SecWorker;
	MaintWorker = sec.MaintWorker;
	PlaneComponent::clone(sec);
}

///////////////////////////////////////CargoBay
CargoBay::CargoBay(){
	SecWorker= false;
	CleanWorker= false;
	MaintWorker= false;
	#ifndef DEBUG
	cout << "CargoBay just created" << endl;
	cout << "Equipment_space is about to be created:" << endl;
	#endif
	equipment_space= new EquipmentCompartment();

}

CargoBay::~CargoBay(){
	#ifndef DEBUG
	cout << "CargoBay to be destroyed" << endl;
	#endif
	delete equipment_space;
}

bool CargoBay::ready_check(){
	if(equipment_space->ready_check()){
		if(SecWorker && CleanWorker && MaintWorker){
			//toString().print();
			cout << "CargoBay OK!" << endl;
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}

String CargoBay::toString(){
	String temp(PlaneComponent::toString().get_txt() + "CargoBay, ");

	if(SecWorker){
		String temp2("SecurityEmployee worked here, ");
		temp.concat(temp2);
	}else{
		String temp2("Need SecurityEmployee to work here, ");
		temp.concat(temp2);
	}
	if(CleanWorker){
		String temp2("CleaningEployee worked here, ");
		temp.concat(temp2);
	}else{
		String temp2("Need CleaningEployee to work here, ");
		temp.concat(temp2);
	}
	if(MaintWorker){
		String temp2("MaintenanceEmployee worked here. ");
		temp.concat(temp2);
	}else{
		String temp2("Need MaintenanceEmployee to work here. ");
		temp.concat(temp2);
	}
	String temp2("\n	{CargoBay's Equipment_space, " + equipment_space->toString().get_txt() + "}");
	temp.concat(temp2);
	return temp;
}

void CargoBay::process(SecurityEmployee& worker){
	cout << "Equipment_space of CargoBay: ";
	worker.workOn(*equipment_space);
	worker.report(*equipment_space);
	SecWorker = true;
}

void CargoBay::process(CleaningEployee& worker){
	CleanWorker = true;
}

void CargoBay::process(MaintenanceEmployee& worker){
	cout << "Equipment_space of CargoBay: ";
	worker.workOn(*equipment_space);
	worker.report(*equipment_space);
	MaintWorker = true;
}

bool CargoBay::equal(CargoBay& sec){
	if(PlaneComponent::equal(sec)){
		if(SecWorker == sec.SecWorker && CleanWorker == sec.CleanWorker && MaintWorker == sec.MaintWorker){
			if(equipment_space->equal(*(sec.equipment_space))){
				return true;
			}
		}
	}
	return false;
}

void CargoBay::clone(CargoBay& sec){
	equipment_space->clone(*(sec.equipment_space));
	SecWorker = sec.SecWorker;
	CleanWorker = sec.CleanWorker;
	MaintWorker = sec.MaintWorker;
	PlaneComponent::clone(sec);
}

///////////////////////////////////////Plane
Plane::Plane(String titl, int ma_pl):
title(titl), max_pl(ma_pl){
	#ifndef DEBUG
	cout << "Plane just created";
	#endif
	cout << " Plane with ID: " << get_id() << endl;
	cargo = new CargoBay();
	cout << "CARGOBAY DONE" << endl;
	e1= new EquipmentCompartment();
	cout << "E1 DONE" << endl;
	e2= new EquipmentCompartment();
	cout << "E2 DONE " << endl;
	e3= new EquipmentCompartment();
	cout << "E3 DONE" << endl;


	float temp = max_pl/75.0;
	if(temp == (int)temp){
		size_PassComp = (int)temp;
	}else{
		size_PassComp = ((int)temp)+ 1;
	}
	pl_PassComp= new PassengerCompartment*[size_PassComp];
	for(int i=0;i<size_PassComp;i++){
		pl_PassComp[i]= new PassengerCompartment;
		cout << "PASS COMPARTMENT DONE" << endl << endl << endl;
	}
}

Plane::~Plane(){
	delete cargo;
	delete e1;
	delete e2;
	delete e3;
	for(int i=0;i<size_PassComp;i++){
		delete pl_PassComp[i];
	}
	delete[] pl_PassComp;

	#ifndef DEBUG
	cout << "Plane to be destroyed" << endl;
	#endif
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
	// int temp=max_pl/50;
	for(int i=0;i<size_PassComp;i++){
		if(!pl_PassComp[i]->ready_check()){
			return false;
		}
	}
	return true;

}

String Plane::toString(){
	String temp(Object::toString().get_txt() +
	"Plane, title= " + title.get_txt() + ", max_pl= " + to_string(max_pl) + ", " +
	"Parts: \n" +
	cargo->toString().get_txt() + "\n" + e1->toString().get_txt() + "\n" + e2->toString().get_txt() + "\n" + e3->toString().get_txt());
	for(int i=0;i<size_PassComp;i++){
		String temp2("\n" + pl_PassComp[i]->toString().get_txt());
		temp.concat(temp2);
	}
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
	for(int i=0;i<size_PassComp;i++){
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
	for(int i=0;i<size_PassComp;i++){
		if(!pl_PassComp[i]->ready_check()){
			worker.workOn(*pl_PassComp[i]);
			worker.report(*pl_PassComp[i]);
		}
	}
}

bool Plane::equal(Plane& sec){
	if(title.get_txt() == sec.title.get_txt() && max_pl == sec.max_pl){
		if(cargo->equal(*(sec.cargo))){
			if(e1->equal(*(sec.e1)) && e2->equal(*(sec.e2)) && e3->equal(*(sec.e3))){
				for(int i=0;i<size_PassComp;i++){
					if(!(pl_PassComp[i]->equal(*(sec.pl_PassComp[i])))){
						return false;
					}
				}
				return true;
			}
		}
	}
	return false;
}

void Plane::clone(Plane& sec){
	title = sec.title;
	max_pl = sec.max_pl;
	for(int i=0;i<size_PassComp;i++){
		delete pl_PassComp[i];
	}
	delete[] pl_PassComp;
	size_PassComp = sec.size_PassComp;
	cargo->clone(*(sec.cargo));
	e1->clone(*(sec.e1));
	e2->clone(*(sec.e2));
	e3->clone(*(sec.e3));
	pl_PassComp = new PassengerCompartment*[size_PassComp];
	for(int i=0;i<size_PassComp;i++){
		pl_PassComp[i] = new PassengerCompartment;
		pl_PassComp[i]->clone(*(sec.pl_PassComp[i]));
	}
	Object::clone(sec);
}
