#include "classes.h"

int main(){
	Plane my_plane("Daboing1", 200);
	cout << "PLANE CONSTRUCTOR DONE" << endl << endl;

	SecurityEmployee SecEmpl("Bill");
	cout << SecEmpl.toString() << endl;
	MaintenanceEmployee MaintEmpl("Bob");
	cout << MaintEmpl.toString() << endl;
	CleaningEployee CleanEmpl("Mike");
	cout << CleanEmpl.toString() << endl;

	cout << "EMPLOYEE DONE" << endl << endl;

	my_plane.process(SecEmpl);
	my_plane.process(MaintEmpl);
	my_plane.process(CleanEmpl);

	cout << "PROCESS DONE" << endl << endl;

	if(my_plane.ready_check()){
		cout << my_plane.toString() << endl;
		cout << "Plane ready to take off!!" << endl;
	}else{
		cout << "Plane not ready ERROR ERROR COLLISION COLLISION " << endl << endl;
	}
	cout << endl << "PLANE DESTRUCTOR" << endl;
	return 0;
}
