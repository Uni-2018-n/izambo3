#include <iostream>
using namespace std;

//forward declaration

class String;
class Employee;
class SecurityEmployee;
class MaintenanceEmployee;
class CleaningEmployee;

class PlaneComponent;
class PassengerCompartment;
class PrivateCompartment;
class EquipmentCompartment;
class CargoBay;

class Plane;

///////////////////////////////////////Object
class Object{
protected:
	static int temp_id;
	int id;
public:
	Object();
	virtual ~Object();
	virtual bool equal(const Object& sec)const;
	bool identical(const Object& sec)const;//kai gia alles synarthseis
	virtual Object* clone()const=0;
	virtual String toString()const;

	int get_id()const;
};

///////////////////////////////////////String
class String:public Object{
	string txt;
public:
	String(const string temp);
	~String();
	int length()const;
	void clear();
	void concat(const String sec);
	void concat(const string sec);
	char at(int pos)const;
	void updateAt(const int pos, const char rep);
	void print()const;

	string  get_txt()const;

	String* clone()const;

	String toString()const;
};

///////////////////////////////////////Employee
class Employee: public Object{
protected:
	String* name;
public:
	Employee();
	virtual ~Employee();
	virtual void workOn(CargoBay& work_place){};
	virtual void workOn(EquipmentCompartment& work_place){};
	virtual void workOn(PassengerCompartment& work_place){};

	virtual void report(const CargoBay& work_place){};
	virtual void report(const EquipmentCompartment& work_place){};
	virtual void report(const PassengerCompartment& work_place){};
	virtual String toString()const;

	virtual bool equal(const Employee& sec)const;
	virtual Employee* clone()const=0;
};

///////////////////////////////////////SecurityEmployee
class SecurityEmployee: public Employee{//all
public:
	SecurityEmployee(const String& nam);
	~SecurityEmployee();
	void workOn(CargoBay& work_place);
	void workOn(EquipmentCompartment& work_place);
	void workOn(PassengerCompartment& work_place);

	void report(const CargoBay& work_place)const;
	void report(const EquipmentCompartment& work_place)const;
	void report(const PassengerCompartment& work_place)const;

	String toString()const;

	bool equal(const SecurityEmployee& sec)const;
	SecurityEmployee* clone()const;
};

///////////////////////////////////////MaintenanceEmployee
class MaintenanceEmployee: public Employee{//cargobay, EquipmentCompartment
public:
	MaintenanceEmployee(const String& nam);
	~MaintenanceEmployee();
	void workOn(CargoBay& work_place);
	void workOn(EquipmentCompartment& work_place);

	void report(const CargoBay& work_place)const;
	void report(const EquipmentCompartment& work_place)const;

	String toString()const;

	bool equal(const MaintenanceEmployee& sec)const;
	MaintenanceEmployee* clone()const;
};

///////////////////////////////////////CleaningEmployee
class CleaningEmployee: public Employee{//CargoBay, PassengerCompartment
public:
	CleaningEmployee(const String nam);
	~CleaningEmployee();
	void workOn(CargoBay& work_place);
	void workOn(PassengerCompartment& work_place);

	void report(const CargoBay& work_place)const;
	void report(const PassengerCompartment& work_place)const;

	String toString()const;

	bool equal(const CleaningEmployee& sec)const;
	CleaningEmployee* clone()const;

};

///////////////////////////////////////PlaneComponent
class PlaneComponent: public Object{
public:
	PlaneComponent();
	virtual ~PlaneComponent();
	virtual bool ready_check()const=0;
	virtual void process(SecurityEmployee& worker){};
	virtual void process(CleaningEmployee& worker){};
	virtual void process(MaintenanceEmployee& worker){};

	virtual String toString()const;

	virtual bool equal(const PlaneComponent& sec)const;

	virtual PlaneComponent* clone()const=0;
};

///////////////////////////////////////PassengerCompartment
class PassengerCompartment: public PlaneComponent{
	PassengerCompartment* Sub_PassCompartment;
	bool SecWorker;
	bool CleanWorker;
	void remove_subs();
public:
	PassengerCompartment();
	PassengerCompartment(bool subs);
	~PassengerCompartment();
	bool ready_check()const;
	String toString()const;
	void process(SecurityEmployee& worker);
	void process(CleaningEmployee& worker);

	bool equal(const PassengerCompartment& sec)const;

	PassengerCompartment* clone()const;
};

///////////////////////////////////////PrivateCompartment
class PrivateCompartment: public PlaneComponent{
protected:
	bool SecWorker;
	bool CleanWorker;
public:
	PrivateCompartment();
	~PrivateCompartment();
	virtual bool ready_check()const;
	String toString()const;
	virtual void process(SecurityEmployee& worker);
	virtual void process(CleaningEmployee& worker);

	bool equal(const PrivateCompartment& sec)const;

	virtual PrivateCompartment* clone()const=0;
};

///////////////////////////////////////EquipmentCompartment
class EquipmentCompartment: public PrivateCompartment{
	bool SecWorker;
	bool MaintWorker;
public:
	EquipmentCompartment();
	~EquipmentCompartment();
	bool ready_check()const;
	String toString()const;
	void process(SecurityEmployee& worker);
	void process(MaintenanceEmployee& worker);

	bool equal(const EquipmentCompartment& sec)const;

	EquipmentCompartment* clone()const;
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
	bool ready_check()const;
	String toString()const;
	void process(SecurityEmployee& worker);
	void process(CleaningEmployee& worker);
	void process(MaintenanceEmployee& worker);

	bool equal(const CargoBay& sec)const;

	CargoBay* clone()const;
};

///////////////////////////////////////Plane
class Plane: public Object{//anaktish twn timwn aytwn
	String* title;
	int max_pl;
	int size_PassComp;
	CargoBay* cargo;
	EquipmentCompartment* e1;
	EquipmentCompartment* e2;
	EquipmentCompartment* e3;
	PassengerCompartment** pl_PassComp;
public:
	Plane(const String& titl, const int ma_pl=40);
	Plane();
	~Plane();
	bool ready_check()const;
	String toString()const;
	void process(SecurityEmployee& worker);
	void process(MaintenanceEmployee& worker);
	void process(CleaningEmployee& worker);

	bool equal(const Plane& sec)const;

	Plane* clone()const;
};

void clone_encrypt_and_print(const Object& sec);
