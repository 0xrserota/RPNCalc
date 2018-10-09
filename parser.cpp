/*
 *
 *  COMP 15 Project 1 - CalcYouLater
 *
 *  DatumStack.cpp
 *  DatumStack class implmentation
 *  Modified By (UTLN): rserot01
 *           On       : 10/24/2017
 *
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string parseCodeBlock(istream&);



string parseCodeBlock(istream &input)
{

	string cb;
	string parsedcb;
	int count = 0;
	int first = 0;

	do 
	{
		input >> cb;
		if (cb == "{")
		{
			++count;
		}

		else if (cb == "}")
		{
			--count;
		}

		if (count != 0 and first != 0)
			parsedcb += cb;

		++first;

	} while (count != 0);

	
	return parsedcb;

}


