#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;
void deleteAllAcc(Account*& pAcc)
{
	while (pAcc != nullptr)
	{
		Account* tempAcc = pAcc;
		pAcc = pAcc->next;
		delete tempAcc;
	}
}