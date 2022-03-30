#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void createSchoolYear(Year *&firstYear)
{
    fstream input;
    Year* newYear = new Year;
    Class *temp, *temp1; 
    int n;
    cout << "\nInput the school year: ";
    cin >> newYear->nameYear;
    temp = newYear->firstClass = nullptr;
    do
    {
        temp1 = new Class;
        temp1->firstStudent = nullptr;
        cout << "\nInput name of the class: ";
        cin >> temp1->nameClass;
        cout << "\nInput name of the file which stores information of students: ";
        string filename;
        cin >> filename;
        input.open(filename.c_str(), ios::in);
        while (input.fail())
        {
            cout << "\nInput name of the file which stores in formation of students: ";
            cin >> filename;
            input.open(filename.c_str(), ios::in);
        }
        string cell, row;
        Student* curStudent = temp1->firstStudent;
        while (getline(input, row))
        {
            stringstream ss(row);
            if (temp1->firstStudent == nullptr)
            {
                temp1->firstStudent = new Student;
                curStudent = temp1->firstStudent;
            }
            else
            {
                curStudent->next = new Student;
                curStudent = curStudent->next;
            }
            curStudent->next = nullptr;
            getline(ss, cell, ',');
            curStudent->Number = cell;
            getline(ss, cell, ',');
            curStudent->studentID = cell;
            getline(ss, cell, ',');
            curStudent->firstName = cell;
            getline(ss, cell, ',');
            curStudent->lastName = cell;
            getline(ss, cell, ',');
            curStudent->gender = cell;
            getline(ss, cell, ',');
            curStudent->dateOfBirth = cell;
            getline(ss, cell, ',');
            curStudent->socialID = cell;
        }
        input.close();
        temp1->next = nullptr;
        if (temp == nullptr)
        {
            temp = temp1;
            newYear->firstClass = temp1;
        }
        else
        {
            temp->next = temp1;
            temp = temp->next;
        }
        cout << "\nChoose 1 to create a new class. ";
        cout << "\nChoose 0 to get out of this function. ";
        cin >> n;
    } while (n == 1);
    Year *tempYear = firstYear;
    while (tempYear->next != nullptr)
        tempYear = tempYear->next;
    tempYear->next = newYear;
    newYear->next = nullptr;
}


void updateClass(Year*& firstYear)
{
    string name;
    int n = 1;
    do
    {   if (n == 1)
        {
        cout << "\nChoose school year you want to update the class";
        cin >> name;}
        Year *tempyear;
        Class *tempclass, *tempclass1; // tempclass để lưu vị trí tail của class năm đó , tempclass1 sẽ cập nhật class mới
        tempyear = firstYear;
        while ( tempyear != NULL || tempyear->nameYear != name)
            tempyear = tempyear->next;
        if (tempyear->nameYear != name) cout <<"\nThis year is not available";
        else 
        {
            tempclass = tempyear->firstClass;
            while (tempclass->next != NULL)
                tempclass = tempclass->next;
            tempclass1 = new Class;
            cout << "\nInput name class: ";
            cin >> tempclass1->nameClass;
            //đọc dữ liệu học sinh tại đây nha Hà
            tempclass->next = tempclass1;
            tempclass1->next = NULL;
        }
        
        cout <<"\n Choose 1 to update a new class for other year";
        cout <<"\n Choose 2 to update a new class for same year";
        cout <<"\n Choose 0 to finish";
        cin >> n; 

    }
    while (n != 0 );
}