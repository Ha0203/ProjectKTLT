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

struct Year
{
    Class *firstClass;
    string nameYear;
    Year *next;
};
void readStudentListMain(Year*& firstYear);
void createSchoolYear(Year* firstYear);
