#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void writeCourseStudentList(Year*& firstYear)
{
	fstream output;
	Year* curYear = firstYear;
	output.open("CourseStudentListDemo.csv", ios::out);
	while (curYear != nullptr)
	{
		Semester* curSe = curYear->firstSemester;
		while (curSe != nullptr)
		{
			Course* curCo = curSe->firstCourse;
			while (curCo != nullptr)
			{
				courseStudent* curStu = curCo->firstcourseStudent;
				while (curStu != nullptr)
				{
					output << curYear->nameYear << "," << curSe->nameSemester << "," << curCo->courseID << "," << curStu->Number << "," << curStu->studentID << "," << curStu->firstName << "," << curStu->lastName << "," << curStu->gender << "," << curStu->dateOfBirth << "," << curStu->socialID << "\n";
					curStu = curStu->next;
				}
				curCo = curCo->next;
			}
			curSe = curSe->next;
		}
		curYear = curYear->next;
	}
	output.close();
}