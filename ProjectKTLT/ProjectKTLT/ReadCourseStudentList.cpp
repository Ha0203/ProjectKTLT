#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void readCourseStudentList(Year*& firstYear)
{
	string temp, row;
	fstream input;
	input.open("CourseStudentList.csv", ios::in);
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
			Semester* curSe = curYear->firstSemester;
			getline(ss, temp, ',');
			while (curSe != nullptr && curSe->nameSemester != temp)
			{
				curSe = curSe->next;
			}
			if (curSe != nullptr)
			{
				Course* curCo = curSe->firstCourse;
				getline(ss, temp, ',');
				{
					while (curCo != nullptr && curCo->courseID != temp)
					{
						curCo = curCo->next;
					}
					if (curCo != nullptr)
					{
						courseStudent* newStu = new courseStudent;
						getline(ss, temp, ',');
						newStu->Number = stoi(temp);
						getline(ss, temp, ',');
						newStu->studentID = temp;
						getline(ss, temp, ',');
						newStu->firstName = temp;
						getline(ss, temp, ',');
						newStu->lastName = temp;
						getline(ss, temp, ',');
						newStu->gender = temp;
						getline(ss, temp, ',');
						newStu->dateOfBirth = temp;
						getline(ss, temp, ',');
						newStu->socialID = temp;
						if (curCo->firstcourseStudent == nullptr)
						{
							curCo->firstcourseStudent = newStu;
						}
						else
						{
							courseStudent* curStu = curCo->firstcourseStudent;
							while (curStu->next != nullptr)
								curStu = curStu->next;
							curStu->next = newStu;
						}
						newStu->next = nullptr;
					}
				}
			}

		}
	}
	input.close();
}