//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <string>
//#include "file.h"
//using namespace std;
//
//void viewMyCourse(Year* firstYear, Account* userAcc)
//{
//	cout << "courseID\tcourseName\tteacherName\tnumberOfCredit\tnumberOfStudents\tday1\ttime1\tday2\ttime2" << endl;
//	Year* curYear = firstYear;
//	while (curYear != nullptr)
//	{
//		Semester* curSemester = curYear->firstSemester;
//		{
//			while (curSemester != nullptr)
//			{
//				Course* curCourse = curSemester->firstCourse;
//				while (curCourse != nullptr)
//				{
//					courseClass* curcourseClass = curCourse->firstcourseClass;
//					while (curcourseClass != nullptr)
//					{
//						courseStudent* curcourseStudent = curcourseClass->firstcourseStudent;
//						while (curcourseStudent != nullptr)
//						{
//							if (curcourseStudent->studentID == userAcc->username)
//							{
//								cout << curcourseStudent->firstCourse->courseID << "\t" << curcourseStudent->firstCourse->courseName << "\t" << curcourseStudent->firstCourse->teacherName << "\t" << curcourseStudent->firstCourse->numberOfStudents << "\t" << curcourseStudent->firstCourse->day1 << "\t" << curcourseStudent->firstCourse->time1 << "\t" << curcourseStudent->firstCourse->day2 << "\t" << curcourseStudent->firstCourse->time2 << endl;
//								break;
//							}
//							curcourseStudent = curcourseStudent->next;
//						}
//						curcourseClass = curcourseClass->next;
//					}
//					curCourse = curCourse->next;
//				}
//				curSemester = curSemester->next;
//			}
//		}
//		curYear = curYear->next;
//	}
//}