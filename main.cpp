//String, identical, clone_and_encrypt, rwta gia to {}, rwta gia to poses process prepei na exoyme

#include "classes.h"

int main(){
	Plane my_plane("Daboing1", 200);
	cout << "PLANE CONSTRUCTOR DONE" << endl << endl;

	SecurityEmployee SecEmpl("Bill");
	SecEmpl.toString().print();
	MaintenanceEmployee MaintEmpl("Bob");
	MaintEmpl.toString().print();
	CleaningEployee CleanEmpl("Mike");
	CleanEmpl.toString().print();

	cout << "EMPLOYEE DONE" << endl << endl;


	my_plane.process(SecEmpl);
	my_plane.process(MaintEmpl);
	my_plane.process(CleanEmpl);


	cout << "-------------------TEST-----------------------" << endl;
	cout << "-------------------/TEST-----------------------" << endl;

	cout << "PROCESS DONE" << endl << endl;

	if(my_plane.ready_check()){
		my_plane.toString().print();
		cout << "Plane ready to take off!!" << endl;
	}else{
		cout << "Plane not ready ERROR ERROR COLLISION COLLISION " << endl << endl;
	}



	cout << endl << "PLANE DESTRUCTOR" << endl;
	return 0;
}
