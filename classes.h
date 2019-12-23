#include <iostream>
#include <cstring>
using namespace std;

//forward declaration

class Employee;
class SecurityEmployee;
class MaintenanceEmployee;
class CleaningEployee;

class PlaneComponent;
class PassengerCompartment;
class PrivateCompartment;
class EquipmentCompartment;
class CargoBay;

class Plane;

///////////////////////////////////////Object
class Object{
	int id;
public:
	void equal(Object sec);
	void identical(Object sec);
	void clone(Object sec);
	string toString();
};

///////////////////////////////////////String
class String: public Object{
	string txt;
public:
	String(string temp);
	int length();
	void clear();
	void concat(String sec);
	char at(int pos);
	void updateAt(int pos, char rep);
	void print();
};

///////////////////////////////////////Employee
class Employee{
	string name;
public:
	Employee();
	~Employee();
	virtual void workOn();
	virtual bool report();
};

///////////////////////////////////////SecurityEmployee
class SecurityEmployee: public Employee{//all
public:
	SecurityEmployee();
	~SecurityEmployee();
	// void workOn(CargoBay work_place);
	// void workOn(EquipmentCompartment work_place);
	// void workOn(PassengerCompartment work_place);
	// bool report();
};

///////////////////////////////////////MaintenanceEmployee
class MaintenanceEmployee: public Employee{//cargobay, EquipmentCompartment
public:
	MaintenanceEmployee();
	~MaintenanceEmployee();
	//bool report();
};

///////////////////////////////////////CleaningEployee
class CleaningEployee: public Employee{//CargoBay, PassengerCompartment
public:
	CleaningEployee();
	~CleaningEployee();
	//bool report();
};

///////////////////////////////////////PlaneComponent
class PlaneComponent{
public:
	PlaneComponent();
	~PlaneComponent();
	//bool ready_check();
	//string toString();
	//void process(Employee worker);
};

///////////////////////////////////////PassengerCompartment
class PassengerCompartment: public PlaneComponent{
	PassengerCompartment* Sub_PassCompartment;
	bool SecWorker;
	bool CleanWorker;
public:
	PassengerCompartment();
	~PassengerCompartment();
	bool ready_check();
	//void toString();
	void process(SecurityEmployee worker);
	void process(CleaningEployee worker);
};

///////////////////////////////////////PrivateCompartment
class PrivateCompartment: public PlaneComponent{
	bool SecWorker;
	bool CleanWorker;
public:
	PrivateCompartment();
	~PrivateCompartment();
	bool ready_check();
	//void toString();
	void process(SecurityEmployee worker);
	void process(CleaningEployee worker);
};

///////////////////////////////////////EquipmentCompartment
class EquipmentCompartment: public PlaneComponent{
	bool SecWorker;
	bool MaintWorker;
public:
	EquipmentCompartment();
	~EquipmentCompartment();
	bool ready_check();
	//void toString();
	void process(SecurityEmployee worker);
	void process(MaintenanceEmployee worker);
};

///////////////////////////////////////CargoBay
class CargoBay: public PlaneComponent{
	EquipmentCompartment equipment_space;
	bool SecWorker;
	bool CleanWorker;
	bool MaintWorker;
public:
	CargoBay();
	~CargoBay();
	bool ready_check();
	//void toString();
	void process(SecurityEmployee worker);
	void process(CleaningEployee worker);
	void process(MaintenanceEmployee worker);
};

///////////////////////////////////////Plane
class Plane{
	string title;
	int max_pl;
	CargoBay cargo;
	EquipmentCompartment e1;
	EquipmentCompartment e2;
	EquipmentCompartment e3;
	int curr_pl;
public:
	Plane(string titl, int cur_pl, int ma_pl=40);
	~Plane();
	//void toString();
	//bool ready_check();
	//void process();
};
