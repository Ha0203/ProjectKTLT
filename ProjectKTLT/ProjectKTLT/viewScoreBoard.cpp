#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void viewCourseScore(Year* firstYear)
{
	string temp;
	cout << "\nInput the school year (Ex: 2021-2022): ";
	cin >> temp;
	Year* curYear = firstYear;
	while (curYear != nullptr && curYear->nameYear != temp)
	{
		curYear = curYear->next;
	}
	if (curYear == nullptr)
	{
		cout << "\nThis year has not been created yet.";
		return;
	}
	cout << "\nInput the name of semester (Ex: Fall): ";
	cin >> temp;
	Semester* curSemester = curYear->firstSemester;
	while (curSemester != nullptr && curSemester->nameSemester != temp)
	{
		curSemester = curSemester->next;
	}
	if (curSemester == nullptr)
	{
		cout << "\nThis semester has not been created yet.";
		return;
	}
	cout << "\nInput the ID of the course: ";
	cin >> temp;
	Course*curCourse = curSemester->firstCourse;
	while (curCourse != nullptr && curCourse->courseID != temp)
	{
		curCourse = curCourse->next;
	}
	if (curCourse == nullptr)
	{
		cout << "\n\tThis course has not been created yet.";
		return;
	}
	//Phi
	courseStudent* curStu = curCourse->firstcourseStudent;
	cout << setw(15) << left << "Number";
	cout << setw(15) << left << "StudentID";
	cout << setw(15) << left << "FirstName";
	cout << setw(15) << left << "LastName";
	cout << setw(15) << left << "TotalMark";
	cout << setw(15) << left << "MidtermMark";
	cout << setw(15) << left << "FinalMark";
	while (curStu != nullptr)
	{
		cout << endl;
		cout << setw(15) << left << curStu->Number;
		cout << setw(15) << left << curStu->studentID;
		cout << setw(15) << left << curStu->firstName;
		cout << setw(15) << left << curStu->lastName;
		cout << setw(15) << left << curStu->mark.total;
		cout << setw(15) << left << curStu->mark.mid;
		cout << setw(15) << left << curStu->mark.final;
		curStu = curStu->next;
	}
}
//Phi dựa trên hàm update trong ViewCourses.cpp
void updateScore(Year* firstYear)
{
	if (!firstYear)
	{
		cout << "\nNo information.";
		return;
	}
	string temp;
	cout << "Please enter the school year you want to access (Ex: 2021-2022): ";
	cin.ignore();
	getline(cin, temp);
	Year* cur1 = firstYear;
	while (cur1 && cur1->nameYear != temp)
		cur1 = cur1->next;
	if (!cur1)
	{
		cout << "\nInvalid year! Please try again.";
		return; 
	}
	cout << "Which semester you want to access: ";
	getline(cin, temp);
	Semester* cur = firstYear->firstSemester;
	while (cur && cur->nameSemester != temp)
		cur = cur->next;
	if (!cur)
	{
		cout << "\nInvalid semester! Please try again.";
		return;
	}
	cout << "Which course you want to access: ";
	getline(cin, temp);
	Course* cur2 = cur->firstCourse;
	while (cur2 && cur2->courseName != temp)
		cur2 = cur2->next;
	if (!cur2)
	{
		cout << "\nInvalid course! Please try again.";
		return;
	}
	string StuID;
	cout << "Please enter the Student's ID of the one you want to update result: ";
	cin >> StuID;
	courseStudent* curStu = cur2->firstcourseStudent;
	while (curStu && curStu->studentID != StuID)
		curStu = curStu->next;
	if (!curStu)
	{
		cout << "Invalid student! Please try again";
		return;
	}
	int mark;
	cout << "Total Mark: ";
	cin >> mark;
	curStu->mark.total = mark;
	cout << "Mid: ";
	cin >> mark;
	curStu->mark.mid = mark;
	cout << "Final: ";
	cin >> mark;
	curStu->mark.final = mark;
	cout << "\nContent updated successfully";
}
//Phi
void viewMyScore(Account*userAcc, Year* firstYear)
{
	string temp;
	cout << "\nInput the school year of yours (Ex: 2021-2022): ";
	cin >> temp;
	Year* curYear = firstYear;
	while (curYear != nullptr && curYear->nameYear != temp)
	{
		curYear = curYear->next;
	}
	if (curYear == nullptr)
	{
		cout << "\nThis year has not been created yet.";
		return;
	}
	cout << "\nInput the name of semester (Ex: Fall): ";
	cin >> temp;
	Semester* curSemester = curYear->firstSemester;
	while (curSemester != nullptr && curSemester->nameSemester != temp)
	{
		curSemester = curSemester->next;
	}
	if (curSemester == nullptr)
	{
		cout << "\nThis semester has not been created yet.";
		return;
	}
	Year* myY = userAcc->firstYear;
	while (myY != nullptr && myY->nameYear != curYear->nameYear)
	{
		myY = myY->next;
	}
	if (myY == nullptr)
	{
		cout << "\n\tYou have not enrolled any courses.\n\t";
		system("pause");
		return;
	}
	Semester* mySe = myY->firstSemester;
	while (mySe != nullptr && mySe->nameSemester != curSemester->nameSemester)
	{
		mySe = mySe->next;
	}
	if (mySe == nullptr)
	{
		cout << "\n\tYou have not enrolled any courses.\n\t";
		system("pause");
		return;
	}
	Course* myC = mySe->firstCourse;
	if (myC == nullptr)
	{
		cout << "\n\tYou have not enrolled any courses.\n\t";
		system("pause");
		return;
	}
	system("cls");
	cout << "\n\t\t\t\t\t- - - - SCOREBOARD - - - -\n\n";
	cout << setw(15) << left << "CourseID";
	cout << setw(30) << left << "Course Name";
	cout << setw(23) << left << "Teacher Name";
	cout << setw(15) << left << "TotalMark";
	cout << setw(15) << left << "MidtermMark";
	cout << setw(15) << left << "FinalMark";
	cout << endl;
	cout << "-------------------------------------------------------------------------------------------------------------\n";
	while (myC)
	{
		cout << endl;
		cout << setw(15) << left << myC->courseID;
		cout << setw(30) << left << myC->courseName;
		cout << setw(23) << left << myC->teacherName;
		cout << setw(15) << left << myC->mark.total;
		cout << setw(15) << left << myC->mark.mid;
		cout << setw(15) << left << myC->mark.final;
		myC = myC->next;
	}
}