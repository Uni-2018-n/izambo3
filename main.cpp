#include "classes.h"

int main(){
	Plane my_plane("Daboing1", 200);
	cout << "PLANE CONSTRUCTOR DONE" << endl << endl;

	SecurityEmployee SecEmpl;
	MaintenanceEmployee MaintEmpl;
	CleaningEployee CleanEmpl;

	cout << "EMPLOYEE DONE" << endl << endl;

	my_plane.process(SecEmpl);
	my_plane.process(MaintEmpl);
	my_plane.process(CleanEmpl);

	cout << "PROCESS DONE" << endl << endl;

	if(my_plane.ready_check()){
		cout << "Plane ready to take off!!" << endl;
	}
	cout << endl << "PLANE DESTRUCTOR" << endl;
	return 0;
}
