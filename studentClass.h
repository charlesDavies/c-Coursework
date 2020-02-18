#pragma once
#include <iostream>
#include <string>
#include "courseClass.h"
#include "dateClass.h"
#include <windows.h>
#include <fstream>
using namespace std;


// A function for clearing up the screen
void clearScreen()
{
	for (int i = 0; i < 50; i++)
	{
		cout << "\n";
	}

}

class Student {
public:
	// the student menu
	bool studentMenu(Student& s);
	void addStudent(Student& s);
	void viewStudent(Student& s);
	void editStudent(Student& s);
	void removeStudent(Student& s);
	void saveStudent(Student& s);
	void searchForStudent(Student& s);
	void numberOfStudentRecords(int &n);
	void studentFound(Student& s, bool &found);

private:
	
	int studentID = 0;
	char name[256];
	char address[256];
	int dd;
	int mm;
	int yyyy;
	
	

};



// the student menu

bool
Student::studentMenu(Student& s)
{
	bool contine = true;
	int choice;

	while (contine)
	{
		cout << "Please choose what you are interested in:\n";
		cout << "1.Add Student\n";
		cout << "2.View Student Added\n";
		cout << "3.Edit Student Added\n";
		cout << "4.Remove Student\n";
		cout << "5.Get number of Student Records\n";
		cout << "6.Search for Student\n";
		cout << "7.Save Student\n";
		cout << "8.Return to previous menu\n";
		cout << "Enter choice here: ";
		cin >> choice;
		clearScreen();

		switch (choice)
		{
		case 1:
			s.addStudent(s);
			break;
		case 2:
			s.viewStudent(s);
			break;
		case 3:
			s.editStudent(s);
			break;
		case 4:
			s.removeStudent(s);
			break;
		case 5:
			s.numberOfStudentRecords(s.studentID);
			break;
		case 6:
			s.searchForStudent(s);
			break;
		case 7:
			s.saveStudent(s);
			break;
		case 8:
			cout << "Going back\n";
			return 0;
		default:
			cout << "WTF happened bro";
			break;

		}

		//cout << "Seems you entered an invalid input...\n";
	}
	return 0;
}

void
Student::addStudent(Student& s)
{
	clearScreen();
	bool found = false;

	cout << "ADDING STUDENT\n";
	cout << "Please enter Student ID Number: ";
	cin >> s.studentID;
	studentFound(s, found);
	if (found == true)
	{
		cout << "Error - That Student ID already exists... Please enter a different ID\n";
		system("pause");
		addStudent(s);
	}
	else
	{
		while (cin.fail()) // Checking if something other than an INT was entered
		{

			cin.clear();
			cin.ignore();
			cout << "Error, Please only enter whole numbers.\n";
			cout << "Please enter Student ID Number: ";
			cin >> s.studentID;

		}
		while (to_string(s.studentID).length() != 8) // Checking if the INTs length is greater or smaller than 8
		{
			cout << "Oops! You've entered a wrong ID Number. ID numbers must be 8 numbers long!\n";
			cout << "Please enter Student ID Number: ";
			cin.clear();
			cin.ignore();
			cin >> s.studentID;
			while (cin.fail()) 
			{
				cin.clear();
				cin.ignore();
				cout << "Error, Please only enter whole numbers.\n";
				cout << "Please enter Student ID Number: ";
				cin >> s.studentID;

			}
		}
		cout << "Please enter Student Name: ";
		cin.ignore();
		cin.getline(s.name, 256); // using get line and not cin so the user can input spaces
		cout << "Please enter Student Email Address: ";
		cin.getline(s.address, 256);
		Date d;
		cout << "Please enter Student date of birth: ";
		d.getDate(dd, mm, yyyy);
		clearScreen();
		cout << "Adding Student";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << "\nStudent Added!\n";

		cout << "Would you like to save this Student to the Student Record?\n";
		string choice;
		cin >> choice;
		if (choice == "y" || choice == "Y" || choice == "yes" || choice == "Yes") // taking into accound multiple ways of saying yes
			saveStudent(s);

		system("pause");
		clearScreen();
	}
	

}

