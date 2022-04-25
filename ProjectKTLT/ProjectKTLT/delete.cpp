#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void deleteAll(Year*& firstYear)
{
	Year* curYear = firstYear;
	while (curYear != nullptr)
	{
		Class* curClass = curYear->firstClass;
		while (curClass != nullptr)
		{
			Student* curStudent = curClass->firstStudent;
			while (curStudent != nullptr)
			{
				Student* tempStudent = curStudent;
				curStudent = curStudent->next;
				delete tempStudent;
			}
			Class* tempClass = curClass;
			curClass = curClass->next;
			delete tempClass;
		}
		Semester* curSe = curYear->firstSemester;
		while (curSe != nullptr)
		{
			Course* curCo = curSe->firstCourse;
			while (curCo != nullptr)
			{
				courseStudent* curStu = curCo->firstcourseStudent;
				while (curStu != nullptr)
				{
					courseStudent* tempStu = curStu;
					curStu = curStu->next;
					delete tempStu;
				}
				Course* tempCo = curCo;
				curCo = curCo->next;
				delete tempCo;
			}
			Semester* tempSe = curSe;
			curSe = curSe->next;
			delete tempSe;
		}
		Year* tempYear = curYear;
		curYear = curYear->next;
		delete tempYear;
	}
}