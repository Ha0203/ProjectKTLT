#include <iostream>
using namespace std;
#include "login.h"
void createAccount(Account*pAcc)
{
    Account* tmpAcc = new Account;
    Account* curAcc;
    cout << "\n Type in your username: ";
    cin >> tmpAcc->username;
    for (curAcc = pAcc; curAcc != nullptr; curAcc = curAcc->next)
        if (tmpAcc->username == curAcc->username)
        {
            cout << "\n Username has already been taken. Please try another one.";
            cout << "\n Type in your username: ";
            cin >> tmpAcc->username;
            curAcc = pAcc;
        }
    cout << "Username accepted!";
    cout << "\n Type in your password: ";
    cin >> tmpAcc->password;
    cout << "\n Type in 1 if you are an Academic staff member.";
    cout << "\n Type in 2 if you are a Student.";
    cin >> tmpAcc->type;
    curAcc = tmpAcc;
    tmpAcc->next = nullptr; 
    cout << "\n Account successfully created!";
    cout << "\n Your account information:";
    cout << "\n Username :" << curAcc->username << "\t Password: " << curAcc->password;
}
bool login(Account*pAcc, Account*&userAcc)
{
    userAcc = new Account;
    Account* tmpAcc = pAcc;
    cout << "\n Type in your username: ";
    cin >> userAcc->username;
    cout << "\n Type in your password:";
    cin >> userAcc->password;
    for (tmpAcc = pAcc; tmpAcc != nullptr; tmpAcc = tmpAcc->next) 
        if (userAcc->username == tmpAcc->username && userAcc->password == tmpAcc->password)
            {
                cout << "\n Login successful!";
                delete userAcc;
                userAcc = tmpAcc;
                return true;
            }
        else cout << "\n Login failed.";
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