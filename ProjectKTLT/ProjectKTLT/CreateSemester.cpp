#include "file.h"

void createSemester(Semester*& firstSemester)
{
    Semester *newSemester = new Semester;
    newSemester->registSession;
    int choice;
    cout << "\nInput semester name: ";
    getline(cin, newSemester->nameSemester);
    cout << "\nInput start date: ";
    getline(cin, newSemester->startdate);
    cout << "\nInput end date: ";
    getline(cin, newSemester->enddate);
    newSemester->firstCourse = nullptr;
    do {
        addCourse(newSemester->firstCourse);
        cout << "\nType in 1 to create new course. ";
        cout << "\nType in 0 to get out of this function. ";
        cout << "\nYour choice: ";
        cin >> choice;
    } while (choice == 1);
    if (firstSemester == nullptr) 
    {
        firstSemester = newSemester;
        newSemester->next = nullptr;
    }
    else
    {
        newSemester->next = firstSemester;
        firstSemester = newSemester;
    }
}

void addCourse(Course *& firstCourse)
{
    Course *newCourse = new Course;
    newCourse->firstcourseClass = nullptr;
    cout << "\nInput course ID: ";
    getline(cin, newCourse->courseID);
    cout << "\nInput course name: ";
    getline(cin, newCourse->courseName);
    cout << "\nInput teacher name: ";
    getline(cin, newCourse->teacherName);
    cout << "\nInput number of credits: ";
    cin >> newCourse->numberOfCredit;
    cout << "\nInput the maximum number of students in the course: ";
    cin >> newCourse->numberOfStudents;
    cout << "\nInput day of session 1: ";
    getline(cin, newCourse->day1);
    cout << "\nInput time of session 1: ";
    getline(cin, newCourse->time1);
    cout << "\nInput day of session 2: ";
    getline(cin, newCourse->day2);
    cout << "\nInput time of session 2: ";
    getline(cin, newCourse->time2);
    if (firstCourse == nullptr)
    {
        firstCourse = newCourse;
        newCourse->next = nullptr;
    }
    else
    {
        newCourse->next = firstCourse;
        firstCourse = newCourse;
    }
}


void courseRegist(Semester*& firstSemester) 
{
    int choice;
    do 
    {
        cout << "\nType in 1 to open course registration for this semester.";
        cout << "\nType in 0 to close course registration for this semester.";
        cin >> choice;
        switch (choice) 
        {
        case 1:
            if (firstSemester->registSession == true)
                cout << "\nCourse registration is already open!";
            else 
            {
                firstSemester->registSession = true;
                cout << "\nCourse registration is now open!";
            }
            break;
        case 0:
            if (firstSemester->registSession == false)
                cout << "\nCourse registration is already closed!";
            else 
            {
                firstSemester->registSession = false;
                cout << "\nCourse registration is now closed!";
            }
            break;
        default:
            cout << "\nWrong choice!";
            break;
        }
    } while (choice != 1 && choice != 0);
}