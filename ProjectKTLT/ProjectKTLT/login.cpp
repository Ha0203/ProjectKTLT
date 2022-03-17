#include <iostream>
using namespace std;

#include "login.h"

Account* createNewAccount(){
    Account* newAccount = new Account;
    newAccount->next = nullptr;
    return newAccount;
}
void creatAccount(Account*pAcc)
{
    cout << "Type in your username";
    cin >> pAcc->username;
    for (Account* curAcc = pAcc; curAcc != null; curAcc = curAcc->next)
        if (pAcc->username=curAcc->username)
        {
            cout << "Username has already been taken. Please try another one.";
            cin >> pAcc->username;
        }
        
    cout << "\n Type in your password";
    cin >> pAcc->password;
    cout << "\n Type in 1 if you are an Academic staff member";
    cout << "\n Type in 2 if you are a Student";
    cin >> pAcc->type;
}
void login(User*pUser)
{
    cout << "Type in your username";
    cin >> pUser->usname;
    cout << "Type in your password";
    cin >> pUser->pass;
}

bool checkLogin(Account*pAcc, User*pUser)
{
    if (pUser->usname == pAcc->username && pUser->pass == pAcc->password)
    return true
    else return false
}