#pragma once

#include <string>
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
    string session;
    courseClass* firstcourClass;
};
struct Semester
{
    string nameSemester;
    string startdate;
    string enddate;
    Course* firstCourse;
};
struct Year
{
    Class *firstClass;
    string nameYear;
    Year *next;
    Semester* firstSemester;
};
void readStudentListMain(Year*& firstYear);
void createSchoolYear(Year* firstYear);