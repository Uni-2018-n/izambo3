//clone_and_encrypt, rwta gia to {}, restore tostring of readycheck, restore string object and messeges,
//clone 8elei fix meta to destructors ths passenger compartment
#include "classes.h"

int main(){
	srand(4);
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

	Plane test_plane(plane_Title, 1);
	test_plane.clone(my_plane);
	// if(test_plane.equal(my_plane)){
	// 	cout << "TRUEEEEEEEEEEEEEEEEE " << endl;
	// }else{
	// 	cout << "FALSEEEEEEEEEEEEEEEE" << endl;
	// }

	cout << endl << "PLANE DESTRUCTOR" << endl;
	return 0;
}
