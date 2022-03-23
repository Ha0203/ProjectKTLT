#include <iostream>
#include"file.h"
using namespace std;

int main()
{
	Year* firstYear = nullptr;
	readStudentListMain(firstYear);
	cout << firstYear->firstClass->firstStudent->next->firstName;
	createSchoolYear(firstYear);
	cout << "Member information" << endl;
	cout << firstYear->next->firstClass->firstStudent->firstName;
	return 0;
}