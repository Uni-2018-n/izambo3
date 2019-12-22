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

///////////////////////////////////////
