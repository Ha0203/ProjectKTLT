#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void readStudentListMain(Year*& firstYear)
{
	string tempt, row;
	Year* curYear = firstYear, * prevYear = nullptr;
	Class* curClass = nullptr, * prevClass = nullptr;
	Student* curStudent = nullptr, * prevStudent = nullptr;
	fstream input;
	input.open("StudentListMain.csv", ios::in);
	if (input.fail())
	{
		cout << "Can't find the file " << endl;
		return;
	}
	while (getline(input, row))
	{
		stringstream ss(row);
		getline(ss, tempt, ',');
		if (firstYear == nullptr)
		{
			firstYear = new Year;
			firstYear->nameYear = tempt;
			firstYear->next = nullptr;
			getline(ss, tempt, ',');
			firstYear->firstClass = new Class;
			firstYear->firstClass->nameClass = tempt;
			firstYear->firstClass->next = nullptr;
			getline(ss, tempt, ',');
			firstYear->firstClass->firstStudent = new Student;
			firstYear->firstClass->firstStudent->Number = tempt;
			firstYear->firstClass->firstStudent->next = nullptr;
			getline(ss, tempt, ',');
			firstYear->firstClass->firstStudent->studentID = tempt;
			getline(ss, tempt, ',');
			firstYear->firstClass->firstStudent->firstName = tempt;
			getline(ss, tempt, ',');
			firstYear->firstClass->firstStudent->lastName = tempt;
			getline(ss, tempt, ',');
			firstYear->firstClass->firstStudent->gender = tempt;
			getline(ss, tempt, ',');
			firstYear->firstClass->firstStudent->dateOfBirth = tempt;
			getline(ss, tempt, ',');
			firstYear->firstClass->firstStudent->socialID = tempt;
			continue;
		}
		prevYear = nullptr;
		curYear = firstYear;
		while (curYear != nullptr && curYear->nameYear != tempt)
		{
			prevYear = curYear;
			curYear = curYear->next;
		}
		if (curYear==nullptr)
		{
			prevYear->next = new Year;
			curYear = prevYear->next;
			curYear->next = nullptr;
			curYear->nameYear = tempt;
			curYear->firstClass = nullptr;
		}
		getline(ss, tempt, ',');
		prevClass = nullptr;
		curClass = curYear->firstClass;
		if (curYear->firstClass == nullptr)
		{
			curYear->firstClass = new Class;
			curClass = curYear->firstClass;
			curClass->nameClass = tempt;
			curClass->next = nullptr;
			curClass->firstStudent = nullptr;
		}
		else
		{
			while (curClass != nullptr && curClass->nameClass != tempt)
			{
				prevClass = curClass;
				curClass = curClass->next;
			}
			if (curClass==nullptr)
			{
				prevClass->next = new Class;
				curClass = prevClass -> next;
				curClass->nameClass = tempt;
				curClass->next = nullptr;
				curClass->firstStudent = nullptr;
			}
		}
		getline(ss, tempt, ',');
		prevStudent = nullptr;
		curStudent = curClass->firstStudent;
		while (curStudent != nullptr)
		{
			prevStudent = curStudent;
			curStudent = curStudent->next;
		}
		if (prevStudent != nullptr)
		{
			prevStudent->next = new Student;
			curStudent = prevStudent->next;
		}
		else
		{
				curClass->firstStudent = new Student;
				curStudent = curClass->firstStudent;
		}
		curStudent->next = nullptr;
		curStudent->Number = tempt;
		getline(ss, tempt, ',');
		curStudent->studentID = tempt;
		getline(ss, tempt, ',');
		curStudent->firstName = tempt;
		getline(ss, tempt, ',');
		curStudent->lastName = tempt;
		getline(ss, tempt, ',');
		curStudent->gender = tempt;
		getline(ss, tempt, ',');
		curStudent->dateOfBirth = tempt;
		getline(ss, tempt, ',');
		curStudent->socialID = tempt;
	}
	input.close();
}