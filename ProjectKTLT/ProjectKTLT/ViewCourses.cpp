#include "file.h"
#include "login.h"

Course* findPos(Course* courses, int choice)
{
	Course* cur = courses;
	for (int i = 0; i < choice;i++)
		cur = cur->next;
	return cur;
}

void viewCourses(Year* year)
{
	int i = 1;
	string yeartemp;
	string semestertemp;
	cout << "Please enter the school year you want to access (Ex: 2021-2022): ";
againn:
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
		goto againn;
	}
	else
	{
		cout << "Please enter the semester you want to access: ";
	againnn:
		cin.ignore();
		getline(cin, semestertemp);
		int selection = 0;
		switch (stoi(semestertemp))
		{
		case 1:
			selection = 1;
		case 2:
			selection = 2;
		case 3:
			selection = 3;
		default:
			cout << "Invalid semester! Please enter your choice again: ";
			goto againnn;
		}
		Semester* cur = cur1->firstSemester;
		while (selection == 0)
		{
			selection--;
			cur = cur->next;
		}
		Course* cur2 = cur->firstCourse;
		while (cur2)
		{
			cout << "\nSTT\t"<< "Course ID\t" << "Course Name\t\t" << "Teacher Name\t" << "Number of Credits\t" << "The Number Of Student\t"<<"Session\n";
			cout << i++<<'\t' << cur2->courseID << '\t' << cur2->courseName << '\t' << cur2->teacherName << '\t' << cur2->numberOfCredit << '\t' << cur2->numberOfStudents<< '\t' << cur2->day1 << ", "<< cur2->time1 << " and " << cur2->day2 << ", " << cur2->time2 << endl;
			cur2 = cur2->next;
		}
	}
}

void update(Year* year)
{
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
		cout << "Invalid year! Please enter your choice again: ";
		goto onemoretime;
	}
	cout << "Please enter the semester you want to access: ";
onemoretime1:
	cin.ignore();
	getline(cin, semestertemp);
	int selection = 0;
	switch (stoi(semestertemp))
	{
	case 1:
		selection = 1;
	case 2:
		selection = 2;
	case 3:
		selection = 3;
	default:
		cout << "Invalid semester! Please enter your choice again: ";
		goto onemoretime1;
	}
	Semester* cur3 = cur1->firstSemester;
	while (selection == 0)
	{
		selection--;
		cur3 = cur3->next;
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
	cout << "\nCourse ID\t" << "Course Name\t\t" << "Teacher Name\t" << "Number of Credits\t" << "The Number Of Student\t" << "Session\n";
	cout << cur->courseID << '\t' << cur->courseName << '\t' << cur->teacherName << '\t' << cur->numberOfCredit << '\t' << cur->numberOfStudents<<'\t' << cur->day1 <<", "<<cur->time1<<" " << cur->day2<<", "<<cur->time2 << endl;
	cout << "Which information you want to change?";
	cout << "Press 1 to change course ID.\n";
	cout << "Press 2 to change course name.\n";
	cout << "Press 3 to change teacher name.\n";
	cout << "Press 4 to change number of credits.\n";
	cout << "Press 5 to change the maximum number of students.\n";
	cout << "Press 6 to change session.\n";
	cout << "Your choice: ";
choose:
	cin >> choice;
	string temp;
	int temp1;
	switch (choice)
	{
	case 1:
		cout << "Please enter the content you want to replace: ";
		cin.ignore();
		getline(cin,temp);
		cur->courseID = temp;
		break;
	case 2:
		cout << "Please enter the content you want to replace: ";
		cin.ignore();
		getline(cin, temp);
		cur->courseName = temp;
		break;
	case 3:
		cout << "Please enter the content you want to replace: ";
		cin.ignore();
		getline(cin, temp);
		cur->teacherName = temp;
		break;
	case 4:
		cout << "Please enter the content you want to replace: ";
		cin >> temp1;
		cur->numberOfCredit = temp1;
		break;
	case 5:
		cout << "Please enter the content you want to replace: ";
		cin >> temp1;
		cur->numberOfStudents = temp1;
		break;
	case 6:
		cout << "Please enter the content you want to replace for session 1: ";
		cout << "Day: ";
		cin.ignore();
		getline(cin,temp);
		cur->day1 = temp;
		cout << "Time: ";
		getline(cin, temp);
		cur->time1 = temp;
		cout << "Please enter the content you want to replace for session 2: \n";
		cout << "Day: ";
		getline(cin, temp);
		cur->day2 = temp;
		cout << "Time: ";
		getline(cin, temp);
		cur->time2 = temp;
		break;
	default:
		cout << "Invalid choice! Please enter your choice again: ";
		goto choose;
	}
}

void deleteCourse(Year* year)
{
	int i = 1;
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
		goto nextdelete;
	}
	cout << "Please enter the semester you want to access: ";
