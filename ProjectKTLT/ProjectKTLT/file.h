#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <Windows.h>
#include "file.h"
using namespace std;

struct Mark
{
    int total = -1;
    int final = -1;
    int mid = -1;
};
struct Student
{
    string Number;
    string studentID;
    string firstName;
    string lastName;
    string gender;
    string dateOfBirth;
    string socialID;
    Student* next = nullptr;
};
struct Class
{
    Student* firstStudent = nullptr;
    string nameClass;
    Class* next = nullptr;
};
struct courseStudent
{
    int Number = -1;
    string studentID;
    string firstName;
    string lastName;
    string gender;
    string dateOfBirth;
    string socialID;
    Mark mark;
    courseStudent* next = nullptr;
};
struct Course
{
    string courseID;
    string courseName;
    string teacherName;
    string numberOfCredit;
    int numberOfStudents = 50;
    string session1;
    string session2;
    courseStudent* firstcourseStudent = nullptr;
    Course* next = nullptr;
    Mark mark;
};
struct Semester
{
    string nameSemester;
    string startdate;
    string enddate;
    int registSession = 0;
    Course* firstCourse = nullptr;
    Semester* next = nullptr;
};
struct Year
{
    Class* firstClass = nullptr;
    string nameYear;
    Year* next = nullptr;
    Semester* firstSemester = nullptr;
};
struct Account
{
    string username;
    string password;
    int type;
    Student* myInfo = nullptr;
    Year* firstYear = nullptr;
    Account* next = nullptr;
};
Course* findPos(Course* year, int choice);
void readStudentListMain(Year*& firstYear);
void createSchoolYear(Year*& firstYear);
void createSemester(Year*& firstYear);
void addCourse(Course*& firstCourse);
void courseRegist(Year*&firstYear);
void viewCourses(Year* year);
void update(Year* year);
void deleteCourse(Year* year);
void readUserList(Account*& pAcc);
void updateClass(Year*&firstYear);
void writeStudentListMain(Year*& firstYear);
void writeUserList(Account*& pAcc);
void deleteAll(Year*& firstYear);
void deleteAllAcc(Account*& pAcc);
void createAccount(Account* pAcc);
bool login(Account* pAcc, Account*& userAcc);
void changePassword(Account*& userAcc);
void updatemyInfo(Account* userAcc, Year* firstYear);
void menu(Account* userAcc);
void viewClass(Year* year);
void viewStuClass(Year* year);
void viewStuCourse(Year* year);
void readSemesterList(Year*& firstYear);
void writeSemesterList(Year*& firstYear);
void readCourseList(Year*& firstYear);
void writeCourseList(Year*& firstYear);
void readCourseStudentList(Year*& firstYear,Account*& userAcc);
void writeCourseStudentList(Year*& firstYear);
bool checkexistCourse(Year*curY,Semester*curSe,Course* curC, Account* userAcc);
void putStuInCourse(Course* cur, Account* userAcc);
void updateMyC(Year* curY, Semester* curSe, Course* curC, Account* userAcc);
bool checkNumStu(Course* cur);
bool checkNumCourse(Year* curY, Semester* curSe, Account* userAcc);
bool checkCourse(Year* curY, Semester* curSe, Course* curC, Account* userAcc);
void enrollCourse(Year*& firstYear, Account*& userAcc);
void exportCourseStudent(Year*& firstYear);
void importScoreBoard(Year*& firstYear, Account*& userAcc);
void viewCourseScore(Year* firstYear);
