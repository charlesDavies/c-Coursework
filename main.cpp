#include <iostream>
#include <string>
#include "courseClass.h"
#include "studentClass.h"
#include "dateClass.h"
using namespace std;

int main()
{
	Student studentObject;
	Course courseObject;
	Date dateObject;
	bool contine = true;
	int choice;

	while (contine)
	{
		clearScreen();
		cout << "Please choose what you are interested in:\n";
		cout << "1.Students\n";
		cout << "2.Course\n";
		cout << "3.Enrollment\n";
		cout << "4.End Program\n";
		cout << "Enter choice here: ";
		cin >> choice;
		clearScreen();


		switch (choice)
		{
		case 1:
		    studentObject.studentMenu(studentObject);
			break;
		case 2:
			courseObject.courseMenu(courseObject);
			break;
		case 3:
			cout << "NOT IMPLEMENTED, WOULD TAKE USER TO AN ENROLLMENT MENU\n";
			break;
		case 4:
			cout << "Program ending...";
			contine = false;

		}
	}






	cin.get();
	return 0;
}