void
Student::viewStudent(Student& s)
{
	if (s.studentID == 0)
	{
		cout << "No Student has been added yet.\n";
		system("pause");
		clearScreen();
	}
	else
	{
		cin.ignore();
		cin.clear();
		cout << "STUDENT DETAILS\n";
		cout << "Student ID Number: " << s.studentID << "\n";
		cout << "Student Name: " << s.name << "\n";
		cout << "Student Email Addess: " << s.address << "\n";
		cout << "Student Date of Birth: " << s.dd << "/" << s.mm << "/" << s.yyyy << endl;
		cin.ignore();
		system("pause");
		clearScreen();
	}

}

void
Student::editStudent(Student& s)
{

	int choice = 0;
	bool carryOn = true;
	while (carryOn)
	{
	
		cout << "STUDENT DETAILS\n";
		cout << "1.Student ID Number: " << s.studentID << "\n";
		cout << "2.Student Name: " << s.name << "\n";
		cout << "3.Student Email Addess: " << s.address << "\n";
		cout << "4.Student Date of Birth: " << s.dd << "/" << s.mm << "/" << s.yyyy << endl;
		cout << "\n";
		cout << "Please enter the number of the Student detail you would like to amend or press 5 to go back a screen: ";
		cin >> choice;
		Date d;

		switch (choice)
		{
		case 1:
			cout << "Enter Student new ID Number: ";
			cin >> s.studentID;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Error, Please only enter whole numbers.\n";
				cout << "Please enter Student ID Number: ";
				cin >> s.studentID;

			}
			while (to_string(s.studentID).length() != 8)
			{
				cout << "Oops! You've entered a wrong ID Number. ID numbers must be 8 numbers long!\n";
				cout << "Please enter Student ID Number: ";
				cin.ignore();
				cin.clear();
				cin >> s.studentID;
				while (cin.fail())
				{
					cin.clear();
					cin.ignore();
					cout << "Error, Please only enter whole numbers.\n";
					cout << "Please enter Student ID Number: ";
					cin >> s.studentID;

				}
			}
			clearScreen();
			break;
		case 2:
			cout << "Enter Student new Name: ";
			cin.clear();
			cin.ignore();
			cin.getline(s.name, 256);
			clearScreen();
			break;
		case 3:
			cout << "Enter Student new Email Address: ";
			cin.clear();
			cin.ignore();
			cin.getline(s.address, 256);
			clearScreen();
			break;
		case 4:
			d.getDate(dd, mm, yyyy);
			clearScreen();
			break;
		case 5:
			cout << "Leaving screen";
			carryOn = false;
			clearScreen();
			break;
		default:
			cout << "WTF BRO";
			clearScreen();
			break;



		}
	}

}

void
Student::removeStudent(Student& s) // CURRENTLY ONLY REMOVES FROM PROGRAM, NOT FROM TEXT FILE RECORDS
{
			
	


	s.studentID = NULL;
	s.name[0] = NULL;
	s.address[0] = NULL;
	s.dd = NULL;
	s.mm = NULL;
	s.yyyy = NULL;
	cout << "Removing Student";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << "\nStudent Removed!\n";
	system("pause");
	clearScreen();
} 

