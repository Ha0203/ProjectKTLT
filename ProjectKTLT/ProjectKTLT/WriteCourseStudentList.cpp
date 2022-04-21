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
	output.open("CourseStudentList.csv", ios::out);
	while (curYear != nullptr)
	{
		Semester* curSe = curYear->firstSemester;
		while (curSe != nullptr)
		{
			Course* curCo = curSe->firstCourse;
			while (curCo != nullptr)
			{
				courseStudent* curStu = curCo->firstcourseStudent;
				int i = 0;
				while (curStu != nullptr)
				{
					i++;
					output << curYear->nameYear << "," << curSe->nameSemester << "," << curCo->courseID << "," << i << "," << curStu->studentID << "," << curStu->firstName << "," << curStu->lastName << "," << curStu->gender << "," << curStu->dateOfBirth << "," << curStu->socialID << "\n";
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