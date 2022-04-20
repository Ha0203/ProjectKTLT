#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void enrollCourse(Year*&firstYear, Account*&userAcc)
{
	string temp;
	cout << "\nInput the school year of yours (Ex: 2021-2022): ";
	cin >> temp;
	Year* curYear = firstYear;
	while (curYear != nullptr && curYear->nameYear != temp)
	{
		curYear = curYear->next;
	}
	if(curYear == nullptr)
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
start:
	Course* curCourse = curSemester->firstCourse;
	system("cls");
	cout << "\n\t\t\t\t------------------COURSES IN THIS SEMESTER------------------\n\n";
	cout << '\t'<<setw(14) << left << "Course ID";
	cout << setw(26) << left << "Course Name";
	cout << setw(11) << left << "Credit";
	cout << setw(13) << left << "Students";
	cout << setw(15) << left << "Session 1";
	cout << setw(15) << left << "Session 2";
	cout << "Teacher";
	while (curCourse != nullptr)
	{
		cout << endl;
		cout <<'\t'<< setw(14) << left << curCourse->courseID;
		cout << setw(26) << left << curCourse->courseName;
		cout << setw(11) << left << curCourse->numberOfCredit;
		cout << setw(13) << left << curCourse->numberOfStudents;
		cout << setw(15) << left << curCourse->session1;
		cout << setw(15) << left << curCourse->session2;
		cout << curCourse->teacherName;
		curCourse = curCourse->next;
	}
next:
	cout << endl << endl << endl << endl;
	cout << "\tPress 1 to \tENROLL A NEW COURSE\n";
	cout << "\tPress 2 to \tVIEW A LIST OF ENROLLED COURSES\n";
	cout << "\tPress 3 to \tDELETE AN ENROLLED COURSE\n";
	cout << "\tPress 4 to \tGO BACK\n";
	cout << "\t[ Your choice ]:";
	int choice;
choose:
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		if (curSemester->registSession == 0)
		{
			cout << "\nNot in the course registration session.";
			return;
		}
		curCourse = curSemester->firstCourse;
		system("cls");
		cout << "\n\t\t\t\t------------------COURSES IN THIS SEMESTER------------------\n\n";
		cout << '\t' << setw(14) << left << "Course ID";
		cout << setw(26) << left << "Course Name";
		cout << setw(11) << left << "Credit";
		cout << setw(13) << left << "Students";
		cout << setw(15) << left << "Session 1";
		cout << setw(15) << left << "Session 2";
		cout << "Teacher";
		while (curCourse != nullptr)
		{
			cout << endl;
			cout << '\t' << setw(14) << left << curCourse->courseID;
			cout << setw(26) << left << curCourse->courseName;
			cout << setw(11) << left << curCourse->numberOfCredit;
			cout << setw(13) << left << curCourse->numberOfStudents;
			cout << setw(15) << left << curCourse->session1;
			cout << setw(15) << left << curCourse->session2;
			cout << curCourse->teacherName;
			curCourse = curCourse->next;
		}
		cout << "\n\n\n\tInput the course ID you want to enroll: ";
		string temp;
		cin >> temp;
		curCourse = curSemester->firstCourse;
		while (curCourse != nullptr && curCourse->courseID != temp)
		{
			curCourse = curCourse->next;
		}
		if (curCourse == nullptr)
		{
			cout << "\n\tThis course has not been created yet.\n\t";
			system("pause");
			goto start;
			break;
		}
		if (checkexistCourse(curYear,curSemester,curCourse,userAcc) == true)
		{
			cout << "\n\tYou have already enrolled this course.\n\t";
			system("pause");
			goto start;
			break;
		}
		if (checkCourse(curYear,curSemester,curCourse,userAcc) == false)
		{
			cout << "\n\tThis course is conflicted.\n\t";
			system("pause");
			goto start;
			break;
		}
		if (checkNumCourse(curYear,curSemester,userAcc) == false)
		{
			cout << "\n\tYou can only enroll at most 5 courses.\n\t";
			system("pause");
			break;
		}
		if (checkNumStu(curCourse) == false)
		{
			cout << "\n\tThis course has full slots.\n\t";
			system("pause");
			goto start;
			break;
		}
		updateMyC(curYear,curSemester,curCourse, userAcc);
		putStuInCourse(curCourse, userAcc);
	}
	case 2:
	{
		Year* myY = userAcc->firstYear;
		while (myY != nullptr && myY->nameYear != curYear -> nameYear)
		{
			myY = myY->next;
		}
		if (myY == nullptr)
		{
			cout << "\n\tYou have not enrolled any courses.\n\t";
			system("pause");
			goto start;
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
			goto start;
		}
		Course* myC = mySe->firstCourse;
		if (myC == nullptr)
		{
			cout << "\n\tYou have not enrolled any courses.\n\t";
			system("pause");
			goto start;
		}
		system("cls");
		cout << "\n\t\t\t\t------------------YOUR ENROLLED COURSES------------------\n\n";
		cout << '\t'<<setw(14) << left << "Course ID";
		cout << setw(26) << left << "Course Name";
		cout << setw(11) << left << "Credit";
		cout << setw(13) << left << "Students";
		cout << setw(15) << left << "Session 1";
		cout << setw(15) << left << "Session 2";
		cout << "Teacher";
		while (myC != nullptr)
		{
			cout << endl;
			cout << '\t'<<setw(14) << left << myC->courseID;
			cout << setw(26) << left << myC->courseName;
			cout << setw(11) << left << myC->numberOfCredit;
			cout << setw(13) << left << myC->numberOfStudents;
			cout << setw(15) << left << myC->session1;
			cout << setw(15) << left << myC->session2;
			cout << myC->teacherName;
			myC = myC->next;
		}
		cout << endl<<'\t';
		system("pause");
		goto start;
	}
	case 3:
	{
		if (curSemester->registSession == 0)
		{
			cout << "\nNot in the course registration session.";
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
			goto start;
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
			goto start;
		}
		Course* myC = mySe->firstCourse;
		if (myC == nullptr)
		{
			cout << "\n\tYou have not enrolled any courses.\n\t";
			system("pause");
			goto start;
		}
		system("cls");
		cout << "\n\t\t\t\t------------------YOUR ENROLLED COURSES------------------\n\n";
		cout << '\t' << setw(14) << left << "Course ID";
		cout << setw(26) << left << "Course Name";
		cout << setw(11) << left << "Credit";
		cout << setw(13) << left << "Students";
		cout << setw(15) << left << "Session 1";
		cout << setw(15) << left << "Session 2";
		cout << "Teacher";
		while (myC != nullptr)
		{
			cout << endl;
			cout << '\t' << setw(14) << left << myC->courseID;
			cout << setw(26) << left << myC->courseName;
			cout << setw(11) << left << myC->numberOfCredit;
			cout << setw(13) << left << myC->numberOfStudents;
			cout << setw(15) << left << myC->session1;
			cout << setw(15) << left << myC->session2;
			cout << myC->teacherName;
			myC = myC->next;
		}
		cout << endl;
		cout << "\n\n\tInput the course ID you want to remove: ";
		string temp;
		cin >> temp;
		Course* curCourse = curSemester->firstCourse;
		while (curCourse != nullptr && curCourse->courseID != temp)
		{
			curCourse = curCourse->next;
		}
		if (curCourse == nullptr)
		{
			cout << "\n\tThis course has not been created yet.\n\t";
			system("pause");
			goto start;
			break;
		}
		if (checkexistCourse(curYear,curSemester,curCourse,userAcc) == 0)
		{
			cout << "\n\tDon't have this course in your enrolled list to remove.\n\t";
			system("pause");
			goto start;
			break;
		}
		myC = mySe->firstCourse;
		if (myC->courseID == curCourse->courseID)
		{
			mySe->firstCourse = myC->next;
			delete myC;
		}
		else
		{
			while (myC->next->courseID != curCourse->courseID)
			{
				myC = myC->next;
			}
			Course* temp = myC->next;
			myC->next = myC->next->next;
			delete temp;
		}
		courseStudent* curStu = curCourse->firstcourseStudent;
		if (curStu->studentID == userAcc->myInfo->studentID)
		{
			curCourse->firstcourseStudent = curStu->next;
			delete curStu;
		}
		else
		{
			while (curStu->next->studentID != userAcc->myInfo->studentID)
			{
				curStu = curStu->next;
			}
			courseStudent* temp = curStu->next;
			curStu->next = curStu->next->next;
			delete temp;
		}
		goto start;
	}
	case 4:
		break;
	default:
	{
		cout << "\tInvalid choice! Please enter your choice again: ";
		goto choose;
	}
	}
}
bool checkCourse(Year*curY,Semester*curSe,Course* curC, Account* userAcc)
{
	Year* myY = userAcc->firstYear;
	while (myY != nullptr && myY->nameYear != curY->nameYear)
		myY = myY->next;
	if (myY == nullptr)
		return 1;
	Semester* mySe = myY->firstSemester;
	while (mySe != nullptr && mySe->nameSemester != curSe->nameSemester)
		mySe = mySe->next;
	if (mySe == nullptr)
		return 1;
	Course* myC = mySe->firstCourse;
	if (myC == nullptr)
	{
		return 1;
	}
	while (myC != nullptr)
	{
		if (myC->session1 == curC->session1 || myC->session1 == curC->session2 || myC->session2 == curC->session1 || myC->session2 == curC->session2)
		{
			return 0;
		}
		myC = myC->next;
	}
	return 1;
}
bool checkNumCourse(Year*curY,Semester*curSe,Account* userAcc)
{
	Year* myY = userAcc->firstYear;
	while (myY != nullptr && myY->nameYear != curY->nameYear)
		myY = myY->next;
	if (myY == nullptr)
		return 1;
	Semester* mySe = myY->firstSemester;
	while (mySe != nullptr && mySe->nameSemester != curSe->nameSemester)
		mySe = mySe->next;
	if (mySe == nullptr)
		return 1;
	Course* myC = mySe->firstCourse;
	int n = 0;
	while (myC != nullptr)
	{
		n++;
		myC = myC->next;
	}
	if (n >= 5)
		return 0;
	else 
		return 1;
}
bool checkNumStu(Course* cur)
{
	int n = 0;
	courseStudent* curStu = cur->firstcourseStudent;
	while (curStu != nullptr)
	{
		n++;
		curStu = curStu->next;
	}
	if (n < 50)
		return 1;
	else
		return 0;
}
void updateMyC(Year*curYear,Semester*curSemester,Course* curCourse, Account* userAcc)
{
	Year* myY = userAcc->firstYear;
	while (myY != nullptr && myY->nameYear != curYear->nameYear)
	{
		myY = myY->next;
	}
	if (myY == nullptr)
	{
		myY = new Year;
		myY->next = userAcc->firstYear;
		userAcc->firstYear = myY;
		myY->nameYear = curYear->nameYear;
	}
	Semester* mySe = myY->firstSemester;
	while (mySe != nullptr && mySe->nameSemester != curSemester->nameSemester)
	{
		mySe = mySe->next;
	}
	if (mySe == nullptr)
	{
		mySe = new Semester;
		mySe->next = myY->firstSemester;
		myY->firstSemester = mySe;
		mySe->nameSemester = curSemester->nameSemester;
	}
	Course* myC = new Course;
	myC->next = mySe->firstCourse;
	mySe->firstCourse = myC;
	myC->courseID = curCourse->courseID;
	myC->courseName = curCourse->courseName;
	myC->teacherName = curCourse->teacherName;
	myC->numberOfCredit = curCourse->numberOfCredit;
	myC->numberOfStudents = curCourse->numberOfStudents;
	myC->session1 = curCourse->session1;
	myC->session2 = curCourse->session2;
}
void putStuInCourse(Course* cur, Account* userAcc)
{
	courseStudent* curStu = cur->firstcourseStudent;
	if (cur->firstcourseStudent == nullptr)
	{
		cur->firstcourseStudent = new courseStudent;
		curStu = cur->firstcourseStudent;
		curStu->next = nullptr;
	}
	else
	{
		while (curStu->next != nullptr)
		{
			curStu = curStu->next;
		}
		curStu->next = new courseStudent;
		curStu = curStu->next;
		curStu->next = nullptr;
	}
	curStu->studentID = userAcc->myInfo->studentID;
	curStu->firstName = userAcc->myInfo->firstName;
	curStu->lastName = userAcc->myInfo->lastName;
	curStu->gender = userAcc->myInfo->gender;
	curStu->dateOfBirth = userAcc->myInfo->dateOfBirth;
	curStu->socialID = userAcc->myInfo->socialID;
}
bool checkexistCourse(Year*curY,Semester*curSe,Course* curC, Account* userAcc)
{
	Year* myY = userAcc->firstYear;
	while (myY != nullptr && myY->nameYear != curY->nameYear)
		myY = myY->next;
	if (myY == nullptr)
		return 0;
	Semester* mySe = myY->firstSemester;
	while (mySe != nullptr && mySe->nameSemester != curSe->nameSemester)
		mySe = mySe->next;
	if (mySe == nullptr)
		return 0;
	Course* myC = mySe->firstCourse;
	while (myC != nullptr && myC->courseID != curC->courseID)
		myC = myC->next;
	if (myC == nullptr)
		return 0;
	return 1;
}