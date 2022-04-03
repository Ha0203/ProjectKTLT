#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

struct copyCourse
{
    string courseID;
    string courseName;
    string teacherName;
    int numberOfCredit;
    int numberOfStudents;
    string day1;
    string time1;
    string day2;
    string time2;
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
    copyCourse* firstCourse;
    Student* next;
};
struct Account
{
    string username;
    string password;
    int type;
    Student* myInfo;
    Account* next;
};
struct Class
{
    Student *firstStudent;
    string nameClass;
    Class* next;
};
struct courseStudent
{
    string Number;
    string studentID;
    string firstName;
    string lastName;
    string gender;
    string dateOfBirth;
    string socialID;
    courseStudent* next;
};
struct courseClass
{
    courseStudent* firstcourseStudent;
    string namecourseClass;
    courseClass* next;
};
struct Course
{
    string courseID;
    string courseName;
    string teacherName;
    int numberOfCredit;
    int numberOfStudents;
    string day1;
    string time1;
    string day2;
    string time2;
    courseClass* firstcourseClass;
    Course* next;
};
struct Semester
{
    string nameSemester;
    string startdate;
    string enddate;
    bool registSession = false;
    Course* firstCourse;
    Semester* next;
};
struct Year
{
    Class *firstClass;
    string nameYear;
    Year *next;
    Semester* firstSemester;
};
Course* findPos(Year* year, int choice);
void readStudentListMain(Year*& firstYear);
void createSchoolYear(Year*& firstYear);
void createSemester(Semester*& firstSemester);
void addCourse(Course*& firstCourse);
void courseRegist(Semester*& firstSemester);
void viewCourses(Year* year);
void update(Year* year);
void deleteCourse(Year* year);
void readUserList(Account*& pAcc);
void Menu(Account* userAcc);
void updateClass(Year*&firstYear);
void writeStudentListMain(Year*& firstYear);
void writeUserList(Account*& pAcc);
void deleteAll(Year*& firstYear);
void deleteAllAcc(Account*& pAcc);
void createAccount(Account* pAcc);
bool login(Account* pAcc, Account*& userAcc);
void changePassword(Account* pAcc);
void updatemyInfo(Account* userAcc, Year* firstYear);