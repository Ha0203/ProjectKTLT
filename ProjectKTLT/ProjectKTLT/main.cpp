#include <iostream>
#include"file.h"
using namespace std;

int main()
{
	Year* firstYear = nullptr;
	readStudentListMain(firstYear);
	cout << firstYear->firstClass->next->firstStudent->firstName << endl;
	cout << "Member information" << endl;
	return 0;
}