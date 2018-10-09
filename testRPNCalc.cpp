/*
 *
 *  COMP 15 Project 1 - CalcYouLater
 *
 *  testRPNCalc.cpp
 *  Test program for RPNCalc Class
 *  Modified By (UTLN): rserot01
 *           On       : 10/14/2017
 *
 */


#include "Datum.h"
#include "DatumStack.h"
#include "RPNCalc.h"
#include <iostream>


int main()
{
	
	RPNCalc newCalc;

	newCalc.runHelper("#t", std::cin);
	newCalc.runHelper("#f", std::cin);
	newCalc.runHelper("swap", std::cin);
	newCalc.runHelper("print", std::cin);

	newCalc.runHelper("2", std::cin);
	newCalc.runHelper("3", std::cin);
	newCalc.runHelper("dup", std::cin);
	newCalc.runHelper("print", std::cin);
	newCalc.runHelper("drop", std::cin);
	newCalc.runHelper("print", std::cin);
	newCalc.runHelper("drop", std::cin);
	newCalc.runHelper("print", std::cin);

	newCalc.runHelper("32", std::cin);
	newCalc.runHelper("8", std::cin);
	newCalc.runHelper("+", std::cin);
	newCalc.runHelper("print", std::cin);

	newCalc.runHelper("52", std::cin);
	newCalc.runHelper("8", std::cin);
	newCalc.runHelper("-", std::cin);
	newCalc.runHelper("print", std::cin);

	newCalc.runHelper("3", std::cin);
	newCalc.runHelper("4", std::cin);
	newCalc.runHelper("*", std::cin);
	newCalc.runHelper("print", std::cin);

	newCalc.runHelper("64", std::cin);
	newCalc.runHelper("8", std::cin);
	newCalc.runHelper("/", std::cin);
	newCalc.runHelper("print", std::cin);

	newCalc.runHelper("24", std::cin);
	newCalc.runHelper("5", std::cin);
	newCalc.runHelper("mod", std::cin);
	newCalc.runHelper("print", std::cin);

	newCalc.runHelper("12", std::cin);
	newCalc.runHelper("15", std::cin);
	newCalc.runHelper("<", std::cin);
	newCalc.runHelper("print", std::cin);

	newCalc.runHelper("23", std::cin);
	newCalc.runHelper("3", std::cin);
	newCalc.runHelper(">", std::cin);
	newCalc.runHelper("print", std::cin);

	newCalc.runHelper("12", std::cin);
	newCalc.runHelper("12", std::cin);
	newCalc.runHelper("<=", std::cin);
	newCalc.runHelper("print", std::cin);

	newCalc.runHelper("23", std::cin);
	newCalc.runHelper("23", std::cin);
	newCalc.runHelper(">=", std::cin);
	newCalc.runHelper("print", std::cin);

	newCalc.runHelper("16", std::cin);
	newCalc.runHelper("8", std::cin);
	newCalc.runHelper("==", std::cin);
	newCalc.runHelper("print", std::cin);

	newCalc.runHelper("14", std::cin);
	newCalc.runHelper("14", std::cin);
	newCalc.runHelper("!=", std::cin);
	newCalc.runHelper("print", std::cin);

	newCalc.runHelper("{ 2 3 + }", std::cin);
	newCalc.runHelper("print", std::cin);
	newCalc.runHelper("exec", std::cin);
	newCalc.runHelper("print", std::cin);

	newCalc.runHelper("{ { 2 3 + } 5 4 - }", std::cin);
	newCalc.runHelper("exec", std::cin);
	newCalc.runHelper("print", std::cin);
	newCalc.runHelper("exec", std::cin);
	newCalc.runHelper("print", std::cin);

	newCalc.runHelper("5 4 <", std::cin);
	newCalc.runHelper("{ 5 4 + print }", std::cin);
	newCalc.runHelper("{ 5 4 - print }", std::cin);
	newCalc.runHelper("if", std::cin);
	newCalc.runHelper("print", std::cin);

	newCalc.runHelper("clear", std::cin);
	newCalc.runHelper("print", std::cin);

	newCalc.runHelper("quit", std::cin);

	return 0; 
}