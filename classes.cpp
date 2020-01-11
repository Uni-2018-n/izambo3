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

String Object::toString()const{
	String temp("Object, id= " + to_string(id) + ", ");
	return temp;
}


int Object::get_id()const{
	return id;
}

bool Object::equal(const Object& sec)const{
	if(id == sec.id){
		return true;
	}else{
		return false;
	}
}

bool Object::identical(const Object& sec)const{
	if(this == &sec){
		return true;
	}else{
		return false;
	}
}

///////////////////////////////////////String
String* String::clone()const{
	String* temp= new String(txt);
	//temp->id= id;
	return temp;
}


String::String(const string temp):
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

int String::length()const{
	return txt.length();
}

void String::clear(){
	txt.clear();
}

void String::concat(const String sec){
	txt = txt+ sec.txt;
}

void String::concat(const string sec){
	txt=txt + sec;
}

char String::at(int pos)const{
	return txt[pos];
}

void String::updateAt(const int pos, const char rep){
	txt[pos]=rep;
}

void String::print()const{
	cout << txt << endl;
}

string String::get_txt()const{
	return txt;
}


// String String::toString(){
// 	String temp(Object::toString().get_txt() + " String, txt=" + txt);
// 	return temp;
// }

///////////////////////////////////////Employee
Employee::Employee(){
	#ifndef DEBUG
	cout << "Employee just created ";
	#endif
	cout << "Employee ID: " << get_id() << endl;
}

Employee::~Employee(){
	delete name;
	#ifndef DEBUG
	cout << "Employee to be destroyed" << endl;
	#endif
}

String Employee::toString()const{
	String temp(Object::toString().get_txt() + "Employee, " + name->get_txt() + " , ");
	return temp;
}

