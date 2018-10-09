#include "Datum.h"
#include <iostream>

using namespace std;

int main()
{
	Datum* dt = new Datum(1);
	if (dt -> isBool())
	{
		cout << "yup" << endl;
		return 0;
	}

	else
	{
		cout << "nope" << endl;
		return -1;
	}

}

