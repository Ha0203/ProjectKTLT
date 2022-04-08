#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void readCourseList(Year*& firstYear)
{
	string temp, row;
	fstream input;
	input.open("CourseList.csv", ios::in);
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
				Course* newCo = new Course;
				getline(ss, temp, ',');
				newCo->courseID = temp;
				getline(ss, temp, ',');
				newCo->courseName = temp;
				getline(ss, temp, ',');
				newCo->teacherName = temp;
				getline(ss, temp, ',');
				newCo->numberOfCredit = temp;
				getline(ss, temp, ',');
				newCo->numberOfStudents = stoi(temp);
				getline(ss, temp, ',');
				newCo->session1 = temp;
				getline(ss, temp, ',');
				newCo->session2 = temp;
				newCo->next = curSe->firstCourse;
				curSe->firstCourse = newCo;
			}
			
		}
	}
	input.close();
}