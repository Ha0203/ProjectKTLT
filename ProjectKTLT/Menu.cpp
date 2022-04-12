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
	readCourseStudentList(firstYear);
	importScoreBoard(firstYear);
	if (userAcc->type == 1)
	{
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
				system("pause");
				break;
			case 2:
				system("cls");
				createSemester(firstYear);
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
				system("pause");
				break;
			case 2:
				system("cls");
				viewClass(firstYear);
				system("pause");
				break;
			case 3:
				system("cls");
				viewStuClass(firstYear);
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
				system("pause");
				break;
			case 2:
				system("cls");
				viewCourses(firstYear);
				system("pause");
				break;
			case 3:
				system("cls");
				viewStuCourse(firstYear);
				system("pause");
				break;
			case 4:
				system("cls");
				update(firstYear);
				system("pause");
				break;
			case 5:
				system("cls");
				deleteCourse(firstYear);
				system("pause");
				break;
			case 6:
				system("cls");
				exportCourseStudent(firstYear);
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
			cout << "\n\t\t\t\t*  \t   1. Import The Scoreboard Of Students\t        *";
			cout << "\n\t\t\t\t*  \t   2. View The Scoreboard Of A Course\t        *";
			cout << "\n\t\t\t\t*  \t   3. View The Scoreboard Of A Class \t        *";
			cout << "\n\t\t\t\t*  \t   4. Update A Student's Result\t\t        *";
			cout << "\n\t\t\t\t*  \t   5. Back\t\t\t\t\t*";
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

				system("pause");
				break;
			case 2:
				system("cls");

				system("pause");
				break;
			case 3:
				system("cls");

				system("pause");
				break;
			case 4:
				system("cls");

				system("pause");
				break;
			case 5:
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
		}
	}
	else if (userAcc->type == 0)
	{
	updatemyInfo(userAcc, firstYear);
	int choice5;
back1:
	system("cls");
	SetConsoleTextAttribute(h, 12);
	cout << "\n\t\t\t\t\t- - - - STUDENT - - - -";
	SetConsoleTextAttribute(h, 7);
	cout << "\n\t\t\t\t* * * * * * * * * * * * * * * * * * * *";
	cout << "\n\t\t\t\t*\t 1. EnrollMent\t         *";
	cout << "\n\t\t\t\t*\t 2. View Scoreboard\t      *";
	cout << "\n\t\t\t\t*\t 3. Exit\t              *";
	cout << "\n\t\t\t\t* * * * * * * * * * * * * * * * * * * *";
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
		system("pause");
		goto back1;
	case 2:
		system("cls");

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
	}
 }
}

void Menu(Account* userAcc)
{
	Year* firstYear = nullptr;
	int choice;
	readStudentListMain(firstYear);
	if (userAcc->type == 1)
	{
	next:
		cout << endl;
		cout << "Press 1 to \tCREATE A SCHOOL YEAR AND UPDATE CLASS FOR THIS SCHOOLYEAR\n";
		cout << "Press 2 to \tUPDATE CLASS FOR THE AVAILABLE YEAR\n";
		cout << "Press 3 to \tCREATE A SEMESTER\n";
		cout << "Press 4 to \tCREATE A COURSE REGISTATION SESSION\n";
		cout << "Press 5 to \tVIEW THE LIST OF COURSE\n";
		cout << "Press 6 to \tUPDATE COURSE INFORMATION\n";
		cout << "Press 7 to \tDELETE A COURSE\n";
		cout << "Press 8 to \tVIEW A LIST OF CLASSES\n";
		cout << "Press 9 to \tVIEW A LIST OF STUDENTS IN A CLASS\n";
		cout << "Press 10 to \tVIEW A LIST OF COURSES\n";
		cout << "Press 11 to \tVIEW A LIST OF STUDENTS IN A COURSE";
		cout << "Press 12 to \tEXPORT LIST OF STUDENT IN A COURSE\n";
		cout << "Press 13 to \tIMPORT THE SCOREBOARD OF A COURSE\n";
		cout << "Press 14 to \tVIEW THE SCOREBOARD OF A COURSE\n";
		cout << "Press 15 to \tUPDATE A STUDENT RESULT\n";
		cout << "Press 16 to \tVIEW THE SCOREBOARD OF A CLASS\n";
		cout << "Your choice: ";
	choose:
		cin >> choice;
		switch (choice)
		{
		case 1:
			createSchoolYear(firstYear);
			break;
		case 2:
			updateClass(firstYear);
			break;
		case 3:
			createSemester(firstYear);
			break;
		case 4:
			/*courseRegist(firstYear);*/
			break;
		case 5:
			system("cls");
			viewCourses(firstYear);
			break;
		case 6:
			system("cls");
			update(firstYear);
			break;
		case 7:
			system("cls");
			deleteCourse(firstYear);
			break;
		case 8:
			system("cls");

			break;
		case 9:
			system("cls");

			break;
		case 10:
			system("cls");

			break;
		case 11:
			system("cls");

			break;
		case 12:
			system("cls");

			break;
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
			writeStudentListMain(firstYear);
			writeSemesterList(firstYear);
			deleteAll(firstYear);
			cout << "\nThank you for using the program.";
		}
		else
		{
			cout << "\nInvalid choice! Please enter your choice again: ";
			goto again;
		}
	}
	else if (userAcc->type == 0)
	{
		updatemyInfo(userAcc, firstYear);
	next1:
		cout << "\nPress 1 to \tENROLL IN A COURSE";
		cout << "\nPress 2 to \tVIEW THE LIST OF ENROLLED COURSES";
		cout << "\nPress 3 to \tVIEW THE LIST OF CLASSES";
		cout << "\nPress 4 to \tVIEW THE LIST OF STUDENTS IN A CLASS";
		cout << "\nPress 5 to \tVIEW THE LIST OF STUDENTS IN A COURSE";
		cout << "\nPress 6 to \tREMOVE A COURSE";
		cout << "\nPress 7 to \tVIEW SCOREBOARD";
	choose1:
		cout << "Your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			system("cls");

			break;
		case 2:
			system("cls");

			break;
		case 3:
			system("cls");

			break;
		case 4:
			system("cls");

			break;
		case 5:
			system("cls");

			break;
		case 6:
			system("cls");

			break;
		case 7:
			system("cls");

			break;
		default:
			cout << "Invalid choice! Please enter your choice again: ";
			goto choose1;
		}
	again1:
		cout << "\nDo you want to continue the program (Y/N)?";
		char dec;
		cin >> dec;
		if (dec == 'Y')
			goto next1;
		else if (dec == 'N')
			cout << "\nThank your for using the program.";
		else
		{
			cout << "\nInvalid choice! Please enter your choice again: ";
			goto again1;
		}
	}
}

