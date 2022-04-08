#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void writeSemesterList(Year*& firstYear)
{
	fstream output;
	Year* curYear = firstYear;
	output.open("SemesterListDemo.csv", ios::out);
	while (curYear != nullptr)
	{
		Semester* curSe = curYear->firstSemester;
		while (curSe != nullptr)
		{
			output << curYear->nameYear << "," << curSe->nameSemester << "," << curSe->startdate << "," << curSe->enddate << "," << curSe->registSession << "\n";
			curSe = curSe->next;
		}
		curYear = curYear->next;
	}
	output.close();
}