bool Employee::equal(const Employee& sec)const{
	if(Object::equal(sec)){
		if(name->get_txt() ==sec.name->get_txt()){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}

///////////////////////////////////////SecurityEmployee
SecurityEmployee::SecurityEmployee(const String& nam){
	name= nam.clone();
	#ifndef DEBUG
	cout << "SecurityEmployee just created " << endl;
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

void SecurityEmployee::report(const CargoBay& work_place)const{
	cout << "SecurityEmployee keep working on CargoBay" << endl;
}
void SecurityEmployee::report(const EquipmentCompartment& work_place)const{
	cout << "SecurityEmployee keep working on EquipmentCompartment" << endl;
}

void SecurityEmployee::report(const PassengerCompartment& work_place)const{
	cout << "SecurityEmployee keep working on PassengerCompartment" << endl;
}

String SecurityEmployee::toString()const{
	String temp(Employee::toString().get_txt() + "SecurityEmployee");
	return temp;
}

bool SecurityEmployee::equal(const SecurityEmployee& sec)const{
	if(Employee::equal(sec)){
		return true;
	}else{
		return false;
	}
}

SecurityEmployee* SecurityEmployee::clone()const{
	SecurityEmployee* temp= new SecurityEmployee(*name);
	temp->id= id;
	return temp;
}

///////////////////////////////////////MaintenanceEmployee
MaintenanceEmployee::MaintenanceEmployee(const String& nam){
	name= nam.clone();
	#ifndef DEBUG
	cout << "MaintenanceEmployee just created " << endl;
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

void MaintenanceEmployee::report(const CargoBay& work_place){
	cout << "MaintenanceEmployee keep working on CargoBay" << endl;
}
void MaintenanceEmployee::report(const EquipmentCompartment& work_place){
	cout << "MaintenanceEmployee keep working on EquipmentCompartment" << endl;
}

String MaintenanceEmployee::toString()const{
	String temp(Employee::toString().get_txt() + "MaintenanceEmployee");
	return temp;
}

bool MaintenanceEmployee::equal(const MaintenanceEmployee& sec)const{
	if(Employee::equal(sec)){
		return true;
	}else{
		return false;
	}
}

MaintenanceEmployee* MaintenanceEmployee::clone()const{
	MaintenanceEmployee* temp = new MaintenanceEmployee(*name);
	temp->id=id;
	return temp;
}
///////////////////////////////////////CleaningEployee
CleaningEployee::CleaningEployee(const String nam){
	name= nam.clone();
	#ifndef DEBUG
	cout << "CleaningEployee just created " << endl;
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

void CleaningEployee::report(const CargoBay& work_place)const{
	cout << "CleaningEployee keep working on CargoBay" << endl;
}

void CleaningEployee::report(const PassengerCompartment& work_place)const{
	cout << "CleaningEployee keep working on PassengerCompartment" << endl;
}

String CleaningEployee::toString()const{
	String temp(Employee::toString().get_txt() + "CleaningEployee");
	return temp;
}

bool CleaningEployee::equal(const CleaningEployee& sec)const{
	if(Employee::equal(sec)){
		return true;
	}else{
		return false;
	}
}

CleaningEployee* CleaningEployee::clone()const{
	CleaningEployee* temp= new CleaningEployee(*name);
	temp->id=id;
	return temp;
}

///////////////////////////////////////PlaneComponent
PlaneComponent::PlaneComponent(){
	#ifndef DEBUG
	cout << "PlaneComponent just created ";
	#endif
	cout << "PlaneComponent ID: " << get_id() << endl;
}

PlaneComponent::~PlaneComponent(){
	#ifndef DEBUG
	cout << "PlaneComponent to be destroyed" << endl;
	#endif
}

String PlaneComponent::toString()const{
	String temp(Object::toString().get_txt() + "PlaneComponent, ");
	return temp;
}

bool PlaneComponent::equal(const PlaneComponent& sec)const{
	if(Object::equal(sec)){
		return true;
	}else{
		return false;
	}
}

///////////////////////////////////////PassengerCompartment
PassengerCompartment::PassengerCompartment(){
	SecWorker= false;
	CleanWorker = false;
	#ifndef DEBUG
	cout << "PassengerCompartment just created " << endl;
	#endif
	if(rand() % 3 == 0){
		cout << "Sub PassengerCompartment about to be created:" << endl;
		Sub_PassCompartment = new PassengerCompartment();
	}else{
		Sub_PassCompartment = NULL;
	}
}

PassengerCompartment::PassengerCompartment(bool subs){
		SecWorker= false;
		CleanWorker = false;
		#ifndef DEBUG
		cout << "PassengerCompartment just created " << endl;
		#endif
		Sub_PassCompartment = NULL;
}

PassengerCompartment::~PassengerCompartment(){
	#ifndef DEBUG
	cout << "PassengerCompartment to be destroyed" << endl;
	#endif
	delete Sub_PassCompartment;
}

bool PassengerCompartment::ready_check()const{
	if(SecWorker && CleanWorker){
		//toString().print();
		cout << "PassengerCompartment OK!" << endl;
		if(Sub_PassCompartment != NULL){
			cout << "Sub: ";
			if(!(Sub_PassCompartment->ready_check())){
				return false;
			}
		}
		return true;
	}else{
		return false;
	}
}

String PassengerCompartment::toString()const{
	String temp(PlaneComponent::toString().get_txt() + "PassengerCompartment, ");
	if(SecWorker){
		temp.concat("SecurityEmployee worked here, ");
	}else{
		temp.concat("Need SecurityEmployee to work here, ");
	}
	if(CleanWorker){
		temp.concat("CleaningEployee worked here, ");
	}else{
		temp.concat("Need CleaningEployee to work here, ");
	}
	if(Sub_PassCompartment != NULL){
		temp.concat("\n	{Sub_PassCompartment, " + Sub_PassCompartment->toString().get_txt() + "}");
	}else{
		temp.concat("No Sub_PassCompartment.");
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

bool PassengerCompartment::equal(const PassengerCompartment& sec)const{
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
void PassengerCompartment::remove_subs(){
	if(Sub_PassCompartment != NULL){
		Sub_PassCompartment->remove_subs();
		delete Sub_PassCompartment;
	}
}
PassengerCompartment* PassengerCompartment::clone()const{
	PassengerCompartment* temp= new PassengerCompartment(true);
	temp->SecWorker= SecWorker;
	temp->CleanWorker= CleanWorker;
	if(Sub_PassCompartment != NULL){
		temp->Sub_PassCompartment= Sub_PassCompartment->clone();
	}
	temp->id= id;
	return temp;
}

///////////////////////////////////////PrivateCompartment
PrivateCompartment::PrivateCompartment(){
	SecWorker= false;
	CleanWorker= false;
	#ifndef DEBUG
	cout << "PrivateCompartment just created " << endl;
	#endif
}

PrivateCompartment::~PrivateCompartment(){
	#ifndef DEBUG
	cout << "PrivateCompartment to be destroyed" << endl;
	#endif
}

bool PrivateCompartment::ready_check()const{
	if(SecWorker && CleanWorker){
		//toString().print();
		cout << "PrivateCompartment OK!" << endl;
		return true;
	}else{
		return false;
	}
}

String PrivateCompartment::toString()const{
	String temp(PlaneComponent::toString().get_txt() + "PrivateCompartment, ");
	if(SecWorker){
		temp.concat("SecurityEmployee worked here, ");
	}else{
		temp.concat("Need SecurityEmployee to work here, ");
	}
	if(CleanWorker){
		temp.concat("CleaningEployee worked here. ");
	}else{
		temp.concat("Need CleaningEployee to work here, ");
	}
	return temp;
}

void PrivateCompartment::process(SecurityEmployee& worker){
	SecWorker = true;
}

void PrivateCompartment::process(CleaningEployee& worker){
	CleanWorker = true;
}

bool PrivateCompartment::equal(const PrivateCompartment& sec)const{
	if(PlaneComponent::equal(sec)){
		if(SecWorker == sec.SecWorker && CleanWorker == sec.CleanWorker){
			return true;
		}
	}
	return false;
}

///////////////////////////////////////EquipmentCompartment
EquipmentCompartment::EquipmentCompartment(){
	SecWorker= false;
	MaintWorker= false;
	#ifndef DEBUG
	cout << "EquipmentCompartment just created " << endl;
	#endif
}

EquipmentCompartment::~EquipmentCompartment(){
	#ifndef DEBUG
	cout << "EquipmentCompartment to be destroyed" << endl;
	#endif
}

bool EquipmentCompartment::ready_check()const{
	if(SecWorker && MaintWorker){
		//toString().print();
		cout << "EquipmentCompartment OK!" << endl;
		return true;
	}else{
		return false;
	}
}

String EquipmentCompartment::toString()const{
	String temp(PlaneComponent::toString().get_txt() + "EquipmentCompartment, ");
	if(SecWorker){
		temp.concat("SecurityEmployee worked here, ");
	}else{
		temp.concat("Need SecurityEmployee to work here, ");
	}
	if(MaintWorker){
		temp.concat("MaintenanceEmployee worked here. ");
	}else{
		temp.concat("Need MaintenanceEmployee to work here. ");
	}
	return temp;
}
void EquipmentCompartment::process(SecurityEmployee& worker){
	SecWorker= true;
}

void 	EquipmentCompartment::process(MaintenanceEmployee& worker){
	MaintWorker = true;
}

bool EquipmentCompartment::equal(const EquipmentCompartment& sec)const{
	if(PlaneComponent::equal(sec)){
		if(SecWorker == sec.SecWorker && MaintWorker == sec.MaintWorker){
			return true;
		}
	}
	return false;
}

EquipmentCompartment* EquipmentCompartment::clone()const{
	EquipmentCompartment* temp = new EquipmentCompartment;
	temp->SecWorker = SecWorker;
	temp->MaintWorker = MaintWorker;
	temp->PrivateCompartment::SecWorker = PrivateCompartment::SecWorker;
	temp->PrivateCompartment::CleanWorker = PrivateCompartment::CleanWorker;
	temp->id= id;
	return temp;
}

///////////////////////////////////////CargoBay
CargoBay::CargoBay(){
	SecWorker= false;
	CleanWorker= false;
	MaintWorker= false;
	#ifndef DEBUG
	cout << "CargoBay just created " << endl;
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

bool CargoBay::ready_check()const{
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

String CargoBay::toString()const{
	String temp(PlaneComponent::toString().get_txt() + "CargoBay, ");

	if(SecWorker){
		temp.concat("SecurityEmployee worked here, ");
	}else{
		temp.concat("Need SecurityEmployee to work here, ");
	}
	if(CleanWorker){
		temp.concat("CleaningEployee worked here, ");
	}else{
		temp.concat("Need CleaningEployee to work here, ");
	}
	if(MaintWorker){
		temp.concat("MaintenanceEmployee worked here. ");
	}else{
		temp.concat("Need MaintenanceEmployee to work here. ");
	}
	temp.concat("\n	{CargoBay's Equipment_space, " + equipment_space->toString().get_txt() + "}");
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

bool CargoBay::equal(const CargoBay& sec)const{
	if(PlaneComponent::equal(sec)){
		if(SecWorker == sec.SecWorker && CleanWorker == sec.CleanWorker && MaintWorker == sec.MaintWorker){
			if(equipment_space->equal(*(sec.equipment_space))){
				return true;
			}
		}
	}
	return false;
}

CargoBay* CargoBay::clone()const{
	CargoBay* temp= new CargoBay;
	delete temp->equipment_space;
	temp->SecWorker = SecWorker;
	temp->CleanWorker = CleanWorker;
	temp->MaintWorker = MaintWorker;
	temp->equipment_space = equipment_space->clone();
	temp->PrivateCompartment::SecWorker = PrivateCompartment::SecWorker;
	temp->PrivateCompartment::CleanWorker = PrivateCompartment::CleanWorker;
	temp->id= id;
	return temp;
}

///////////////////////////////////////Plane
Plane::Plane(const String& titl, const int ma_pl):
max_pl(ma_pl){
	#ifndef DEBUG
	cout << "Plane just created ";
	#endif
	cout << "Plane with ID: " << get_id() << endl;
	title= new String(titl);
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

Plane::Plane(){
	#ifndef DEBUG
	cout << "Plane just created ";
	#endif
}

Plane::~Plane(){
	delete title;
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

bool Plane::ready_check()const{
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
	for(int i=0;i<size_PassComp;i++){
		if(!pl_PassComp[i]->ready_check()){
			return false;
		}
	}
	return true;

}

String Plane::toString()const{
	String temp(Object::toString().get_txt() +
	"Plane, title= " + title->get_txt() + ", max_pl= " + to_string(max_pl) + ", " +
	"Parts: \n" +
	cargo->toString().get_txt() + "\n" + e1->toString().get_txt() + "\n" + e2->toString().get_txt() + "\n" + e3->toString().get_txt());
 	for(int i=0;i<size_PassComp;i++){
		temp.concat("\n" + pl_PassComp[i]->toString().get_txt());
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

bool Plane::equal(const Plane& sec)const{
	if(title->get_txt() == sec.title->get_txt() && max_pl == sec.max_pl){
		if(cargo->equal(*(sec.cargo))){
			if(e1->equal(*(sec.e1)) && e2->equal(*(sec.e2)) && e3->equal(*(sec.e3))){
				for(int i=0;i<size_PassComp;i++){
					if(!(pl_PassComp[i]->equal(*(sec.pl_PassComp[i])))){
						return false;
					}
				}
				return Object::equal(sec);
			}
		}
	}
	return false;
}

Plane* Plane::clone()const{
	Plane* temp= new Plane();
	temp->title = title->clone();
	temp->max_pl = max_pl;
	temp->size_PassComp = size_PassComp;
	temp->cargo=cargo->clone();
	temp->e1=e1->clone();
	temp->e2=e2->clone();
	temp->e3=e3->clone();
	temp->pl_PassComp = new PassengerCompartment*[temp->size_PassComp];
	for(int i=0;i<temp->size_PassComp;i++){
		temp->pl_PassComp[i]= pl_PassComp[i]->clone();
	}
	temp->id= id;
	return temp;
}

//Clone encrypt and print
void clone_encrypt_and_print(const Object& sec){
	Object* temp=sec.clone();
	cout << "Equal: ";
	if(temp->equal(sec)){
		cout << "TRUE" << endl;
	}else{
		cout << "FALSE" << endl;
	}
	String tempSTR= temp->toString();
	String secSTR= sec.toString();

	int rand_how_many = rand() % tempSTR.length();
	int change;
	int from;
	for(int i=0;i<rand_how_many;i++){
		change= rand()% (tempSTR.length() - 1);
		from = rand()% (tempSTR.length() - 1);
		tempSTR.updateAt(change, tempSTR.at(from));
	}
	cout << endl << "tempSTR: ";
	tempSTR.print();
	cout << endl << "secSTR: ";
	secSTR.print();

	tempSTR.concat(secSTR);
	cout << "length after concat: " << tempSTR.length() << endl;
	cout << "Midle ";
	if(tempSTR.length() % 2 != 0){
		cout << "characters: ";
		cout << tempSTR.at((int)tempSTR.length()/2) << ", " << tempSTR.at(((int)tempSTR.length()/2) + 1) << endl;
	}else{
		cout << "character: ";
		cout << tempSTR.at(tempSTR.length()/2) << endl;
	}
	tempSTR.clear();
	cout << "length of tempSTR after clear: " << tempSTR.length() << endl;
	delete temp;
}