nextdelete2:
	cin.ignore();
	getline(cin, semestertemp);
	int selection = 0;
	switch (stoi(semestertemp))
	{
	case 1:
		selection = 1;
	case 2:
		selection = 2;
	case 3:
		selection = 3;
	default:
		cout << "Invalid semester! Please enter your choice again: ";
		goto nextdelete2;
	}
	Semester* cur2 = cur1->firstSemester;
	while (selection == 0)
	{
		selection--;
		cur1 = cur1->next;
	}
	Course* cur3 =cur2->firstCourse ;
	int choice;
	while (cur3)
	{
		cout << "\nPress " << i++ << " to update information of " << cur3->courseName << '\n';
		cur1 = cur1->next;
	}
	cout << "Your choice: ";
	cin >> choice;
	while (choice > i || choice < 1)
	{
		cout << "Invalid choice! Please enter your choice again: ";
		cin >> choice;
	}
	Course* cur = findPos(cur2->firstCourse, choice);
	Course* temp = nullptr;
	for (temp =cur2->firstCourse; temp->next != cur; temp = temp->next);
		temp->next = cur->next;
	delete cur;
}
//#include "file.h"
//
//Course* findPos(Course* courses, int choice)
//{
//	Course* cur = nullptr;
//	for (int i = 0; i < choice;i++)
//		cur = cur->next;
//	return cur;
//}
//
//void viewCourses(Course* courses)
//{
//	int i = 1;
//	Course* cur = courses;
//	while (courses)
//	{
//		cout << "\nSTT\t"<< "Course ID\t" << "Course Name\t\t" << "Teacher Name\t" << "Number of Credits\t" << "The Number Of Student\t"<<"Session\n";
//		cout << i++<<'\t' << cur->courseID << '\t' << cur->courseName << '\t' << cur->teacherName << '\t' << cur->numberOfCredit << '\t' << cur->numberOfStudents<< '\t' << cur->day1 << ", "<< cur->time1 << " and " << cur->day2 << ", " << cur->time2 << endl;
//		cur = cur->next;
//	}
//}
//
//void update(Course* courses)
//{
//	int i=1;
//	Course* cur1 = courses;
//	int choice;
//	while (courses)
//	{
//		cout << "\nPress " << i++ << " to update information of " << cur1->courseName << '\n';
//		cur1 = cur1->next;
//	}
//	cout << "Your choice: ";
//	cin >> choice;
//	while (choice > i || choice < 1)
//	{
//		cout << "Invalid choice! Please enter your choice again: ";
//		cin >> choice;
//	}
//	Course* cur = findPos(courses, choice);
//	cout << "\nCourse ID\t" << "Course Name\t\t" << "Teacher Name\t" << "Number of Credits\t" << "The Number Of Student\t" << "Session\n";
//	cout << cur->courseID << '\t' << cur->courseName << '\t' << cur->teacherName << '\t' << cur->numberOfCredit << '\t' << cur->numberOfStudents<<'\t' << cur->session << endl;
//	cout << "Which information you want to change?";
//	cout << "Press 1 to change course ID.\n";
//	cout << "Press 2 to change course name.\n";
//	cout << "Press 3 to change teacher name.\n";
//	cout << "Press 4 to change number of credits.\n";
//	cout << "Press 5 to change the maximum number of students.\n";
//	cout << "Press 6 to change session.\n";
//	cout << "Your choice: ";
//choose:
//	cin >> choice;
//	string temp;
//	int temp1;
//	switch (choice)
//	{
//	case 1:
//		cout << "Please enter the content you want to replace: ";
//		cin.ignore();
//		getline(cin,temp);
//		cur->courseID = temp;
//		break;
//	case 2:
//		cout << "Please enter the content you want to replace: ";
//		cin.ignore();
//		getline(cin, temp);
//		cur->courseName = temp;
//		break;
//	case 3:
//		cout << "Please enter the content you want to replace: ";
//		cin.ignore();
//		getline(cin, temp);
//		cur->teacherName = temp;
//		break;
//	case 4:
//		cout << "Please enter the content you want to replace: ";
//		cin >> temp1;
//		cur->numberOfCredit = temp1;
//		break;
//	case 5:
//		cout << "Please enter the content you want to replace: ";
//		cin >> temp1;
//		cur->numberOfStudents = temp1;
//		break;
//	case 6:
//		cout << "Please enter the content you want to replace for session 1: ";
//		cout << "Day: ";
//		cin.ignore();
//		getline(cin,temp);
//		cur->day1 = temp;
//		cout << "Time: ";
//		getline(cin, temp);
//		cur->time1 = temp;
//		cout << "Please enter the content you want to replace for session 2: \n";
//		cout << "Day: ";
//		getline(cin, temp);
//		cur->day2 = temp;
//		cout << "Time: ";
//		getline(cin, temp);
//		cur->time2 = temp;
//		break;
//	default:
//		cout << "Invalid choice! Please enter your choice again: ";
//		goto choose;
//	}
//}
//
//void deleteCourse(Course* courses)
//{
//	int i = 1;
//	Course* cur1 = courses;
//	int choice;
//	while (courses)
//	{
//		cout << "\nPress " << i++ << " to update information of " << cur1->courseName << '\n';
//		cur1 = cur1->next;
//	}
//	cout << "Your choice: ";
//	cin >> choice;
//	while (choice > i || choice < 1)
//	{
//		cout << "Invalid choice! Please enter your choice again: ";
//		cin >> choice;
//	}
//	Course* cur = findPos(courses, choice);
//	Course* temp = nullptr;
//	for (temp = courses; temp->next != cur; temp = temp->next);
//	temp->next = cur->next;
//	delete cur;
//	cur = temp;
//}
//}
