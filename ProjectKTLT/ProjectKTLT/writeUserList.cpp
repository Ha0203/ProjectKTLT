#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

void writeUserList(Account*& pAcc)
{
	fstream output;
	output.open("UserList.csv", ios::out);
	Account* curAcc = pAcc;
	while (curAcc != nullptr)
	{
		output << curAcc->username << "," << curAcc->password << "," << curAcc->type << "\n";
		curAcc = curAcc->next;
	}
	output.close();
}