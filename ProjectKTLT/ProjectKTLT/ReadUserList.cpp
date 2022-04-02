#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void readUserList (Account*&pAcc)
{
	pAcc = nullptr;
	Account* curAcc = pAcc;
	string temp, row;
	fstream input;
	input.open("UserList.csv", ios::in);
	if (input.fail())
	{
		cout << "Can't find the file " << endl;
		return;
	}
	while (getline(input, row))
	{
		stringstream ss(row);
		if (pAcc == nullptr)
		{
			pAcc = new Account;
			curAcc = pAcc;
		}
		else
		{
			curAcc->next = new Account;
			curAcc = curAcc->next;
		}
		curAcc->next = nullptr;
		getline(ss, temp, ',');
		curAcc->username = temp;
		getline(ss, temp, ',');
		curAcc->password = temp;
		getline(ss, temp, ',');
		curAcc->type = stoi(temp);
	}
	input.close();
}