/*
 *
 *  COMP 15 Project 1 - CalcYouLater
 *
 *  testDatumStack.cpp
 *  DatumStack test program
 *  Modified By (UTLN): rserot01
 *           On       : 10/05/2017
 *
 */

#include "Datum.h"
#include "DatumStack.h"
#include <iostream>

using namespace std;


int main()
{
	//Datum dtArray[5] = {1, 2, 3, 4, 5};

	Datum dt = Datum(6);
	Datum dt2 = Datum(9);
	cout << "hi" <<endl;
	DatumStack nStack;



//void testIsEmpty(DatumStack nStack)
//{
	cout << "\ntesting isEmpty" << endl;
	bool empty = nStack.isEmpty();
	cout << "called isEmpty" << endl;
	if (empty)
		cout << "empty!" << endl;
	else 
		cout << "not empty!" << endl;
//}

nStack.push(Datum(5));
//void testSize(DatumStack nStack)
//{
	cout << "\ntesting size" << endl;
	int size = nStack.size();
	cout << "called size" << endl;
	if (size == 1)
		cout << "good!" << endl;
	else cout << "bad!" << endl;
//}

//void testTop(DatumStack nStack)
//{
	cout << "\ntesting top" << endl;
	//nStack.top();
	cout << "called top" << endl;
	// cout << "Top of stack: " << nStack.top().getInt() << endl;
//}

//void testPush(DatumStack nStack, Datum dt1)
//{
	cout << "\ntesting push" << endl;
	nStack.push(dt);
	cout << "Top of stack: " << nStack.top().getInt() << endl;
	nStack.push(dt2);
	cout << "called push" << endl;
	cout << "Top of stack: " << nStack.top().getInt() << endl;
	cout << nStack.size() << endl;
//}

//void testPop(DatumStack nStack)
//{
	cout << "\ntesting pop" << endl;
	nStack.pop();
	cout << "called pop" << endl;
	cout << "Top of stack: " << nStack.top().getInt() << endl;
//}

//void testClear(DatumStack nStack)
//{
	cout << "\ntesting clear" << endl;
	nStack.clear();
	cout << "called clear" << endl;
//}	

	return 0;
}

