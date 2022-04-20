#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void viewCourseScore(Year* firstYear)
{
	string temp;
	cout << "\nInput the school year (Ex: 2021-2022): ";
	cin >> temp;
	Year* curYear = firstYear;
	while (curYear != nullptr && curYear->nameYear != temp)
	{
		curYear = curYear->next;
	}
	if (curYear == nullptr)
	{
		cout << "\nThis year has not been created yet.";
		return;
	}
	cout << "\nInput the name of semester (Ex: Fall): ";
	cin >> temp;
	Semester* curSemester = curYear->firstSemester;
	while (curSemester != nullptr && curSemester->nameSemester != temp)
	{
		curSemester = curSemester->next;
	}
	if (curSemester == nullptr)
	{
		cout << "\nThis semester has not been created yet.";
		return;
	}
	cout << "\nInput the ID of the course: ";
	cin >> temp;
	Course*curCourse = curSemester->firstCourse;
	while (curCourse != nullptr && curCourse->courseID != temp)
	{
		curCourse = curCourse->next;
	}
	if (curCourse == nullptr)
	{
		cout << "\n\tThis course has not been created yet.";
		return;
	}
	//Phi
	courseStudent* curStu = curCourse->firstcourseStudent;
	cout << "Number\t" << "StudentID\t" << "FirstName\t" << "LastName\t" << "TotalMark\t" << "MidtermMark\t" << "FinalMark\n";
	while (curStu != nullptr)
	{
		cout << curStu->Number << "\t" << curStu->studentID << "\t" << curStu->firstName << "\t" << curStu->lastName << "\t" << curStu->mark.total << "\t" << curStu->mark.mid << "\t" << curStu->mark.final << "\n";
		curStu = curStu->next;
	}
}
//Phi dựa trên hàm update trong ViewCourses.cpp
void updateScore(Year* firstYear)
{

}
//Định dạng xem điểm của hàm viewMyScore
//STT CourseName Total Final Mid 
//1      VTP       7     8    5
//2      VLDC      5     8    3
//3      NMLT      6     6    6
void viewMyScore(Account*userAcc)
{
	int num = 0;
	string temp;
	cout << "\nInput the school year (Ex: 2021-2022): ";
	cin >> temp;
	Year* curYear = userAcc->firstYear;
	while (curYear != nullptr && curYear->nameYear != temp)
	{
		curYear = curYear->next;
	}
	if (curYear == nullptr)
	{
		cout << "\nThis year has not been created yet.";
		return;
	}
	cout << "\nInput the name of semester (Ex: Fall): ";
	cin >> temp;
	Semester* curSemester = curYear->firstSemester;
	while (curSemester != nullptr && curSemester->nameSemester != temp)
	{
		curSemester = curSemester->next;
	}
	if (curSemester == nullptr)
	{
		cout << "\nThis semester has not been created yet.";
		return;
	}
	Course* curC = curSemester->firstCourse;
	if (curC == nullptr)
	{
		cout << "\nYou haven't enrolled any courses yet";
		return;
	}
	cout << "\n-----Your Score----\n";
	cout << "STT\t" << "CourseName\t" << "Total\t" << "Final\t" << "Mid\n";
	int stt = 0;
	for (curC = curSemester->firstCourse; curC != nullptr; curC = curC->next)
	{
		stt++;
		cout << stt << "\t" << curC->courseName << "\t" << curC->mark.total << "\t" << curC->mark.final << "\t" << curC->mark.mid << "\n";
	}
}