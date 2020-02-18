#pragma once
#include "dateClass.h"
#include "studentClass.h"
#include <vector>
#include <iostream>


class Course {
public:
	bool courseMenu(Course& c);
	void addCourse(Course& c);
	void viewCourse(Course& c);
	void saveCourse(Course& c);
	
private:
	int courseId = 0;
	char courseName[256];
    int creditValue;
	Date courseStartDate;
	int startDD;
	int startMM;
	int startYYYY;
	Date courseEndDate;
	int endDD;
	int endMM;
	int endYYYY;
	char level[1];
	// TODO - ADD MORE COURSE DETAILS SUCH AS ASSESSMENTS AND GRADE STUFF
};

bool
Course::courseMenu(Course& c)
{
	bool contine = true;
	int choice;

	while (contine)
	{
		cout << "Please choose what you are interested in:\n";
		cout << "1.Add Course\n";
		cout << "2.View Course\n";
		cout << "3.Remove Course\n";
		cout << "4.Search for Course\n";
		cout << "5.Save Course\n";
		cout << "6.Return to previous menu\n";
		cout << "Enter choice here: ";
		cin >> choice;
		clearScreen();

		switch (choice)
		{
		case 1:
			c.addCourse(c);
			break;
		case 2:
			c.viewCourse(c);
			break;
		case 3:
			cout << "NOT IMPLEMENTED, WOULD REMOVE COURSE?\n";
			break;
		case 4:
			cout << "NOT IMPLEMENTED, WOULD SEARCH FOR COURSE\n";
			break;
		case 5:
			c.saveCourse(c);
			break;
		case 6:
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
Course::addCourse(Course& c)
{
	clearScreen();
	cout << "ADDING COURSE\n";
	cout << "Please enter Course Code: ";
	cin >> c.courseId;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore();
		cout << "Invalid input. Please only enter intergers\n";
		cout << "Please enter Course Code: ";
		cin >> c.courseId;
	}
	cout << "Please enter Course Name: ";
	cin.clear();
	cin.ignore();
	cin.getline(c.courseName, 256);
	cout << "Please enter Credit Value, 60 Credits or 120 Credits: ";
	cin >> c.creditValue;
	while (c.creditValue != 60 && c.creditValue != 120)
	{
		cout << "Error, only available credit values are 60 or 120.\n";
		cout << "Please enter Credit Value: ";
		cin.clear();
		cin.ignore();
		cin >> c.creditValue;
	}
	cout << "Please enter Course Start Date: ";
	courseStartDate.getDate(startDD, startMM, startYYYY);
	cout << "Please enter Course End Date: ";
	courseEndDate.getDate(endDD, endMM, endYYYY);
	cout << "Please enter Course Level: ";
	cin >> c.level;
	while (c.level[0] != 'H' && c.level[0] != 'C' && c.level[0] != 'I')
	{
		cout << "Error, only available levels are C, I, H.\n";
		cout << "Please enter course level: ";
		cin.clear();
		cin.ignore();
		cin >> c.level;
	}
	cout << "Adding Course";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << "\nCourse Added!\n";
	clearScreen();
}

void
Course::viewCourse(Course& c)
{
	if (c.courseId == 0)
	{
		cout << "No Course has been added yet.\n";
		system("pause");
		clearScreen();
	}
	else
	{
		cin.ignore();
		cin.clear();
		cout << "COURSE DETAILS\n";
		cout << "Course Code: " << c.courseId << "\n";
		cout << "Course Name:  " << c.courseName << "\n";
		cout << "Course Credit Value: " << c.creditValue << " credits.\n";
		cout << "Course Start Date: " << c.startDD << "/" << c.startMM << "/" << c.startYYYY << endl;
		cout << "Course End Date: " << c.endDD << "/" << c.endMM << "/" << c.endYYYY << endl;
		cout << "Course Level: " << c.level << "\n";
		cin.ignore();
		system("pause");
		clearScreen();
	}
}

void
Course::saveCourse(Course& c)
{
	
	if (c.courseId == 0) // A check to make sure a course record has been inputted before saving
	{
		
		cout << "No Course has been inputted! Saving failed.\n";
		system("pause");
		clearScreen();
	}
	else
	{
		cout << "Saving Course";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << "\nCourse Saved!\n";
		
		ofstream myfile("courses.txt", fstream::app);
		if (myfile.is_open())
		{
			myfile << "Course ID: " << c.courseId << " \n";
			myfile << "Course Name: " << c.courseName << " \n";
			myfile << "Course Credit Value: " << c.creditValue << " \n";
			if (c.startDD < 10) // Attempt to fix stoi error
				myfile << "Course Start Date: " << "0" << c.startDD << "/" << c.startMM << "/" << c.startYYYY << " \n";
			else
				myfile << "Course Start Date: " << c.startDD << "/" << c.startMM << "/" << c.startYYYY << " \n";

			if (c.endDD < 10) // Attempt to fix stoi error
				myfile << "Course End Date: " << "0" << c.endDD << "/" << c.endMM << "/" << c.endYYYY << " \n";
			else
				myfile << "Course End Date: " << c.endDD << "/" << c.endMM << "/" << c.endYYYY << " \n";
			myfile << "Course Level: " << c.level << "\n";
			myfile << "\n\n";
			myfile.close();
		}
		else cout << "Unable to open file";

		ofstream numberfile("coursenumber.txt", fstream::app); // Saves to to files, but only saves the name and ID to the second file. 
		if (numberfile.is_open())
		{
			numberfile << c.courseName<< ": " << c.courseId << "\n";
			numberfile.close();
		}
		else cout << "Unable to open file";


		std::ifstream  inFile("courses.txt"); // Makes a copy of the file everytime you save as a back up file just incase
		std::ofstream  outFile("tempscourses.txt");
		outFile << inFile.rdbuf();

		system("pause");
		clearScreen();
	}

}