void
Student::saveStudent(Student& s)
{
	if (s.studentID == 0) // A check to make sure a student record has been inputted before saving
	{
		
		cout << "No Student has been inputted! Saving failed.\n";
		system("pause");
		clearScreen();
	}
	else
	{
		cout << "Saving Student";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << "\nStudent Saved!\n";
		
		ofstream myfile("students.txt", fstream::app);
		if (myfile.is_open())
		{
			myfile << "Student ID: " << s.studentID << " \n";
			myfile << "Student Name: " << s.name << " \n";
			myfile << "Student Email Address: " << s.address << " \n";
			if (s.dd < 10) // Attempt to fix stoi error
				myfile << "Student Date of Birth: " << "0" << s.dd << "/" << s.mm << "/" << s.yyyy << " \n";
			else
				myfile << "Student Date of Birth: " << s.dd << "/" << s.mm << "/" << s.yyyy << " \n";
			myfile << "\n\n";
			myfile.close();
		}
		else cout << "Unable to open file";

		ofstream numberfile("studentnumber.txt", fstream::app); // Saves to to files, but only saves the name and ID to the second file. 
		if (numberfile.is_open())
		{
			numberfile << s.name << ": " << s.studentID << "\n";
			numberfile.close();
		}
		else cout << "Unable to open file";


		std::ifstream  inFile("students.txt"); // Makes a copy of the file everytime you save as a back up file just incase
		std::ofstream  outFile("tempstudents.txt");
		outFile << inFile.rdbuf();

		system("pause");
		clearScreen();
	}
}

void
Student::numberOfStudentRecords(int &n) // function to tell us how many lines in our student records file
{
	n = 0;
	string line;

	ifstream numberOfStudentsFile("studentnumber.txt");
	while (getline(numberOfStudentsFile, line))
		n++;

	cout << "There are " << n << " Student Records on file.\n";
	system("pause");
	clearScreen();

	
}

void
Student::searchForStudent(Student& s)
{
	string search;
	string preSearch = "Student ID: ";
	string line;
	int counter = 0;
	bool found = false;
	size_t pos;
	ifstream studentfile("students.txt");
	string temp;
	
	if (studentfile.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}

	cout << "Please enter a Student ID: ";
	cin >> search;
	preSearch += search;
	cout << "Searching for Student";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	while (!studentfile.eof()) //While the error state flag is not set
	{
		counter++;
		getline(studentfile, line); 
		pos = line.find(preSearch); // Searches the line for what we are looking for 
		if (pos != string::npos)
		{
			
			temp = line.substr(12, 8); // getting the student id from the page
			s.studentID = stoi(temp); // and turning it into an int so we can assign it to id number variable
			cout << "\nStudent found on line " << counter << "\n";
		    found = true;
			for (int i = 0; i < 4; i++)
			{
				cout << "\n";
				cout << line;
				getline(studentfile, line);
				
				switch (i) // switch statement to do different things depending on what iteration I is on
				{
					case 0:
						temp = line.substr(14); // creates a temp string with the value of the string lin starting from the 14 char
						strcpy_s(s.name, temp.c_str()); // copies the values to s.name
						break;
					case 1:
						temp = line.substr(23);
						strcpy_s(s.address, temp.c_str()); // the same but for s.address
						break;
					case 2: // gets each individual part of the date, converts it to int and sets it to student date
						string temp2;
						string temp3;
						cin.clear();
						cin.ignore();
						temp = line.substr(23, 2);
						s.dd = stoi(temp);
						temp2 = line.substr(26, 2);
						s.mm = stoi(temp2);
						temp3 = line.substr(28);
						s.yyyy = stoi(temp3);


				}
			}
			cout << "\n";
		}
		
		
	}
	cout << "Student details added to current student! To View or Edit them, go back to the Student Menu\n";
	
	if (found == false)
	{
		cout << "\nStudent not found!\n";
	}
	system("pause");
	clearScreen();
	
	

}

void
Student::studentFound(Student& s, bool &found) // Searches the text file and returns true if found
{
	string preSearch = "Student ID: ";
	string line;
	size_t pos;
	ifstream studentfile("students.txt");

	if (studentfile.fail())
	{
		cout << "Input file opening failed.\n";
		exit(1);
	}

	preSearch += to_string(s.studentID); // adds the students ID to the string to get a more precise search
	while (!studentfile.eof())
	{
		getline(studentfile, line);
		pos = line.find(preSearch);
		if (pos != string::npos)
			found = true;
	}
}