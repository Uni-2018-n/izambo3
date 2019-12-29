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
public:
	static int id;//set private if dont want to print or use it
	Object();
	~Object();
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
class Employee: public Object{
	string name;
public:
	Employee();
	virtual ~Employee();
	// virtual void workOn(CargoBay& work_place)=0;
	// virtual void workOn(EquipmentCompartment& work_place)=0;
	// virtual void workOn(PassengerCompartment& work_place)=0;
	//
	// virtual void report(CargoBay& work_place)=0;
	// virtual void report(EquipmentCompartment& work_place)=0;
	// virtual void report(PassengerCompartment& work_place)=0;
};

///////////////////////////////////////SecurityEmployee
class SecurityEmployee: public Employee{//all
public:
	SecurityEmployee();
	~SecurityEmployee();
	void workOn(CargoBay& work_place);
	void workOn(EquipmentCompartment& work_place);
	void workOn(PassengerCompartment& work_place);

	void report(CargoBay& work_place);
	void report(EquipmentCompartment& work_place);
	void report(PassengerCompartment& work_place);
};

///////////////////////////////////////MaintenanceEmployee
class MaintenanceEmployee: public Employee{//cargobay, EquipmentCompartment
public:
	MaintenanceEmployee();
	~MaintenanceEmployee();
	void workOn(CargoBay& work_place);
	void workOn(EquipmentCompartment& work_place);
	void report(CargoBay& work_place);
	void report(EquipmentCompartment& work_place);
};

///////////////////////////////////////CleaningEployee
class CleaningEployee: public Employee{//CargoBay, PassengerCompartment
public:
	CleaningEployee();
	~CleaningEployee();
	void workOn(CargoBay& work_place);
	void workOn(PassengerCompartment& work_place);
	void report(CargoBay& work_place);
	void report(PassengerCompartment& work_place);
};

///////////////////////////////////////PlaneComponent
class PlaneComponent: public Object{
public:
	PlaneComponent();
	virtual ~PlaneComponent();
	// virtual bool ready_check() = 0;
	// virtual string toString() = 0;
	// virtual void process() = 0;
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
	string toString();
	void process(SecurityEmployee& worker);
	void process(CleaningEployee& worker);
};

///////////////////////////////////////PrivateCompartment
class PrivateCompartment: public PlaneComponent{
	bool SecWorker;
	bool CleanWorker;
public:
	PrivateCompartment();
	~PrivateCompartment();
	virtual bool ready_check();
	string toString();
	virtual void process(SecurityEmployee& worker);
	virtual void process(CleaningEployee& worker);
};

///////////////////////////////////////EquipmentCompartment
class EquipmentCompartment: public PrivateCompartment{
	bool SecWorker;
	bool MaintWorker;
public:
	EquipmentCompartment();
	~EquipmentCompartment();
	bool ready_check();
	string toString();
	void process(SecurityEmployee& worker);
	void process(MaintenanceEmployee& worker);
};

///////////////////////////////////////CargoBay
class CargoBay: public PrivateCompartment{
	EquipmentCompartment equipment_space;
	bool SecWorker;
	bool CleanWorker;
	bool MaintWorker;
public:
	CargoBay();
	~CargoBay();
	bool ready_check();
	string toString();
	void process(SecurityEmployee& worker);
	void process(CleaningEployee& worker);
	void process(MaintenanceEmployee& worker);
};

///////////////////////////////////////Plane
class Plane: public Object{//anaktish twn timwn aytwn
	string title;
	int max_pl;
	CargoBay* cargo;
	EquipmentCompartment* e1;
	EquipmentCompartment* e2;
	EquipmentCompartment* e3;
	PassengerCompartment** pl_PassComp;
public:
	Plane(string titl, int ma_pl=40);
	~Plane();
	bool ready_check();
	void toString();
	void process(SecurityEmployee& worker);
	void process(MaintenanceEmployee& worker);
	void process(CleaningEployee& worker);
};
