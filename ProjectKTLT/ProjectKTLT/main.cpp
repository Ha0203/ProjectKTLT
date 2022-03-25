#include <iostream>
#include"login.h"
#include"file.h"
using namespace std;

int main()
{
	Account* pAcc = nullptr, * userAcc = nullptr;
	readUserList(pAcc);
	while (login(pAcc, userAcc) == 0)
	{
		cout << "\nYour user name or your password is not correct, plese enter gain";
	}
	Menu(userAcc);
	return 0;
}