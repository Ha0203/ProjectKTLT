#include "file.h"
#include "login.h"

void createSemester(Semester *& firstSemester)
{
    Semester *newSemester = new Semester;
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
        cout << "\n Type in 1 to create new course. ";
        cout << "\n Type in 0 to get out of this function. ";
        cout << "\n Your choice: ";
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
    Course *curCourse = firstCourse;
    Course *newCourse = new Course;
    newCourse->firstcourseClass = nullptr;
    cout << "Input course ID: ";
    getline(cin, newCourse->courseID);
    cout << "Input course name: ";
    getline(cin, newCourse->courseName);
    cout << "Input teacher name: ";
    getline(cin, newCourse->teacherName);
    cout << "Input number of credits: ";
    cin >> newCourse->numberOfCredit;
    cout << "Input the maximum number of students in the course: ";
    cin >> newCourse->numberOfStudents;
    cout << "Input day of session 1: ";
    getline(cin, newCourse->day1);
    cout << "Input time of session 1: ";
    getline(cin, newCourse->time1);
    cout << "Input day of session 2: ";
    getline(cin, newCourse->day2);
    cout << "Input time of session 2: ";
    getline(cin, newCourse->time2);
    if (curCourse == nullptr)
    {
        curCourse = newCourse;
        newCourse->next = nullptr;
    }
    else
    {
        newCourse->next = curCourse;
        curCourse = newCourse;
    }
}
