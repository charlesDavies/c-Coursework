#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Date {
	int dd;
	int mm;
	int yyyy;
	string dateOfBirth;
	
public:
	void showDate();
	void getDate(int &dd, int &mm, int &yyyy);
	
	
	
};

void
Date::showDate()
{
	cout << dd << "/" << mm << "/" << yyyy;
}


void
Date::getDate(int &dd, int &mm, int &yyyy) // function to get date of birth from user
{
	cout << "Please enter day of date: ";
	cin >> dd;

	while (dd > 31 || dd < 1) // preventing any invalid days
	{
		cout << "Oops! Seems you entered a wrong day! Try again!\n";
		cin >> dd;
	}

	cout << "Please enter month of date: ";
	cin >> mm;

	while (mm > 12 || mm < 1) // preventing any invalid months
	{
		cout << "Oops! Seems you entered a wrong month! Try again!\n";
		cin >> mm;
	}

	cout << "Please enter year of date: ";
	cin >> yyyy;
}