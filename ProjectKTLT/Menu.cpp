#include <iostream>
#include"ProjectKTLT/login.h"
#include"ProjectKTLT/file.h"
using namespace std;
void Menu(Account* userAcc)
{
	Year* firstYear = nullptr;
	int choice;
	readStudentListMain(firstYear);
	if (userAcc->type == 1)
	{
	next:
		cout << "\nPress 1 to \tCREATE A SCHOOL YEAR";
		cout << "\nPress 2 to \tCREATE CLASS FOR 1ST YEAR STUDENT";
		cout << "\nPress 3 to \tCREATE A SEMESTER";
		cout << "\nPress 4 to \tCREATE A COURSE REGISTATION SESSION";
		cout << "\nPress 5 to \tVIEW THE LIST OF COURSES";
		cout << "\nPress 6 to \tUPDATE COURSE INFORMATION";
		cout << "\nPress 7 to \tDELETE A COURSE";
		cout << "\nPress 8 to \tEXPORT THE LIST OF STUDENTS IN A COURSE";
		cout << "\nPress 9 to \tIMPORT THE SCOREBOARD OF A COURSE";
		cout << "\nPress 10 to \tVIEW THE SCOREBOARD OF A COURSE";
		cout << "\nPress 11 to \tUPDATE A STUDENT RESULT";
		cout << "\nPress 12 to \tVIEW THE SCOREBOARD OF A CLASS";
		cout << "Your choice: ";
	choose:
		cin >> choice;
		switch (choice)
		{
		case 1:
			createSchoolYear(firstYear);
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
			cout << "\nThank you for using the program.";
		else
		{
			cout << "\nInvalid choice! Please enter your choice again: ";
			goto again;
		}
	}
	else if (userAcc->type == 2)
	{
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