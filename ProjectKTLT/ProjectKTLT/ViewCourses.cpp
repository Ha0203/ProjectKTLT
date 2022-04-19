#include "file.h"

Course* findPos(Course* courses, int choice)
{
	Course* cur = courses;
	for (int i = 0; i < choice-1;i++)
		cur = cur->next;
	return cur;
}

void viewCourses(Year* year)
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
	bool exist = false;
	while (cur1)
	{
		if (cur1->nameYear == yeartemp)
		{
			exist = true;
			break;
		}
		cur1 = cur1->next;
	}
	if (exist == false)
	{
		cout << "Invalid year! Please try again.";
		return;
	}
	else
	{
		cout << "Please enter the semester you want to access: ";
		cin >> semestertemp;
		Semester* cur = cur1->firstSemester;
		while (cur && cur->nameSemester != semestertemp)
			cur = cur->next;
		if (!cur)
		{
			cout << "\nInvalid semester! Please try again";
			return;
		}
		system("cls");
		cout << "\n\t\t\t\t------------------LIST OF COURSES------------------\n\n";
		cout << setw(14) << left << "Course ID";
		cout << setw(26) << left << "Course Name";
		cout << setw(11) << left << "Credit";
		cout << setw(13) << left << "Students";
		cout << setw(15) << left << "Session 1";
		cout << setw(15) << left << "Session 2";
		cout << "Teacher";
		cout << endl;
		Course* cur2 = cur->firstCourse;
		while (cur2)
		{
			cout << setw(14) << left << cur2->courseID;
			cout << setw(26) << left << cur2->courseName;
			cout << setw(11) << left << cur2->numberOfCredit;
			cout << setw(13) << left << cur2->numberOfStudents;
			cout << setw(15) << left << cur2-> session1;
			cout << setw(15) << left << cur2->session2;
			cout << cur2->teacherName;
			cout << endl;
			cur2 = cur2->next;
		}
	}
}

void update(Year* year)
{
	if (!year)
	{
		cout << "\nNo information.";
		return;
	}
	int i = 1;
	string yeartemp;
	string semestertemp;
	cout << "Please enter the school year you want to access (Ex: 2021-2022): ";
onemoretime:
	cin.ignore();
	getline(cin, yeartemp);
	Year* cur1 = year;
	bool exist = false;
	while (cur1)
	{
		if (cur1->nameYear == yeartemp)
		{
			exist = true;
			break;
		}
		cur1 = cur1->next;
	}
	if (exist == false)
	{
		cout << "Invalid year! Please try again.";
		return;
	}
	cout << "Please enter the semester you want to access: ";
	getline(cin, semestertemp);
	Semester* cur3 = cur1->firstSemester;
	while (cur3 && cur3->nameSemester != semestertemp)
		cur3=cur3->next;
	if (cur3 == nullptr)
	{
		cout << "Invalid semester! Please try again.";
		return;
	}
	Course* cur2 = cur3->firstCourse;
	int choice;
	while (cur2)
	{
		cout << "\nPress " << i++ << " to update information of " << cur2->courseName << '\n';
		cur2 = cur2->next;
	}
	cout << "Your choice: ";
	cin >> choice;
	while (choice > i || choice < 1)
	{
		cout << "Invalid choice! Please enter your choice again: ";
		cin >> choice;
	}
	Course* cur = findPos(cur3->firstCourse, choice);
update:
	system("cls");
	cout << "\n\t\t\t\t------------------COURSES INFORMATION------------------\n\n";
	cout <<'\t'<< setw(14) << left << "Course ID";
	cout << setw(26) << left << "Course Name";
	cout << setw(11) << left << "Credit";
	cout << setw(13) << left << "Students";
	cout << setw(15) << left << "Session 1";
	cout << setw(15) << left << "Session 2";
	cout << "Teacher";
	cout << endl;
	cout <<'\t'<< setw(14) << left << cur->courseID;
	cout << setw(26) << left << cur->courseName;
	cout << setw(11) << left << cur->numberOfCredit;
	cout << setw(13) << left << cur->numberOfStudents;
	cout << setw(15) << left << cur->session1;
	cout << setw(15) << left << cur->session2;
	cout << cur->teacherName;
	cout << endl;
	cout << "\n\nWhich information you want to update?\n";
	cout << "Press 1 to \tUPDATE COURSE ID\n";
	cout << "Press 2 to \tUPDATE COURSE NAME\n";
	cout << "Press 3 to \tUPDATE TEACHER NAME\n";
	cout << "Press 4 to \tUPDATE NUMBER OF CREDITS \n";
	cout << "Press 5 to \tUPDATE THE MAXIMUM NUMBER OF STUDENTS\n";
	cout << "Press 6 to \tUPDATE SESSION\n";
	cout << "Press 7 to \tGO BACK\n";
	cout << "Your choice: ";
choose:
	cin >> choice;
	string temp;
	int temp1;
	switch (choice)
	{
	case 1:
		system("cls");
		cout << "Please enter the content you want to replace: ";
		cin.ignore();
		getline(cin,temp);
		cur->courseID = temp;
		cout << "Content Updated Succesfully\n";
		system("pause");
		goto update;
	case 2:
		system("cls");
		cout << "Please enter the content you want to replace: ";
		cin.ignore();
		getline(cin, temp);
		cur->courseName = temp;
		cout << "Content Updated Succesfully\n";
		system("pause");
		goto update;
	case 3:
		system("cls");
		cout << "Please enter the content you want to replace: ";
		cin.ignore();
		getline(cin, temp);
		cur->teacherName = temp;
		cout << "Content Updated Succesfully\n";
		system("pause");
		goto update;
	case 4:
		system("cls");
		cout << "Please enter the content you want to replace: ";
		cin >> temp;
		cur->numberOfCredit = temp;
		cout << "Content Updated Succesfully\n";
		system("pause");
		goto update;
	case 5:
		system("cls");
		cout << "Please enter the content you want to replace: ";
		cin >> temp1;
		cur->numberOfStudents = temp1;
		cout << "Content Updated Succesfully\n";
		system("pause");
		goto update;
	case 6:
		system("cls");
		cout << "Please enter the content you want to replace for session 1: ";
		cin.ignore();
		getline(cin,temp);
		cur->session1 = temp;
		cout << "Please enter the content you want to replace for session 2: \n";
		getline(cin, temp);
		cur->session2 = temp;
		cout << "Content Updated Succesfully\n";
		system("pause");
		goto update;
	case 7:
		return;
	default:
		cout << "Invalid choice! Please enter your choice again: ";
		goto choose;
	}
}

