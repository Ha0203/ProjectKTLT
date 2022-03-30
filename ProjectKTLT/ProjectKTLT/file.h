#pragma once
#include <iostream>
#include <string>
#include"login.h"
using namespace std;


struct Student
{
    string Number;
    string studentID;
    string firstName;
    string lastName;
    string gender;
    string dateOfBirth;
    string socialID;
    Student* next;
};

struct Class
{
    Student *firstStudent;
    string nameClass;
    Class* next;
};
struct copyCourse
{
    string courseID;
    string courseName;
    string teacherName;
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
    copyCourse*firstCourse;
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
    string session;
    courseClass* firstcourseClass;
    Course* next;
};
struct Semester
{
    string nameSemester;
    string startdate;
    string enddate;
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
Course* findPos(Course* courses);
void readStudentListMain(Year*& firstYear);
void createSchoolYear(Year*& firstYear);
void viewCourses(Course* courses);
void readUserList(Account*& pAcc);
void Menu(Account* userAcc);
void updateClass(Year* firstYear);