#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void enrollCourse(Year*&firstYear, Account*&userAcc)
{
	string temp;
	cout << "\nInput the school year of yours";
	cin >> temp;
	Year* curYear = firstYear;
	while (curYear != nullptr && curYear->nameYear != temp)
	{
		curYear = curYear->next;
	}
	if(curYear==nullptr)
	{
		cout << "\nThis year has not been created yet";
		return;
	}
	cout << "\nInput the name of semester";
	cin >> temp;
	Semester* curSemester = curYear->firstSemester;
	while (curSemester != nullptr && curSemester->nameSemester != temp)
	{
		curSemester = curSemester->next;
	}
	if (curSemester == nullptr)
	{
		cout << "\nThis semester has not been created yet";
		return;
	}
	cout << "\nHere is  the list of courses in this semester";
	Course* curCourse = curSemester->firstCourse;
	cout << "\nCourse ID\t" << "Course Name\t\t" << "Teacher Name\t" << "Number of Credits\t" << "The Number Of Student\t" << "Session1\t" << "Session2\n";
	while (curCourse != nullptr)
	{
		cout << curCourse->courseID << "\t" << curCourse->courseName << "\t" << curCourse->teacherName << "\t" << curCourse->numberOfCredit << "\t" << curCourse->numberOfStudents << "\t" << curCourse->session1 << "\t" << curCourse->session2 << "\n";
		curCourse = curCourse->next;
	}
next:
	cout << endl;
	cout << "Press 1 to \tENROLL A NEW COURSE\n";
	cout << "Press 2 to \tVIEW A LIST OF ENROLLED COURSES\n";
	cout << "Press 3 to \tDELETE A ENROLLED COURSE\n";
	cout << "Your choice: ";
	int choice;
choose:
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "\nInput the course'ID you want to enroll";
		string temp;
		cin >> temp;
		Course* curCourse = curSemester->firstCourse;
		while (curCourse != nullptr && curCourse->courseID != temp)
		{
			curCourse = curCourse->next;
		}
		if (curCourse == nullptr)
		{
			cout << "\nThis course has not been created yet";
			break;
		}
		//Xem course co thoa man hay k
		if (checkexistCourse(curCourse,userAcc) == true)
		{
			cout << "\nYou have already enrolled this course";
			break;
		}
		if (checkCourse(curCourse,userAcc) == false)
		{
			cout << "\nThis course is conflicted";
			break;
		}
		if (checkNumCourse(userAcc) == false)
		{
			cout << "\nYou canonly enroll at most 5 courses";
			break;
		}
		if (checkNumStu(curCourse) == false)
		{
			cout << "\nThis course has full slots";
			break;
		}
		//Cap nhat course vao du lieu cua sinh vien
		updateMyC(curCourse, userAcc);
		putStuInCourse(curCourse, userAcc);
	}
	case 2:
	{
		cout << "\nThe list of enrolled courses is" << endl;
		copyCourse* cur = userAcc->myInfo->firstCourse;
		cout << "\nCourse ID\t" << "Course Name\t\t" << "Teacher Name\t" << "Number of Credits\t" << "The Number Of Student\t" << "Session1\t" << "Session2\n";
		while (cur != nullptr)
		{
			cout << curCourse->courseID << "\t" << curCourse->courseName << "\t" << curCourse->teacherName << "\t" << curCourse->numberOfCredit << "\t" << curCourse->numberOfStudents << "\t" << curCourse->session1 << "\t" << curCourse->session2 << "\n";
			cur = cur->next;
		}
		break;
	}
	case 3:
	{
		cout << "\nInput the course'ID you want to remove";
		string temp;
		cin >> temp;
		Course* curCourse = curSemester->firstCourse;
		while (curCourse != nullptr && curCourse->courseID != temp)
		{
			curCourse = curCourse->next;
		}
		if (curCourse == nullptr)
		{
			cout << "\nThis course has not been created yet";
			break;
		}
		if (checkexistCourse == false)
		{
			cout << "\nDon't have this course in your enrolled list to remove";
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
		break;
	}
	default:
	{
		cout << "Invalid choice! Please enter your choice again: ";
		goto choose;
	}
	}
again:
	cout << "\nDo you want to continue the program (Y/N)?";
	char dec;
	cin >> dec;
	if (dec == 'Y')
		goto next;
	else if (dec == 'N')
	{
		return;
	}
	else
	{
		cout << "\nInvalid choice! Please enter your choice again: ";
		goto again;
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