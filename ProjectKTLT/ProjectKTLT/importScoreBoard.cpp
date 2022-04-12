#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void importScoreBoard(Year*& firstYear)
{
	fstream input;
	Year* curYear = firstYear;
	string temp, row;
	while (curYear != nullptr)
	{
		Semester* curSe = curYear->firstSemester;
		while (curSe != nullptr)
		{
			Course* curCo = curSe->firstCourse;
			while (curCo != nullptr)
			{
				courseStudent* curStu = curCo->firstcourseStudent;
				string filename = curYear->nameYear + curSe->nameSemester + curCo->courseID;
				input.open(filename.c_str(), ios::out);
				if (input.fail())
				{
					cout << "Can't find the file "<< filename << ".csv" << endl;
					break;

				}
				while (getline(input, row) && curStu!=nullptr)
				{
					stringstream ss(row);
					getline(ss, temp, ',');
					getline(ss, temp, ',');
					getline(ss, temp, ',');
					getline(ss, temp, ',');
					curStu->mark.total = stoi(temp);
					getline(ss, temp, ',');
					curStu->mark.final = stoi(temp);
					getline(ss, temp, ',');
					curStu->mark.mid = stoi(temp);
					curStu = curStu->next;
				}
				input.close();
				curCo = curCo->next;
			}
			curSe = curSe->next;
		}
		curYear = curYear->next;
	}
}