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
	if (curSemester->registSession == 0)
	{
		cout << "\nNot in the course registration session.";
		return;
	}
	//Phi
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
		//Xem course co thoa man hay k
		if (checkexistCourse(curCourse,userAcc) == true)
		{
			cout << "\n\tYou have already enrolled this course.\n\t";
			system("pause");
			goto start;
			break;
		}
		if (checkCourse(curCourse,userAcc) == false)
		{
			cout << "\n\tThis course is conflicted.\n\t";
			system("pause");
			goto start;
			break;
		}
		if (checkNumCourse(userAcc) == false)
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
		//Cap nhat course vao du lieu cua sinh vien
		updateMyC(curCourse, userAcc);
		putStuInCourse(curCourse, userAcc);
	}
	case 2:
	{
		copyCourse* cur = userAcc->myInfo->firstCourse;
		if (cur == nullptr)
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
		while (cur != nullptr)
		{
			cout << endl;
			cout << '\t'<<setw(14) << left << cur->courseID;
			cout << setw(26) << left << cur->courseName;
			cout << setw(11) << left << cur->numberOfCredit;
			cout << setw(13) << left << cur->numberOfStudents;
			cout << setw(15) << left << cur->session1;
			cout << setw(15) << left << cur->session2;
			cout << cur->teacherName;
			cur = cur->next;
		}
		cout << endl<<'\t';
		system("pause");
		goto start;
	}
	case 3:
	{
		copyCourse* cur = userAcc->myInfo->firstCourse;
		system("cls");
		cout << "\n\t\t\t\t------------------YOUR ENROLLED COURSES------------------\n\n";
		cout << '\t'<<setw(14) << left << "Course ID";
		cout << setw(26) << left << "Course Name";
		cout << setw(11) << left << "Credit";
		cout << setw(13) << left << "Students";
		cout << setw(15) << left << "Session 1";
		cout << setw(15) << left << "Session 2";
		cout << "Teacher";
		while (cur != nullptr)
		{
			cout << endl;
			cout << '\t'<<setw(14) << left << cur->courseID;
			cout << setw(26) << left << cur->courseName;
			cout << setw(11) << left << cur->numberOfCredit;
			cout << setw(13) << left << cur->numberOfStudents;
			cout << setw(15) << left << cur->session1;
			cout << setw(15) << left << cur->session2;
			cout << cur->teacherName;
			cur = cur->next;
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
		if (checkexistCourse == 0)
		{
			cout << "\n\tDon't have this course in your enrolled list to remove.\n\t";
			system("pause");
			goto start;
			break;
		}
		copyCourse* myC = userAcc->myInfo->firstCourse;
		if (myC->courseID == curCourse->courseID)
		{
			userAcc->myInfo->firstCourse = myC->next;
			delete myC;
		}
		else
		{
			while (myC->next->courseID != curCourse->courseID)
			{
				myC = myC->next;
			}
			copyCourse* temp = myC->next;
			myC = myC->next->next;
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
bool checkCourse(Course* cur, Account* userAcc)
{
	copyCourse* myC = userAcc->myInfo->firstCourse;
	if (myC == nullptr)
	{
		return 1;
	}
	while (myC != nullptr)
	{
		if (myC->session1 == cur->session1 || myC->session1 == cur->session2 || myC->session2 == cur->session1 || myC->session2 == cur->session2)
		{
			return 0;
		}
		myC = myC->next;
	}
	return 1;
}
bool checkNumCourse(Account* userAcc)
{
	copyCourse* myC = userAcc->myInfo->firstCourse;
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
void updateMyC(Course* cur, Account* userAcc)
{
	copyCourse* myC = userAcc->myInfo->firstCourse;
	if (myC == nullptr)
	{
		userAcc->myInfo->firstCourse = new copyCourse;
		myC = userAcc->myInfo->firstCourse;
	}
	else
	{
		while (myC->next != nullptr)
			myC = myC->next;
		myC->next = new copyCourse;
		myC = myC->next;
	}
	myC->next = nullptr;
	myC->courseID = cur->courseID;
	myC->courseName = cur->courseName;
	myC->teacherName = cur->teacherName;
	myC->numberOfCredit = cur->numberOfCredit;
	myC->numberOfStudents = cur->numberOfStudents;
	myC->session1 = cur->session1;
	myC->session2 = cur->session2;
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
bool checkexistCourse(Course* cur, Account* userAcc)
{
	copyCourse* myC = userAcc->myInfo->firstCourse;
	if (myC == nullptr)
		return 0;
	else
	{
		while (myC != nullptr)
		{
			if (myC->courseID == cur->courseID)
				return 1;
			myC = myC->next;
		}
	}
	return 0;
}