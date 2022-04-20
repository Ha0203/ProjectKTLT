#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <Windows.h>
using namespace std;
#include"ProjectKTLT/file.h"

void menu(Account* userAcc)
{
	Year* firstYear = nullptr;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int choice, choice1, choice2, choice3, choice4;
	readStudentListMain(firstYear);
	readSemesterList(firstYear);
	readCourseList(firstYear);
	if (userAcc->type == 1)
	{
		readCourseStudentList(firstYear, userAcc);
		importScoreBoard(firstYear, userAcc);
	back:
		system("cls");
		SetConsoleTextAttribute(h, 12);
		cout << "\n\t\t\t\t\t\t- - - - TASKS - - - -";
		SetConsoleTextAttribute(h, 7);
		cout << "\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * *";
		cout << "\n\t\t\t\t\t*\t   1. School Year\t    *";
		cout << "\n\t\t\t\t\t*\t   2. Classes\t\t    *";
		cout << "\n\t\t\t\t\t*\t   3. Courses\t\t    *";
		cout << "\n\t\t\t\t\t*\t   4. Scoreboard\t    *";
		cout << "\n\t\t\t\t\t*\t   5. Exit\t\t    *";
		cout << "\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * *";
	again7:
		SetConsoleTextAttribute(h, 12);
		cout << "\n\t\t\t\t\t[ Your choice ]: ";
		SetConsoleTextAttribute(h, 7);
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");
			SetConsoleTextAttribute(h, 12);
			cout << "\n\t\t\t\t\t\t- - - - SCHOOL YEAR - - - -";
			SetConsoleTextAttribute(h, 7);
			cout << "\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * *";
			cout << "\n\t\t\t\t\t*\t   1. Create School Year\t  *";//And update class for this school year
			cout << "\n\t\t\t\t\t*\t   2. Create Semester\t\t  *";
			cout << "\n\t\t\t\t\t*\t   3. Back\t\t\t  *";
			cout << "\n\t\t\t\t\t* * * * * * * * * * * * * * * * * * * * * *";
		again1:
			SetConsoleTextAttribute(h, 12);
			cout << "\n\t\t\t\t\t[ Your choice ]: ";
			SetConsoleTextAttribute(h, 7);
			cin >> choice1;
			switch (choice1)
			{
			case 1:
				system("cls");
				createSchoolYear(firstYear);
				cout << endl;
				system("pause");
				break;
			case 2:
				system("cls");
				createSemester(firstYear);
				cout << endl;
				system("pause");
				break;
			case 3:
				goto back;
			default:
				cout << "\n\t\t\t\t\tInvalid choice! Please try again.";
				goto again1;
				break;
			}
			goto back;
		case 2:
			system("cls");
			SetConsoleTextAttribute(h, 12);
			cout << "\n\t\t\t\t\t\t  - - - - CLASSES - - - -";
			SetConsoleTextAttribute(h, 7);
			cout << "\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
			cout << "\n\t\t\t\t*\t   1. Update Class\t\t\t\t  *";//For the available class
			cout << "\n\t\t\t\t*\t   2. View The List Of Classes\t\t\t  *";
			cout << "\n\t\t\t\t*\t   3. View The List Of Students In A Class\t  *";
			cout << "\n\t\t\t\t*\t   4. Back\t\t\t\t\t  *";
			cout << "\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
		again2:
			SetConsoleTextAttribute(h, 12);
			cout << "\n\t\t\t\t[ Your choice ]: ";
			SetConsoleTextAttribute(h, 7);
			cin >> choice2;
			switch (choice2)
			{
			case 1:
				system("cls");
				updateClass(firstYear);
				cout << endl;
				system("pause");
				break;
			case 2:
				system("cls");
				viewClass(firstYear);
				cout << endl;
				system("pause");
				break;
			case 3:
				system("cls");
				viewStuClass(firstYear);
				cout << endl;
				system("pause");
				break;
			case 4:
				goto back;
			default:
				cout << "\n\t\t\t\tInvalid choice! Please try again.";
				goto again2;
			}
			goto back;
		case 3:
			system("cls");
			SetConsoleTextAttribute(h, 12);
			cout << "\n\t\t\t\t\t\t  - - - - COURSES - - - -";
			SetConsoleTextAttribute(h, 7);
			cout << "\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
			cout << "\n\t\t\t\t*  \t   1. Create Course Registation Session\t\t    *";
			cout << "\n\t\t\t\t*  \t   2. View The List Of Courses\t\t\t    *";
			cout << "\n\t\t\t\t*  \t   3. View The List Of Students In A Courses\t    *";
			cout << "\n\t\t\t\t*  \t   4. Update Course Information\t\t\t    *";
			cout << "\n\t\t\t\t*  \t   5. Delete A Course\t\t\t\t    *";
			cout << "\n\t\t\t\t*  \t   6. Export The List Of Students In A Course\t    *";
			cout << "\n\t\t\t\t*  \t   7. Back\t\t\t\t\t    *";
			cout << "\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
		again3:
			SetConsoleTextAttribute(h, 12);
			cout << "\n\t\t\t\t[ Your choice ]: ";
			SetConsoleTextAttribute(h, 7);
			cin >> choice3;
			switch (choice3)
			{
			case 1:
				system("cls");
				courseRegist(firstYear);
				cout << endl;
				system("pause");
				break;
			case 2:
				system("cls");
				viewCourses(firstYear);
				cout << endl;
				system("pause");
				break;
			case 3:
				system("cls");
				viewStuCourse(firstYear);
				cout << endl;
				system("pause");
				break;
			case 4:
				system("cls");
				update(firstYear);
				cout << endl;
				system("pause");
				break;
			case 5:
				system("cls");
				deleteCourse(firstYear);
				cout << endl;
				system("pause");
				break;
			case 6:
				system("cls");
				exportCourseStudent(firstYear);
				cout << endl;
				system("pause");
				break;
			case 7:
				goto back;
			default:
				cout << "\n\t\t\t\tInvalid choice! Please try again";
				goto again3;
			}
			goto back;
		case 4:
			system("cls");
			SetConsoleTextAttribute(h, 12);
			cout << "\n\t\t\t\t\t        - - - - SCOREBOARD - - - -";
			SetConsoleTextAttribute(h, 7);
			cout << "\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
			cout << "\n\t\t\t\t*  \t   1. View The Scoreboard Of A Course\t        *";
			cout << "\n\t\t\t\t*  \t   2. View The Scoreboard Of A Class \t        *";
			cout << "\n\t\t\t\t*  \t   3. Update A Student's Result\t\t        *";
			cout << "\n\t\t\t\t*  \t   4. Back\t\t\t\t\t*";
			cout << "\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
		again4:
			SetConsoleTextAttribute(h, 12);
			cout << "\n\t\t\t\t[ Your choice ]: ";
			SetConsoleTextAttribute(h, 7);
			cin >> choice4;
			switch (choice4)
			{
			case 1:
				system("cls");
				viewCourseScore(firstYear);
				cout << endl;
				system("pause");
				break;
			case 2:
				system("cls");

				cout << endl;
				system("pause");
				break;
			case 3:
				system("cls");

				cout << endl;
				system("pause");
				break;
			case 4:
				goto back;
			default:
				cout << "\n\t\t\t\tInvalid choice! Please try again.";
				goto again4;
			}
			goto back;
		case 5:
			system("cls");
			char dec;
			cout << "\n\t\t\t\t\tAre you sure to exit the program? (y/n)";
		next:
			SetConsoleTextAttribute(h, 12);
			cout << "\n\t\t\t\t\t[ Your choice ]: ";
			SetConsoleTextAttribute(h, 7);
			cin >> dec;
			if (dec == 'y')
			{
				system("cls");
				SetConsoleTextAttribute(h, 12);
				cout << "\n\t\t\t\t\t      - - - - THANK YOU - - - -\n";
				SetConsoleTextAttribute(h, 7);
				writeSemesterList(firstYear);
				writeStudentListMain(firstYear);
				writeCourseList(firstYear);
				writeCourseStudentList(firstYear);
				deleteAll(firstYear);
			}
			else if (dec == 'n')
				goto back;
			else
			{
				cout << "\n\t\t\t\t\tInvalid choice! Please try again.";
				goto next;
			}
			break;
		default:
			cout << "\n\t\t\t\t\tInvalid choice! Please try again.";
			goto again7;
		}
	}
	else if (userAcc->type == 0)
	{
	updatemyInfo(userAcc, firstYear);
	readCourseStudentList(firstYear, userAcc);
	importScoreBoard(firstYear, userAcc);
	int choice5;
back1:
	system("cls");
	SetConsoleTextAttribute(h, 12);
	cout << "\n\t\t\t\t\t- - - - STUDENT - - - -";
	SetConsoleTextAttribute(h, 7);
	cout << "\n\t\t\t\t* * * * * * * * * * * * * * * * * * * *";
	cout << "\n\t\t\t\t*\t   1. Enrollment\t      *";
	cout << "\n\t\t\t\t*\t   2. View Scoreboard\t      *";
	cout << "\n\t\t\t\t*\t   3. Exit\t              *";
	cout << "\n\t\t\t\t* * * * * * * * * * * * * * * * * * * *";
again6:
	SetConsoleTextAttribute(h, 12);
	cout << "\n\t\t\t\t[ Your choice ]: ";
again5:
	SetConsoleTextAttribute(h, 7);
	cin >> choice5;
	switch (choice5)
	{
	case 1:
		system("cls");
		enrollCourse(firstYear, userAcc);
		cout << endl;
		system("pause");
		goto back1;
	case 2:
		system("cls");

		cout << endl;
		system("pause");
		goto back1;
	case 3:
		system("cls");
		char dec;
		cout << "\n\t\t\t\tAre you sure to exit the program? (y/n)";
	next1:
		SetConsoleTextAttribute(h, 12);
		cout << "\n\t\t\t\t[ Your choice ]: ";
		SetConsoleTextAttribute(h, 7);
		cin >> dec;
		if (dec == 'y')
		{
			system("cls");
			SetConsoleTextAttribute(h, 12);
			cout << "\n\t\t\t\t      - - - - THANK YOU - - - -\n";
			SetConsoleTextAttribute(h, 7);
			writeSemesterList(firstYear);
			writeStudentListMain(firstYear);
			writeCourseList(firstYear);
			writeCourseStudentList(firstYear);
			deleteAll(firstYear);
		}
		else if (dec == 'n')
			goto back1;
		else
		{
			cout << "\n\t\t\t\tInvalid choice! Please try again.";
			goto next1;
		}
		break;
	default:
		cout << "\n\t\t\t\tInvalid choice! Please try again.";
		goto again6;
	}
 }
}
