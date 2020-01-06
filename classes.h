#include <iostream>
#include <cstring>
using namespace std;



//forward declaration

class String;
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
	static int temp_id;
	int id;
public:
	Object();
	~Object();
	virtual bool equal(Object& sec);
	bool identical(Object& sec);//kai gia alles synarthseis
	virtual void clone(Object& sec);
	virtual String toString();

	int get_id();
};

///////////////////////////////////////String
class String: public Object{
	string txt;
public:
	String(string temp);
	~String();
	int length();
	void clear();
	void concat(String sec);
	char at(int pos);
	void updateAt(int pos, char rep);
	void print();

	string  get_txt();
};

///////////////////////////////////////Employee
class Employee: public Object{
	String name;
public:
	Employee(String nam);
	virtual ~Employee();
	virtual void workOn(CargoBay& work_place){};
	virtual void workOn(EquipmentCompartment& work_place){};
	virtual void workOn(PassengerCompartment& work_place){};

	virtual void report(CargoBay& work_place){};
	virtual void report(EquipmentCompartment& work_place){};
	virtual void report(PassengerCompartment& work_place){};
	virtual String toString();

	virtual bool equal(Employee& sec);
	virtual void clone(Employee& sec);
};

///////////////////////////////////////SecurityEmployee
class SecurityEmployee: public Employee{//all
public:
	SecurityEmployee(String nam);
	~SecurityEmployee();
	void workOn(CargoBay& work_place);
	void workOn(EquipmentCompartment& work_place);
	void workOn(PassengerCompartment& work_place);

	void report(CargoBay& work_place);
	void report(EquipmentCompartment& work_place);
	void report(PassengerCompartment& work_place);

	String toString();

	bool equal(SecurityEmployee& sec);
	void clone(SecurityEmployee& sec);
};

///////////////////////////////////////MaintenanceEmployee
class MaintenanceEmployee: public Employee{//cargobay, EquipmentCompartment
public:
	MaintenanceEmployee(String nam);
	~MaintenanceEmployee();
	void workOn(CargoBay& work_place);
	void workOn(EquipmentCompartment& work_place);
	void report(CargoBay& work_place);
	void report(EquipmentCompartment& work_place);

	String toString();

	bool equal(MaintenanceEmployee& sec);
	void clone(MaintenanceEmployee& sec);
};

///////////////////////////////////////CleaningEployee
class CleaningEployee: public Employee{//CargoBay, PassengerCompartment
public:
	CleaningEployee(String nam);
	~CleaningEployee();
	void workOn(CargoBay& work_place);
	void workOn(PassengerCompartment& work_place);
	void report(CargoBay& work_place);
	void report(PassengerCompartment& work_place);

	String toString();

	bool equal(CleaningEployee& sec);
	void clone(CleaningEployee& sec);

};

///////////////////////////////////////PlaneComponent
class PlaneComponent: public Object{
public:
	PlaneComponent();
	virtual ~PlaneComponent();
	virtual bool ready_check() = 0;
	virtual void process(SecurityEmployee& worker){};
	virtual void process(CleaningEployee& worker){};
	virtual void process(MaintenanceEmployee& worker){};

	virtual String toString();

	virtual bool equal(PlaneComponent& sec);

	virtual void clone(PlaneComponent& sec);
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
	String toString();
	void process(SecurityEmployee& worker);
	void process(CleaningEployee& worker);

	bool equal(PassengerCompartment& sec);

	void clone(PassengerCompartment& sec);
};

///////////////////////////////////////PrivateCompartment
class PrivateCompartment: public PlaneComponent{
	bool SecWorker;
	bool CleanWorker;
public:
	PrivateCompartment();
	~PrivateCompartment();
	virtual bool ready_check();
	String toString();
	virtual void process(SecurityEmployee& worker);
	virtual void process(CleaningEployee& worker);

	bool equal(PrivateCompartment& sec);

	void clone(PrivateCompartment& sec);
};

///////////////////////////////////////EquipmentCompartment
class EquipmentCompartment: public PrivateCompartment{
	bool SecWorker;
	bool MaintWorker;
public:
	EquipmentCompartment();
	~EquipmentCompartment();
	bool ready_check();
	String toString();
	void process(SecurityEmployee& worker);
	void process(MaintenanceEmployee& worker);

	bool equal(EquipmentCompartment& sec);

	void clone(EquipmentCompartment& sec);
};

///////////////////////////////////////CargoBay
class CargoBay: public PrivateCompartment{
	EquipmentCompartment* equipment_space;
	bool SecWorker;
	bool CleanWorker;
	bool MaintWorker;
public:
	CargoBay();
	~CargoBay();
	bool ready_check();
	String toString();
	void process(SecurityEmployee& worker);
	void process(CleaningEployee& worker);
	void process(MaintenanceEmployee& worker);

	bool equal(CargoBay& sec);

	void clone(CargoBay& sec);
};

///////////////////////////////////////Plane
class Plane: public Object{//anaktish twn timwn aytwn
	String title;
	int max_pl;
	CargoBay* cargo;
	EquipmentCompartment* e1;
	EquipmentCompartment* e2;
	EquipmentCompartment* e3;
	PassengerCompartment** pl_PassComp;
public:
	Plane(String titl, int ma_pl=40);
	~Plane();
	bool ready_check();
	String toString();
	void process(SecurityEmployee& worker);
	void process(MaintenanceEmployee& worker);
	void process(CleaningEployee& worker);

	bool equal(Plane& sec);

	void clone(Plane& sec);
};
