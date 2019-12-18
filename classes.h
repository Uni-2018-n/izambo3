#include <iostream>
#include <cstring>
using namespace std;

///////////////////////////////////////Object
class Object{
	int id;
public:
	void equal(Object sec);
	void identical(Object sec);
	void clone(Object sec);
	string toString();
};

string Object::toString(){
	return id + " ";
}

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

///////////////////////////////////////PlaneComponent
class PlaneComponent: public Object{
public:
	string toString();
	void ready_check();
	//process
};

string PlaneComponent::toString(){
	return Object::toString()+"got data from PlaneComponent ";
}

///////////////////////////////////////PassengerCompartment
class PassengerCompartment: public PlaneComponent{
	PassengerCompartment* Sub_passengers;
public:
	PassengerCompartment();//constructor
	void ready_check();
	string toString();
};

string PassengerCompartment::toString(){
	return PlaneComponent::toString() + "got data from PassengerCompartment ";
}


void PassengerCompartment::ready_check(){
	cout << "PassengerCompartment OK!" << endl;
	cout << toString() << endl;
	cout << "Sub Compartment: " << endl;
	Sub_passengers->ready_check();
}

///////////////////////////////////////PrivateCompartment
class PrivateCompartment: public PlaneComponent{

public:
	PrivateCompartment();//constructor
	void ready_check();
	string toString();
};

void PrivateCompartment::ready_check(){
	cout << "PrivateCompartment OK!" << endl;
	//+toString output
}



///////////////////////////////////////Plane
class Plane: public Object{
	string title;
	int pl_passengers;
	//cargobay
	//equipmentcompartment1
	//equipmentcompartment2
	//equipmentcompartment3
public:
	string get_title();
	int get_pl_passengers();
	//get cargobay
	//get equipmentcompartment1
	//get equipmentcompartment2
	//get equipmentcompartment3
	string toString();
	void ready_check();
};
