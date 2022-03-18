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

void createAccount(Account*pAcc);
bool login(Account*pAcc, Account*& userAcc);