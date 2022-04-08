#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void readSemesterList(Year*& firstYear)
{
	string temp, row;
	fstream input;
	input.open("SemesterList.csv", ios::in);
	if (input.fail())
	{
		cout << "Can't find the file " << endl;
		return;
	}
	while (getline(input, row))
	{
		stringstream ss(row);
		Year* curYear = firstYear;
		getline(ss, temp, ',');
		while (curYear != nullptr && curYear->nameYear != temp)
		{
			curYear = curYear->next;
		}
		if (curYear != nullptr)
		{
			Semester* newSe = new Semester;
			getline(ss, temp, ',');
			newSe->nameSemester = temp;
			getline(ss, temp, ',');
			newSe->startdate = temp;
			getline(ss, temp, ',');
			newSe->enddate = temp;
			getline(ss, temp, ',');
			newSe->registSession = stoi(temp);
			newSe->next = curYear->firstSemester;
			curYear->firstSemester = newSe;
		}
	}
	input.close();
}