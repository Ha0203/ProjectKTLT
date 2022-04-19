#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void importScoreBoard(Year*& firstYear,Account*&userAcc)
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
				string filename = curYear->nameYear + curSe->nameSemester + curCo->courseID+".csv";
				input.open(filename.c_str(), ios::in);
				if (input.fail())
				{
					cout << "Can't find the file "<< filename << ".csv" << endl;
					curCo = curCo->next;
					continue;
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
					if (userAcc->myInfo != nullptr && curStu->studentID == userAcc->myInfo->studentID)
					{
						Year* myY = userAcc->firstYear;
						while (myY != nullptr && myY->nameYear != curYear->nameYear)
						{
							myY = myY->next;
						}
						if (myY == nullptr)
						{
							myY = new Year;
							myY->next = userAcc->firstYear;
							userAcc->firstYear = myY;
							myY->nameYear = curYear->nameYear;
						}
						Semester* mySe = myY->firstSemester;
						while (mySe != nullptr && mySe->nameSemester != curSe->nameSemester)
						{
							mySe = mySe->next;
						}
						if (mySe == nullptr)
						{
							mySe = new Semester;
							mySe->next = myY->firstSemester;
							myY->firstSemester = mySe;
							mySe->nameSemester = curSe->nameSemester;
						}
						Course* myC = mySe->firstCourse;
						myC->mark.final = curStu->mark.final;
						myC->mark.mid = curStu->mark.mid;
						myC->mark.total = curStu->mark.total;
					}
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