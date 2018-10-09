/*
 *
 *  COMP 15 Project 1 - CalcYouLater
 *
 *  RPNCalc.h
 *  RPNCalc class definition
 *  Modified By (UTLN): rserot01
 *           On       : 10/14/2017
 *
 */

#include "Datum.h"
#include "DatumStack.h"
#include <sstream>

#ifndef RPNCALC_H
#define RPNCALC_H

class RPNCalc {


	public:

		RPNCalc();
		~RPNCalc();

		void run();

	private:

		void pushNum(int);
		void pushTrue();
		void pushFalse();
		void pushCodeBlock(std::istream&);
		void popNot();
		void printTop();
		void clearCalc();
		void dropTop();
		void dupTop();
		void swapTop();
		void quitCalc();

		void add();
		void subtract();
		void multiply();
		void divide();
		void modulus();

		void isGreat();
		void isLess();
		void isGreatEq();
		void isLessEq();
		void isEqual();
		void isNotEq();
		
		void exec();
		std::string parseCodeBlock(std::istringstream&);
		void iffunc();
		void file(std::string);
		void pickFunction(std::string, std::istream&);
		void runHelper(std::istream&);

		DatumStack* dtsp;
		Datum* dtp;
		Datum* dtp2;

		int a, b, c;
		bool tf;
		bool done;

		std::string s;
		std::string cb1;
		std::string cb2;
		std::istringstream iss;
};


#endif
