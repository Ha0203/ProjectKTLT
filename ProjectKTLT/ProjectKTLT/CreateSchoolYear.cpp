#include <iostream>
#include <fstream>
#include <sstream>
#include "file.h"
using namespace std;

void createSchoolYear(Year *firstYear)
{
    //Đang cần 1 hàm đọc file csv cho năm học mới
    // Thêm 1 hàm để đẩy data ra file dữ liệu tổng
    Year *newYear;
    Class *temp, *temp1; // temp dùng để lưu vị trí cuối cùng của danh sách lớp, temp1 dùng để tạo lớp mới
    int i, n;

    cout << "\n Nhập năm học: ";
    cin >> newYear->nameYear;
    temp = newYear->firstClass = nullptr;
    do
    {
        temp1 = new Class;
        cout << "\n Nhập tên lớp: ";
        cin >> temp1->nameClass;
        // Hàm đọc file student ở đây (chỉ có 1 lớp)
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
        cout << "\n Nhấn phím 1 để tạo lớp mới. ";
        cout << "\n Nhấn phím 0 để thoát. ";
        cin >> n;
    } while (n == 1);
    Year *tempYear = firstYear;
    while (tempYear->next != nullptr)
        tempYear = tempYear->next;
    tempYear->next = newYear;
    newYear->next = nullptr;
    // Hàm lưu lại thay đổi data ở đây
}