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
		Year* tempYear = curYear;
		curYear = curYear->next;
		delete tempYear;
	}
}