#pragma once

#include <string>
using namespace std;
struct Account
{
    string username;
    string password;
    int type;
    Account* next;
};
struct User 
{
    string usname;
    string pass;
    User* next;
};


Account* createNewAccount();
void creatAccount(Account*pAcc);
void login(User*pUser);
bool checkLogin(Account*pAcc, User*pUser);