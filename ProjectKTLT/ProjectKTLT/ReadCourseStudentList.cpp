#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void readCourseStudentList(Year*& firstYear,Account*& userAcc)
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
						if (userAcc->myInfo != nullptr && newStu->studentID == userAcc->myInfo->studentID)
						{
							Year* myY = userAcc->firstYear;
							while (myY != nullptr && myY->nameYear != curYear->nameYear)
							{
								myY = myY->next;
							}
							if (myY == nullptr)
							{
								Year*newY = new Year;
								newY->next = userAcc->firstYear;
								userAcc->firstYear = newY;
								newY->nameYear = curYear->nameYear;
								myY = newY;
							}
							Semester* mySe = myY->firstSemester;
							while (mySe != nullptr && mySe->nameSemester != curSe->nameSemester)
							{
								mySe = mySe->next;
							}
							if (mySe == nullptr)
							{
								Semester*newSe = new Semester;
								newSe->next = myY->firstSemester;
								myY->firstSemester = newSe;
								newSe->nameSemester = curSe->nameSemester;
								mySe = newSe;
							}
							Course* myC = mySe->firstCourse;
							while (myC != nullptr && myC->courseID != curCo->courseID)
							{
								myC = myC->next;
							}
							if (myC == nullptr)
							{
								Course* newCo = new Course;
								newCo->next = mySe->firstCourse;
								mySe->firstCourse = newCo;
								newCo->courseID = curCo->courseID;
								myC = newCo;
								myC->courseID = curCo->courseID;
								myC->courseName = curCo->courseName;
								myC->teacherName = curCo->teacherName;
								myC->numberOfCredit = curCo->numberOfCredit;
								myC->numberOfStudents = curCo->numberOfStudents;
								myC->session1 = curCo->session1;
								myC->session2 = curCo->session2;
							}
						}
					}
				}
			}

		}
	}
	input.close();
}