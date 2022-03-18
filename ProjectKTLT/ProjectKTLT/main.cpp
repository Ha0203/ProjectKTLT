#include <iostream>
#include"file.h"
using namespace std;

int main()
{
	Year* firstYear = nullptr;
	readStudentListMain(firstYear);
	cout << "Member information" << endl;
	return 0;
}