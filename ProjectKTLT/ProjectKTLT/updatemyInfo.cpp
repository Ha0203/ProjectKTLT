#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void updatemyInfo(Account* userAcc, Year* firstYear)
{
	Year* curYear = firstYear;
	while (curYear != nullptr)
	{
		Class* curClass = curYear->firstClass;
		while (curClass != nullptr)
		{
			Student* curStudent = curYear->firstClass->firstStudent;
			while (curStudent != nullptr)
			{
				if (curStudent->studentID == userAcc->username)
				{
					userAcc->myInfo = curStudent;
					return;
				}
				curStudent = curStudent->next;
			}
			curClass = curClass->next;
		}
		curYear = curYear->next;
	}
}