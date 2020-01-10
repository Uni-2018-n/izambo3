//clone_and_encrypt, rwta gia to {}, restore tostring of readycheck, restore string object and messeges
//fix the constructor messeges, memory leaks, check something with the Sub_PassCompartment ready_check
//649 line
#include "classes.h"

int main(){
	srand(time(NULL));
	String plane_Title("Daboing1");
	Plane my_plane(plane_Title, 200);
	cout << "PLANE CONSTRUCTOR DONE" << endl << endl;

	String SecEmp_Title("BIll");
	SecurityEmployee SecEmpl(SecEmp_Title);
	SecEmpl.toString().print();

	String MaintEmp_Title("Bob");
	MaintenanceEmployee MaintEmpl(MaintEmp_Title);
	MaintEmpl.toString().print();

	String CleanEmp_Title("Mike");
	CleaningEployee CleanEmpl(CleanEmp_Title);
	CleanEmpl.toString().print();

	cout << "EMPLOYEE DONE" << endl << endl;


	my_plane.process(SecEmpl);
	my_plane.process(MaintEmpl);
	my_plane.process(CleanEmpl);

	cout << "PROCESS DONE" << endl << endl;

	if(my_plane.ready_check()){
		cout << "PLANE TOSTRING:" << endl;
		my_plane.toString().print();
		cout << "Plane ready to take off!!" << endl;
	}else{
		cout << "Plane not ready ERROR ERROR COLLISION COLLISION " << endl << endl;
	}

	cout << endl << endl << "<CLONE>" << endl;
	Plane* test_plane= my_plane.clone();
	cout << endl <<"test_plane : toString :" << endl;
	test_plane->toString().print();
	cout << endl << "test_plane : ready_check:" << endl;
	if(test_plane->ready_check()){
		cout << "READY" << endl;
	}else{
		cout << "NOT READY" << endl << endl;
	}
	cout << "</CLONE>" << endl << endl << endl;

	cout << endl << "PLANE DESTRUCTOR" << endl;
	return 0;
}
