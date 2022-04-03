#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void enrollCourse(Year*&firstYear, Account*&userAcc)
{
	string temp;
	cout << "\nInput the school year of yours";
	cin >> temp;
	Year* curYear = firstYear;
	while (curYear != nullptr && curYear->nameYear != temp)
	{
		curYear = curYear->next;
	}
	if(curYear==nullptr)
	{
		cout << "\nThis year has not been created yet";
		return;
	}
	cout << "\nInput the name of semester";
	cin >> temp;
	Semester* curSemester = curYear->firstSemester;
	while (curSemester != nullptr && curSemester->nameSemester != temp)
	{
		curSemester = curSemester->next;
	}
	if (curSemester == nullptr)
	{
		cout << "\nThis semester has not been craeted yet";
		return;
	}
	cout << "\nThese are the list of courses in this semester";
	Course* curCourse = curSemester->firstCourse;
	while (curCourse != nullptr)
	{

	}
}