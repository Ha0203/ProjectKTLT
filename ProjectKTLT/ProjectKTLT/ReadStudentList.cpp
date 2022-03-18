#include<iostream>
#include<fstream>
#include"file.h"
using namespace std;

void readStudentListMain(Year*&firstYear)
{
	string tempt;
	Year* curYear = nullptr;
	Class* curClass = nullptr;
	Student* curStudent = nullptr;
	fstream input;
	input.open("StudentListMain.csv", ios::in);
	if (input.fail())
	{
		cout << "Can't file the find 'StudentListMain.csv'" << endl;
	}
	while (input.good())
	{
		getline(input, tempt, ',');
		if (firstYear == nullptr)
		{
			firstYear = new Year;
			firstYear->nameYear = tempt;
			firstYear->next = nullptr;
			curYear = firstYear;
			getline(input, tempt, ',');
			firstYear->firstClass = new Class;
			firstYear->firstClass->nameClass = tempt;
			firstYear->firstClass->next = nullptr;
			getline(input, tempt, ',');
			firstYear->firstClass->firstStudent = new Student;
			firstYear->firstClass->firstStudent->Number = tempt;
			firstYear->firstClass->firstStudent->next = nullptr;
			getline(input, tempt, ',');
			firstYear->firstClass->firstStudent->studentID = tempt;
			getline(input, tempt, ',');
			firstYear->firstClass->firstStudent->firstName = tempt;
			getline(input, tempt, ',');
			firstYear->firstClass->firstStudent->lastName = tempt;
			getline(input, tempt, ',');
			firstYear->firstClass->firstStudent->gender = tempt;
			getline(input, tempt, ',');
			firstYear->firstClass->firstStudent->dateOfBirth = tempt;
			getline(input, tempt);
			firstYear->firstClass->firstStudent->socialID = tempt;
			continue;
		}
		curYear = firstYear;
		while (curYear != nullptr)
		{
			if (curYear->nameYear == tempt)
			{
				getline(input, tempt, ',');
				curClass = curYear->firstClass;
				while (curClass != nullptr)
				{
					if (curClass->nameClass == tempt)
					{
						curStudent = curClass->firstStudent;
						while (curStudent != nullptr)
						{
							curStudent = curStudent->next;
						}
						curStudent = new Student;
						curStudent->next = nullptr;
						getline(input, tempt, ',');
						curStudent->Number = tempt;
						getline(input, tempt, ',');
						curStudent->studentID = tempt;
						getline(input, tempt, ',');
						curStudent->firstName = tempt;
						getline(input, tempt, ',');
						curStudent->lastName = tempt;
						getline(input, tempt, ',');
						curStudent->gender = tempt;
						getline(input, tempt, ',');
						curStudent->dateOfBirth = tempt;
						getline(input, tempt);
						curStudent->socialID = tempt;
						break;
					}
					curClass = curClass->next;
				}
				if (curClass == nullptr)
				{
					curClass = new Class;
					curClass->next = nullptr;
					curClass->nameClass = tempt;
					curStudent = curClass->firstStudent;
					curStudent->next = nullptr;
					getline(input, tempt, ',');
					curStudent->Number = tempt;
					getline(input, tempt, ',');
					curStudent->studentID = tempt;
					getline(input, tempt, ',');
					curStudent->firstName = tempt;
					getline(input, tempt, ',');
					curStudent->lastName = tempt;
					getline(input, tempt, ',');
					curStudent->gender = tempt;
					getline(input, tempt, ',');
					curStudent->dateOfBirth = tempt;
					getline(input, tempt);
					curStudent->socialID = tempt;
				}
				break;
			}
			curYear = curYear->next;
		}
		if (curYear == nullptr)
		{
			curYear = new Year;
			curYear->next = nullptr;
			curYear->nameYear = tempt;
			curClass = curYear->firstClass;
			curClass = new Class;
			curClass->next = nullptr;
			getline(input, tempt, ',');
			curClass->nameClass = tempt;
			curStudent = curClass->firstStudent;
			curStudent->next = nullptr;
			getline(input, tempt, ',');
			curStudent->Number = tempt;
			getline(input, tempt, ',');
			curStudent->studentID = tempt;
			getline(input, tempt, ',');
			curStudent->firstName = tempt;
			getline(input, tempt, ',');
			curStudent->lastName = tempt;
			getline(input, tempt, ',');
			curStudent->gender = tempt;
			getline(input, tempt, ',');
			curStudent->dateOfBirth = tempt;
			getline(input, tempt);
			curStudent->socialID = tempt;
		}
	}
	input.close();
}