/*
 *
 *  COMP 15 Project 1 - CalcYouLater
 *
 *  RPNCalc.cpp
 *  RPNCalc class implementation
 *  Modified By (UTLN): rserot01
 *           On       : 10/14/2017
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "RPNCalc.h"


using namespace std;


// RPNCalc constructor
RPNCalc::RPNCalc()					
{
	dtsp = new DatumStack;			// Allocate a DatumStack
}

// Blank RPNCalc destructor
RPNCalc::~RPNCalc()					
{}

// Executive function
void RPNCalc::run()					// run
{		

	istream& is = cin;
	runHelper(is);

	return;							// return to quit program
}

// Pushes an integer Datum to the stack
void RPNCalc::pushNum(int num)
{
	dtp = new Datum(num);           // datum pointer gets new integer Datum
	dtsp->push(dtp);				// Call DatumStack::push(datum pointer)
}

// Pushes true to the stack
void RPNCalc::pushTrue()			
{
	dtp = new Datum(true);			// new bool Datum
	dtsp->push(dtp);				// Call DatumStack::push(datum pointer)
}

// Pushes false to the stack
void RPNCalc::pushFalse()
{
	dtp = new Datum(false);
	dtsp->push(dtp);				// Call DatumStack::push(datum pointer)
}

// Pushes a codeblock to the stack
void RPNCalc::pushCodeBlock(istream& is)
{

	string cblock;					// Declare string to take input 
	string output = "{";			// Declare output string, initialize to {
	int count = 1;												

	do 								
	{	
		is >> cblock;				// Get input from iss (istringstream)
		if (cblock == "{")          // if cblock is "{"
			++count;				// Increment counter

		else if (cblock == "}")		// If cblock is "}"
			--count;				// decrement counter

		if (count != 0)
		{
			output += " ";				// add spaces between strings
			output += cblock;			// Append input string to output string
		}
 		
 		else if (count == 0)
 		{
 			output += " ";				// add spaces between strings
 			output += cblock;			// append to output string
 		}

	} while (count != 0);			// While count non-zero (brackets not matched)

	dtp = new Datum(output);		// Datum pointer gets new string datum
	dtsp->push(dtp);				// Push datum pointer

}

// Pops boolean on top, pushes boolean inverse
void RPNCalc::popNot()
{
	if (dtsp->top().isBool())        // if top is a bool datum
	{
		Datum dt = dtsp->top();      // Assign top to datum
		dtsp->pop();				 // call pop
		tf = !(dt.getBool());        // bool tf gets boolean inverse
		dtp = new Datum(tf);         // Make new bool datum
		dtsp->push(dtp);             // Call DatumStack::push(datum pointer)
	}

	else
	{
		cerr << "Error: Datum_not_bool" << endl; // Catch exception
		return;  					 
	}
}

// Prints the top datum
void RPNCalc::printTop()
{
	if (dtsp->isEmpty())			// if stack is empty, catch exception
	{
		cerr << "Error: empty_stack" << endl;
		return;
	}
	
	else
	{
		if (dtsp->top().isBool())	// if top of stack is bool
		{
			if (dtsp->top().getBool() == true)  // Check if "true"
				cout << "#t" << endl;			// print #t
			else								// else it's "false"
				cout << "#f" << endl;			// print #f
		}
		else if (dtsp->top().isInt())			  // else if integer
			cout << dtsp->top().getInt() << endl; // print integer value of datum

		else											// else, is codeblock
			cout << dtsp->top().getCodeBlock() << endl; // print codeblock value
	}
}

// Clears calculator
void RPNCalc::clearCalc()		
{
	dtsp->clear();		// Call DatumStack::clear() to clear stack
}

// Pops top datum off of DatumStack
void RPNCalc::dropTop()	
{
	dtsp->pop();		// Call DatumStack::pop() 
}

// Pushes a copy of top Datum to the stack
void RPNCalc::dupTop()
{
	dtp = new Datum(dtsp->top()); // Datum pointer gets new Datum, same as top
	dtsp->push(dtp);			  // Call DatumStack::push(datum pointer)
}

// Swaps the top of stack with datum below top
void RPNCalc::swapTop()
{
	dtp = new Datum(dtsp->top());  // Datum ptr gets new Datum, same as top
	dtsp->pop();                   // Call DatumStack::pop()
	dtp2 = new Datum(dtsp->top()); // Datum ptr 2 gets new Datum, same as top
	dtsp->pop();                   // Call DatumStack::pop()
	dtsp->push(dtp);			   // Call DatumStack::push(datum pointer)
	dtsp->push(dtp2);			   // Call DatumStack::push(datum pointer 2)
}

// Exits the CalcYouLater program entirely
void RPNCalc::quitCalc()
{
	done = true;     // Set done bool to true
}

// Adds the two integer datums on top of stack
void RPNCalc::add()
{
	a = dtsp->top().getInt();	// get top datum integer value, save to a
	dtsp->pop();				// pop this datum

	b = dtsp->top().getInt();   // get top datum integer value, save to b
	dtsp->pop();				// pop this datum

	c = b + a;					// Add b and a, save sum to c
	pushNum(c);				 	// Call pushNum with c as arg
}

// Subtract top two datums
void RPNCalc::subtract()		// 
{
	a = dtsp->top().getInt();	// get top datum integer value, save to a
	dtsp->pop();				// pop this datum
	
	b = dtsp->top().getInt();   // get top datum integer value, save to b
	dtsp->pop();				// pop this datum

	c = b - a;
	pushNum(c);
}

// Multiply top two datums
void RPNCalc::multiply()
{
	a = dtsp->top().getInt();	// get top datum integer value, save to a
	dtsp->pop();				// pop this datum
	
	b = dtsp->top().getInt();   // get top datum integer value, save to b
	dtsp->pop();				// pop this datum

	c = b * a;
	pushNum(c);
}

// Divide top two datums
void RPNCalc::divide()
{
	if (dtsp->top().getInt() == 0)
	{
		cerr << "Error: Cannot_divide_by_zero" << endl;
		return;
	}

	a = dtsp->top().getInt();	// get top datum integer value, save to a
	dtsp->pop();				// pop this datum
	
	b = dtsp->top().getInt();   // get top datum integer value, save to b
	dtsp->pop();				// pop this datum
	
	c = b / a;
	pushNum(c);
}

// Return remainder of division top two datums
void RPNCalc::modulus()
{
	if (dtsp->top().getInt() == 0)
	{
		cerr << "Error: Cannot_divide_by_zero" << endl;
		return;
	}

	a = dtsp->top().getInt();	// get top datum integer value, save to a
	dtsp->pop();				// pop this datum
	
	b = dtsp->top().getInt();   // get top datum integer value, save to b
	dtsp->pop();				// pop this datum

	c = b % a;
	pushNum(c);
}

// Check if second datum less than top
void RPNCalc::isLess()
{
	a = dtsp->top().getInt();	// get top datum integer value, save to a
	dtsp->pop();				// pop this datum
	
	b = dtsp->top().getInt();   // get top datum integer value, save to b
	dtsp->pop();				// pop this datum

	if (b < a)
		pushTrue();

	else
		pushFalse();	
}

// Check if second datum greater than top
void RPNCalc::isGreat()
{
	a = dtsp->top().getInt();	// get top datum integer value, save to a
	dtsp->pop();				// pop this datum
	
	b = dtsp->top().getInt();   // get top datum integer value, save to b
	dtsp->pop();				// pop this datum

	if (b > a)
		pushTrue();

	else
		pushFalse();
}

// Check if second datum less than or equal to top
void RPNCalc::isLessEq()
{
	a = dtsp->top().getInt();	// get top datum integer value, save to a
	dtsp->pop();				// pop this datum
	
	b = dtsp->top().getInt();   // get top datum integer value, save to b
	dtsp->pop();				// pop this datum

	if (b <= a)
		pushTrue();

	else
		pushFalse();
}

// Check if second datum greater than or equal to top
void RPNCalc::isGreatEq()
{
	a = dtsp->top().getInt();	// get top datum integer value, save to a
	dtsp->pop();				// pop this datum
	
	b = dtsp->top().getInt();   // get top datum integer value, save to b
	dtsp->pop();				// pop this datum

	if (b >= a)
		pushTrue();

	else
		pushFalse();
}

// Check if top two datums are equal
void RPNCalc::isEqual()
{
	a = dtsp->top().getInt();	// get top datum integer value, save to a
	dtsp->pop();				// pop this datum
	
	b = dtsp->top().getInt();   // get top datum integer value, save to b
	dtsp->pop();				// pop this datum

	if (b == a)
		pushTrue();

	else
		pushFalse();
}

// Check if top two datums are not equal
void RPNCalc::isNotEq()
{
	a = dtsp->top().getInt();	// get top datum integer value, save to a
	dtsp->pop();				// pop this datum
	
	b = dtsp->top().getInt();   // get top datum integer value, save to b
	dtsp->pop();				// pop this datum

	if (b != a)
		pushTrue();

	else
		pushFalse();
}

// Calls parseCodeBlock on top codeblock and executes commands
void RPNCalc::exec()
{
	if (dtsp->top().isCodeBlock())			// make sure top is codeblock
	{
		s = dtsp->top().getCodeBlock();		 // get codeblock from top
		istringstream iss(s); 	

		string s2 = parseCodeBlock(iss);
		istringstream iss2(s2);				// make into istringstream

		runHelper(iss2); // call runHelper with new istringstream
	}

	else 
	{
		cerr << "Error: cannot execute non codeblock\n";
		return;
	}
}

// Removes outermost brackets from a CodeBlock
string RPNCalc::parseCodeBlock(istringstream& iss)
{
	string cb;					// input string
	string parsedcb;			// output string
	int count = 0;				// set open bracket count to 0
	int first = 0;				// set first bracket counter to 0

	do 
	{
		iss >> cb;				// read from stringstream
		if (cb == "{")			// if input is an open bracket
			++count;			// increment count

		else if (cb == "}")		// else if closing bracket
			--count;			// decrement count

		if (count != 0 and first != 0)	// if this is not the first or last bracket 
		{
			parsedcb += " ";
			parsedcb += cb;				// append input to output string
		}

		++first;						// increment to signal not first
 			
	} while (count != 0);				// loop while count not equal to 0

	return parsedcb;					// return parsed output string
}

// Reads from file input stream
void RPNCalc::file(string filename)
{
	ifstream inFile; 				// Declare input file strea
 	inFile.open(filename.c_str());  // Open file using string filename

	if (!inFile)					// if not open
	{
		cerr << "Error: Unable_to_read " << filename << "\n"; 
		return;						// Exit
	}
		
	else
	{
		runHelper(inFile);       // Call runHelper using ifstream
		inFile.close();          // Close file stream once loop done
	}		
}

// Depending on condition 3rd from top, executes 
void RPNCalc::iffunc()				
{ 
	if (dtsp->isEmpty())			                // if empty, print error and return
	{
		cerr << "Error: empty_stack\n";
		return;
	}

	if (dtsp->top().isCodeBlock())				    // if top a codeblock
	{
		cb1 = dtsp->top().getCodeBlock();	        // save top datum string
		dtsp->pop(); 								// pop 
	}
	else
		cerr << "Error: expected codeblock in if branch\n";	// print error to cerr

	if (dtsp->top().isCodeBlock())							// if top a codeblock
	{
		cb2 = dtsp->top().getCodeBlock();			        // save top datum string
		dtsp->pop();				                        // pop
	}							
	else
	{
		cerr << "Error: expected codeblock in if branch\n"; //print error to cerr
		return;												
	}
		
	if (dtsp->top().isBool())								// if top is bool
	{
		tf = dtsp->top().getBool();							// save bool 
		dtsp->pop();										// pop
	}
	else
	{
		cerr << "Error: expected boolean in if test\n";     // else cerr
		return;												// return
	}

	if (tf)													// if condition true
	{
		istringstream iss(cb2);						    // make iss from cb2
		pushCodeBlock(iss);									// Call pushCodeBlock
	}
	else
	{
		istringstream iss((cb1));							// else push other one
		pushCodeBlock(iss);									// call pushCodeBlock
	}	

	exec();													// exec top codeblock
}

// Checks input and calls appropriate function, if implemented
void RPNCalc::pickFunction(string s, istream& is)
{
	if (isdigit(s[0]))  // Check if int
	{
		int num = atoi(s.c_str());
		pushNum(num);
	}
	else if (s == "#t")
		pushTrue();
	else if (s == "#f")
		pushFalse();
	else if (s == "{")
		pushCodeBlock(is);
	else if (s == "not")
		popNot();
	else if (s == "print")
		printTop();
	else if (s == "clear")	
		clearCalc();
	else if (s == "drop")
		dropTop();
	else if (s == "dup")
		dupTop();
	else if (s == "swap")
		swapTop();
	else if (s == "quit")
		quitCalc();
	else if (s == "+")
		add();
	else if (s == "-")
		subtract();
	else if (s == "*")
		multiply();
	else if (s == "/")
		divide();	
	else if (s == "mod")
		modulus();
	else if (s == "<")
		isLess();
	else if (s == ">")
		isGreat();
	else if (s == "<=")
		isLessEq();
	else if (s == ">=")
		isGreatEq();
	else if (s == "==")
		isEqual();	
	else if (s == "!=")
		isNotEq();
	else if (s == "file")
	{
		is >> s; 
		file(s);
	}
	else if (s == "if")
		iffunc();
	else if (s == "exec")
		exec();
	else 
	{
		cerr << s << ": unimplemented\n";
		return;
	}
}

// The real run. Only way to call pickFunction is through here. 
void RPNCalc::runHelper(istream& is)
{

	do {
		done = is.eof();      // Bool set to eof()
		is >> s;			  // input from strema to string
		pickFunction(s, is);  // call pick function using string and stream

	} while (!done);		  // while done is not true

	return;					  
}
