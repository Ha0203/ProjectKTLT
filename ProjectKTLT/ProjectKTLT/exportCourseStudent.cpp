#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void exportCourseStudent(Year*& firstYear)
{
	fstream output;
	Year* curYear = firstYear;
	while (curYear != nullptr)
	{
		Semester* curSe = curYear->firstSemester;
		while (curSe != nullptr)
		{
			Course* curCo = curSe->firstCourse;
			while (curCo != nullptr)
			{
				courseStudent* curStu = curCo->firstcourseStudent;
				string filename = curCo->courseID;
				output.open(filename.c_str(), ios::out);
				while (curStu != nullptr)
				{
					output << curStu->Number << "," << curStu->studentID << "," << curStu->lastName + curStu->firstName << "," << -1 << "," << -1 << "," << -1 << "\n";
					curStu = curStu->next;
				}
				output.close();
				curCo = curCo->next;
			}
			curSe = curSe->next;
		}
		curYear = curYear->next;
	}
}