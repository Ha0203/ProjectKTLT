#include <iostream>
#include"ProjectKTLT/login.h"
#include"ProjectKTLT/file.h"
using namespace std;
void Menu(Account* userAcc)
{
	Year* firstYear = nullptr;
	int choice;
	bool active;
	readStudentListMain(firstYear);
	if (userAcc->type == 1)
	{
	next:
		cout << "Press 1 to \tCREATE A SCHOOL YEAR\n";
		cout << "Press 2 to \tCREATE CLASS FOR 1ST YEAR STUDENT\n";
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
		case 13:
			system("cls");

			break;
		case 14:
			system("cls");

			break;
		case 15:
			system("cls");

			break;
		case 16:
			system("cls");

			break;
		default:
		{
			cout << "Invalid choice! Please enter your choice again: ";
			goto choose;
		}
		}
	again:
		cout << "Do you want to continue the program (Y/N)?";
		char dec;
		cin >> dec;
		if (dec == 'Y')
			goto next;
		else if (dec == 'N')
			cout << "Thank you for using the program.";
		else
		{
			cout << "Invalid choice! Please enter your choice again: ";
			goto again;
		}
	}
	else if (userAcc->type == 2)
	{
	next1:
		cout << "Press 1 to \tENROLL IN A COURSE\n";
		cout << "Press 2 to \tVIEW LIST OF ENROLLED COURSES\n";
		cout << "Press 3 to \tREMOVE A COURSE\n";
		cout << "Press 4 to \tVIEW SCOREBOARD\n";
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
		default:
			cout << "Invalid choice! Please enter your choice again: ";
			goto choose1;
		}
	again1:
		cout << "Do you want to continue the program (Y/N)?";
		char dec;
		cin >> dec;
		if (dec == 'Y')
			goto next1;
		else if (dec == 'N')
			cout << "Thank your for using the program.";
		else
		{
			cout << "Invalid choice! Please enter your choice again: ";
			goto again1;
		}
	}
}