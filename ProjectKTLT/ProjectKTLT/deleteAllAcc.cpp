#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "file.h"
using namespace std;
void deleteAllAcc(Account*& pAcc)
{
	Account* curAcc = pAcc;
	while (curAcc != nullptr)
	{
		Year* curY = curAcc->firstYear;
		if (curY != nullptr)
		{
			Semester* curSe = curY->firstSemester;
			if (curSe != nullptr)
			{
				Course* curCo = curSe->firstCourse;
				if (curCo != nullptr)
				{
					delete curCo;
				}
				delete curSe;
			}
			delete curY;
		}
		Account* tempAcc = curAcc;
		curAcc = curAcc->next;
		delete tempAcc;
	}
}