void deleteCourse(Year* year)
{
	if (!year)
	{
		cout << "\nNo information.";
		return;
	}
	string yeartemp;
	string semestertemp;
	cout << "Please enter the school year you want to access (Ex: 2021-2022): ";
nextdelete:
	cin.ignore();
	getline(cin, yeartemp);
	Year* cur1 = year;
	bool exist = false;
	while (cur1)
	{
		if (cur1->nameYear == yeartemp)
		{
			exist = true;
			break;
		}
		cur1 = cur1->next;
	}
	if (exist == false)
	{
		cout << "Invalid year! Please enter your choice again: ";
		return;
	}
	cout << "Please enter the semester you want to access: ";
	getline(cin, semestertemp,'\n');
	Semester* cur2 = cur1->firstSemester;
	while (cur2 && cur2->nameSemester != semestertemp)
		cur2 = cur2->next;
	if (cur2 == nullptr)
	{
		cout << "Invalid Semester! Please try again.";
		return;
	}
no:
	system("cls");
	Course* cur3 =cur2->firstCourse ;
	if (cur3 == nullptr)
	{
		cout << "\nDon't have any courses to be deleted";
		return;
	}
	int choice;
	int i = 1;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 12);
	cout << "\n\t\t\t\t\t      - - - - DELETE - - - -";
	SetConsoleTextAttribute(h, 7);
	cout << "\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * *";
	while (cur3)
	{
		cout << "\n\t\t\t\t*  \t      "<<i++<<". " << setw(33) << left << cur3->courseName<< "* ";
		cur3 = cur3->next;
	}
	cout << "\n\t\t\t\t*  \t      " << i << ". " << setw(33) << left << "Back" << "* ";
	cout << "\n\t\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * *";
	SetConsoleTextAttribute(h, 12);
	cout << "\n\t\t\t\t[ Your choice ]: ";
	SetConsoleTextAttribute(h, 7);
	cin >> choice;
	if (choice == i)
		return;
	while (choice > i || choice < 1)
	{
		cout << "\n\t\t\t\tInvalid choice! Please enter your choice again: ";
		cin >> choice;
	}
	Course* cur = findPos(cur2->firstCourse, choice);
	char delete1;
	cout << "\n\t\t\t\tDo you want to delete " << cur->courseName <<" ? (y/n)";
	SetConsoleTextAttribute(h, 12);
	cout << "\n\t\t\t\t[ Your choice ]: ";
	SetConsoleTextAttribute(h, 7);
else1:
	cin >> delete1;
	if (delete1 == 'y')
	{
		Course* temp = cur2->firstCourse;
		if (temp == cur)
		{
			cur2->firstCourse = cur->next;
			delete temp;
		}
		else
		{
			while (temp && temp->next != cur)
			{
				temp = temp->next;
			}
			if (temp)
			{
				temp->next = cur->next;
				delete cur;
			}
		}
	}
	else if (delete1 == 'n')
		goto no;
	else
	{
		cout << "\n\t\t\t\tInvalid choice! Please enter your choice again: ";
		goto else1;
	}
}
