#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;
void createAccount(Account*pAcc)
{
    Account* tmpAcc = new Account;
    Account* curAcc;
    cout << "\nType in your username: ";
    cin >> tmpAcc->username;
    for (curAcc = pAcc; curAcc != nullptr; curAcc = curAcc->next)
        if (tmpAcc->username == curAcc->username)
        {
            cout << "\nUsername has already been taken. Please try another one.";
            cout << "\nType in your username: ";
            cin >> tmpAcc->username;
            curAcc = pAcc;
        }
    cout << "Username accepted!";
    cout << "\nType in your password: ";
    cin >> tmpAcc->password;
    cout << "\nType in 1 if you are an Academic staff member.";
    cout << "\nType in 2 if you are a Student.";
    cin >> tmpAcc->type;
    curAcc = tmpAcc;
    tmpAcc->next = nullptr; 
    cout << "\nAccount successfully created!";
    cout << "\nYour account information:";
    cout << "\nUsername :" << curAcc->username << "\t Password: " << curAcc->password;
}
bool login(Account*pAcc, Account*&userAcc)
{
    userAcc = new Account;
    Account* tmpAcc = pAcc;
    cout << "\nType in your username: ";
    cin >> userAcc->username;
    cout << "\nType in your password: ";
    cin >> userAcc->password;
    for (tmpAcc = pAcc; tmpAcc != nullptr; tmpAcc = tmpAcc->next)
    {
        if (userAcc->username == tmpAcc->username && userAcc->password == tmpAcc->password)
        {
            cout << "\nLogin successful!";
            delete userAcc;
            userAcc = tmpAcc;
            return true;
        }
    }
        cout << "\nLogin failed.";
        return false;
}
void changePassword(Account*& userAcc) 
{
    string temppass, checktemppass;
    cout << "\n Type in your current password: ";
    cin >> temppass;
    while (temppass != userAcc->password) 
    {
        cout << "\n Wrong password! Please try again.";
        cin >> temppass;
    }
    cout << "\n Type in your new password:";
    cin >> temppass;
    cout << "\n Type in your new password again: ";
    cin >> checktemppass;
    while (checktemppass != temppass) 
    {
        cout << "\n Wrong password! Please try again.";
        cin >> checktemppass;
    }
    userAcc->password = checktemppass;
    cout << "\n Password successfully changed!";
    cout << "\n Your new password is: " << userAcc->password;    
}