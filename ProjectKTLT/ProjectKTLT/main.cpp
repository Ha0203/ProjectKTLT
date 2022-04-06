#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;

int main()
{
	Account* pAcc = nullptr, * userAcc = nullptr;
	readUserList(pAcc);
	while (login(pAcc, userAcc) == 0)
	{
		cout << "\nYour user name or your password is not correct, plese enter gain";
	}
	char choice;
	cout << "\nChoose 1 if you want to change password\n";
	cout << "Otherwise, press any key\n";
	cout << "Your choice: ";
	cin >> choice;
	cin.ignore();
	if (choice == '1')
	{
		changePassword(userAcc);
	}
	Menu(userAcc);
	writeUserList(pAcc);
	return 0;
}