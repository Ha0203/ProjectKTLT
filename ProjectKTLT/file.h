#pragma once

#include <string>
using namespace std;


struct Student
{
    int Number;
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

void createNewYear (Year *&lastYear);
