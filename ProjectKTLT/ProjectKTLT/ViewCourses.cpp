#include "file.h"

Course* findPos(Course* courses, int choice)
{
	Course* cur = courses;
	for (int i = 0; i < choice;i++)
		cur = cur->next;
	return cur;
}

void viewCourses(Year* year)
{
	string yeartemp;
	string semestertemp;
	cout << "Please enter the school year you want to access (Ex: 2021-2022): ";
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
	else
	{
		cout << "Please enter the semester you want to access: ";
		cin.ignore();
		getline(cin, semestertemp);
		Semester* cur = cur1->firstSemester;
		while (cur && cur->nameSemester != semestertemp)
			cur = cur->next;
		if (!cur)
		{
			cout << "\nInvalid semester! Please try again";
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
	cin.ignore();
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
	
	system("cls");
	cout << "\n\t\t\t\t------------------COURSES INFORMATION------------------\n\n";
	cout << setw(14) << left << "Course ID";
	cout << setw(26) << left << "Course Name";
	cout << setw(11) << left << "Credit";
	cout << setw(13) << left << "Students";
	cout << setw(15) << left << "Session 1";
	cout << setw(15) << left << "Session 2";
	cout << "Teacher";
	cout << endl;
	cout << setw(14) << left << cur->courseID;
	cout << setw(26) << left << cur->courseName;
	cout << setw(11) << left << cur->numberOfCredit;
	cout << setw(13) << left << cur->numberOfStudents;
	cout << setw(15) << left << cur->session1;
	cout << setw(15) << left << cur->session2;
	cout << cur->teacherName;
	cout << endl;

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
		cin.ignore();
		getline(cin,temp);
		cur->session1 = temp;
		cout << "Please enter the content you want to replace for session 2: \n";
		getline(cin, temp);
		cur->session2 = temp;
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
		return;
	}
	cout << "Please enter the semester you want to access: ";
	cin.ignore();
	getline(cin, semestertemp);
	Semester* cur2 = cur1->firstSemester;
	while (cur2 && cur2->nameSemester != semestertemp)
		cur2 = cur2->next;
	if (cur2 == nullptr)
	{
		cout << "Invalid Semester! Please try again.";
		return;
	}
	Course* cur3 =cur2->firstCourse ;
	int choice;
	while (cur3)
	{
		cout << "\nPress " << i++ << " to delete " << cur3->courseName << '\n';
		cur3 = cur3->next;
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
