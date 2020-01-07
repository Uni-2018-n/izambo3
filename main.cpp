//clone_and_encrypt, rwta gia to {}, restore tostring of readycheck, restore string object and messeges

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

	cout << endl << "PLANE DESTRUCTOR" << endl;
	return 0;
}
