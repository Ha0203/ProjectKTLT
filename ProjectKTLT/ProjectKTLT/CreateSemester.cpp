#include "file.h"

void createSemester(Year*& firstYear)
{
    cout << "\nInput the school year whose semester you want to create: ";
    string temp;
    cin >> temp;
    Year* curYear = firstYear;
    while (curYear != nullptr && curYear->nameYear != temp)
    {
        curYear = curYear->next;
    }
    if (curYear == nullptr)
    {
        cout << "\nThis year has not been created yet";
        return;
    }
    Semester *newSemester = new Semester;
    int choice;
    cout << "\nInput semester name: ";
    cin >> newSemester->nameSemester;
    cout << "\nInput start date: ";
    cin >> newSemester->startdate;
    cout << "\nInput end date: ";
    cin >> newSemester->enddate;
    newSemester->firstCourse = nullptr;
    do {
        addCourse(newSemester->firstCourse);
        cout << "\nType in 1 to create a new course. ";
        cout << "\nType in 0 to get out of this function. ";
        cout << "\nYour choice: ";
        cin >> choice;
    } while (choice == 1);
    if (curYear->firstSemester == nullptr) 
    {
        curYear->firstSemester = newSemester;
        newSemester->next = nullptr;
    }
    else
    {
        newSemester->next = curYear->firstSemester;
        curYear->firstSemester = newSemester;
    }
}

void addCourse(Course *& firstCourse)
{
    Course *newCourse = new Course;
    cout << "\nInput course ID: ";
    cin >> newCourse->courseID;
    cout << "\nInput course name: ";
    cin.ignore();
    getline(cin, newCourse->courseName);
    cout << "\nInput teacher name: ";
    getline(cin, newCourse->teacherName);
    cout << "\nInput number of credits: ";
    cin >> newCourse->numberOfCredit;
    cout << "\nInput the maximum number of students in the course: ";
    cin >> newCourse->numberOfStudents;
    cout << "\nInput session 1 of this course: ";
    cin >> newCourse->session1;
    cout << "\nInput session 2 of this course: ";
    cin >> newCourse->session2;
    getline(cin, newCourse->session2);
    newCourse->next = firstCourse;
    firstCourse = newCourse;
}


void courseRegist(Year*&firstYear) 
{
    cout << "\nChoose the school year: ";
    string temp;
    cin >> temp;
    Year* curYear = firstYear;
    while (curYear != nullptr && curYear->nameYear != temp)
    {
        curYear = curYear->next;
    }
    if (curYear == nullptr)
    {
        cout << "\nThis year has not been created yet";
        return;
    }
    cout << "\nChoose the semester: ";
    cin >> temp;
    Semester* curSe = curYear->firstSemester;
    while (curSe != nullptr && curSe->nameSemester != temp)
    {
        curSe = curSe->next;
    }
    if (curSe == nullptr)
    {
        cout << "\nThis semester has not been created yet";
        return;
    }
    int choice;
    do 
    {
        cout << "\nType in 1 to open course registration for this semester.";
        cout << "\nType in 0 to close course registration for this semester.";
        cin >> choice;
        switch (choice) 
        {
        case 1:
            if (curSe->registSession == 1)
                cout << "\nCourse registration is already open!";
            else 
            {
                curSe->registSession = 1;
                cout << "\nCourse registration is now open!";
            }
            break;
        case 0:
            if (curSe->registSession == 0)
                cout << "\nCourse registration is already closed!";
            else 
            {
                curSe->registSession = 0;
                cout << "\nCourse registration is now closed!";
            }
            break;
        default:
            cout << "\nWrong choice!";
            break;
        }
    } while (choice != 1 && choice != 0);
}