#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void writeStudentListMain(Year*& firstYear)
{
	fstream output;
	output.open("StudentListMainDemo.csv", ios::out);
	Year*curYear = firstYear;
	while (curYear != nullptr)
	{
		Class* curClass = curYear->firstClass;
		while (curClass != nullptr)
		{
			Student* curStudent = curClass->firstStudent;
			while (curStudent != nullptr)
			{
				output << curYear->nameYear << "," << curClass->nameClass << "," << curStudent->Number << "," << curStudent->studentID << "," << curStudent->firstName << "," << curStudent->lastName << "," << curStudent->gender << "," << curStudent->dateOfBirth << "," << curStudent->socialID << "\n";
				curStudent = curStudent->next;
			}
			curClass = curClass->next;
		}
		curYear = curYear->next;
	}
	output.close();
}