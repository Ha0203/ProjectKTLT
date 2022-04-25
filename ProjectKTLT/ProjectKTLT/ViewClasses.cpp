#include "file.h"

void viewClass(Year* year)
{
	if (!year)
	{
		cout << "\nNo information.";
		return;
	}
	string yeartemp;
	string semestertemp;
	cout << "Please enter the school year you want to access (Ex: 2021-2022): ";
	cin >> yeartemp;
	Year* cur1 = year;
	while (cur1 && cur1->nameYear != yeartemp)
		cur1 = cur1->next;
	if (!cur1)
	{
		cout << "\nThis year has not been created yet";
		return;
	}
	cout << "\nClasses in " << cur1->nameYear << ": ";
	Class* curClass = cur1->firstClass;
	while (curClass)
	{
		cout << "\n" << curClass->nameClass;
		curClass = curClass->next;
	}
	cout << endl;
}

void viewStuClass(Year* year)
{
	if (!year)
	{
		cout << "\nNo information.";
		return;
	}
	string temp;
	cout << "Please enter the school year you want to access (Ex: 2021-2022): ";
	cin >> temp;
	Year* cur1 = year;
	while (cur1 && cur1->nameYear != temp)
		cur1 = cur1->next;
	if (!cur1)
	{
		cout << "\nThis year has not been created yet";
		return;
	}
	cout << "Which class you want to view the list of students: ";
	cin >> temp;
	Class* cur = cur1->firstClass;
	while (cur && cur->nameClass != temp)
		cur = cur->next;
	if (!cur)
	{
		cout << "\nThis class has not been created yet";
		return;
	}
	cout << setw(5) << left << "No.";
	cout << setw(15) << left << "Student ID";
	cout << setw(15) << left << "First Name";
	cout << setw(15) << left << "Last Name";
	cout << setw(10) << left << "Gender";
	cout << setw(15) << left << "D.O.B";
	cout << setw(15) << left << "Social ID";
	cout << "\n---------------------------------------------------------------------------------------";
	int i = 1;
	Student* cur2 = cur->firstStudent;
	while (cur2)
	{
		cout << endl;
		cout << setw(5) << left << i++;
		cout << setw(15) << left << cur2->studentID;
		cout << setw(15) << left << cur2->firstName;
		cout << setw(15) << left << cur2->lastName;
		cout << setw(10) << left << cur2->gender;
		cout << setw(15) << left << cur2->dateOfBirth;
		cout << setw(15) << left << cur2->socialID;
		cur2 = cur2->next;
	}
	cout << endl;
}

void viewStuCourse(Year* year)
{
	if (!year)
	{
		cout << "\nNo information.";
		return;
	}
	string temp;
	cout << "Please enter the school year you want to access (Ex: 2021-2022): ";
	cin.ignore();
	getline(cin, temp);
	Year* cur1 = year;
	while (cur1 && cur1->nameYear != temp)
		cur1 = cur1->next;
	if (!cur1)
	{
		cout << "\nInvalid year! Please try again.";
		return;
	}
	cout << "Which semester you want to access: ";
	getline(cin, temp);
	Semester* cur = cur1->firstSemester;
	while (cur && cur->nameSemester != temp)
		cur = cur->next;
	if (!cur)
	{
		cout << "\nInvalid semester! Please try again.";
		return;
	}
	cout << "Input course ID you want to see the list of students: ";
	getline(cin, temp);
	Course* cur2 = cur->firstCourse;
	while (cur2 && cur2->courseID != temp)
		cur2 = cur2->next;
	if (!cur2)
	{
		cout << "\nInvalid course! Please try again.";
		return;
	}
	courseStudent* stu = cur2->firstcourseStudent;
	cout << setw(5) << left << "No.";
	cout << setw(15) << left << "Student ID";
	cout << setw(15) << left << "First Name";
	cout << setw(15) << left << "Last Name";
	cout << setw(10) << left << "Gender";
	cout << setw(15) << left << "D.O.B";
	cout << setw(15) << left << "Social ID";
	cout << "\n---------------------------------------------------------------------------------------";
	int i = 1;
	while (stu)
	{
		cout << endl;
		cout << setw(5) << left << i++;
		cout << setw(15) << left << stu->studentID;
		cout << setw(15) << left << stu->firstName;
		cout << setw(15) << left << stu->lastName;
		cout << setw(10) << left << stu->gender;
		cout << setw(15) << left << stu->dateOfBirth;
		cout << setw(15) << left << stu->socialID;
		stu = stu->next;
	}
}