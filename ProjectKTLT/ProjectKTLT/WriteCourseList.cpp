#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void writeCourseList(Year*& firstYear)
{
	fstream output;
	Year* curYear = firstYear;
	output.open("CourseList.csv", ios::out);
	while (curYear != nullptr)
	{
		Semester* curSe = curYear->firstSemester;
		while (curSe != nullptr)
		{
			Course* curCo = curSe->firstCourse;
			while (curCo != nullptr)
			{
				output << curYear->nameYear << "," << curSe->nameSemester << "," << curCo->courseID << "," << curCo->courseName << "," << curCo->teacherName << "," << curCo->numberOfCredit << "," << curCo->numberOfStudents << "," << curCo->session1 << "," << curCo->session2 << "\n";
				curCo = curCo->next;
			}
			curSe = curSe->next;
		}
		curYear = curYear->next;
	}
	output.close();
}