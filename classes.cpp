#include "classes.h"

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



class Employee{
	string name;

public:
	virtual void workOn();
	virtual bool report();
};


class SecurityEmployee: public Employee{//all
public:
	void workOn(CargoBay* work_place);
	void workOn(EquipmentCompartment* work_place);
	void workOn(PassengerCompartment* work_place);

	bool report();
};

class MaintenanceEmployee: public Employee{//cargobay, EquipmentCompartment
public:
	bool report();
};

class CleaningEployee: public Employee{//CargoBay, PassengerCompartment
public:

	bool report();
};



class PlaneComponent{
public:
	bool ready_check();
	string toString();
	void process(Employee worker);
};

class PassengerCompartment: public PlaneComponent{
	PassengerCompartment* Sub_PassCompartment;
public:
	PassengerCompartment();
	bool ready_check();
	void toString();
	void process(SecurityEmployee worker);
	void process(CleaningEployee worker);
};

bool PassengerCompartment::ready_check(){ //TIS READY_CHECK PREPEI NA PERASOUN OLOI GIA NA EINAI READY
	toString();
	cout << "PassengerCompartment OK!" << endl;
	if(Sub_PassCompartment != NULL)
	cout << "Sub: ";
	Sub_PassCompartment->ready_check();
}

class PrivateCompartment: public PlaneComponent{
public:
	PrivateCompartment();
	bool ready_check();
	void toString();
	void process(SecurityEmployee worker);
	void process(CleaningEployee worker);
};

bool PrivateCompartment::ready_check(){
	toString();
	cout << "PrivateCompartment OK!" << endl;
}

class EquipmentCompartment: public PlaneComponent{
public:
	EquipmentCompartment();
	bool ready_check();
	void toString();
	void process(SecurityEmployee worker);
	void process(MaintenanceEmployee worker);
};

bool EquipmentCompartment::ready_check(){
	toString();
	cout << "EquipmentCompartment OK!" << endl;
}

class CargoBay: public PlaneComponent{
	EquipmentCompartment equipment_space;
public:
	CargoBay();
	bool ready_check();
	void toString();
	void process(SecurityEmployee worker);
	void process(CleaningEployee worker);
	void process(MaintenanceEmployee worker);
};

bool CargoBay::ready_check(){
	toString();
	cout << "CargoBay OK!" << endl;
}

class Plane{
	string title;
	int max_pl;
	CargoBay cargo;
	EquipmentCompartment e1;
	EquipmentCompartment e2;
	EquipmentCompartment e3;
	int curr_pl;
public:
	void toString();
	bool ready_check();
	void process();
};
