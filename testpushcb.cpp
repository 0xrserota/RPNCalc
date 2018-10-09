#include <iostream>
#include <sstream>
#include <string>

void pushCodeBlock(std::istream&);

int main()
{
	pushCodeBlock(std::cin);
	return 0;
}


void pushCodeBlock(std::istream& is)
{

	std::string cblock;					// Declare string to take input 
	std::string output = "{";			// Declare output string, initialize to {
	int count = 1;												

	do 								
	{	
		is >> cblock;				// Get input from iss (istringstream)
		std::cout << cblock << std::endl;
		if (cblock == "{")          // if cblock is "{"
			++count;				// Increment counter

		else if (cblock == "}")		// If cblock is "}"
			--count;				// decrement counter

		if (count != 0)
		{
			output += " ";
			output += cblock;			// Append input string to output string
		}
 		
 		else if (count == 0)
 		{
 			output += " ";
 			output += cblock;
 		}

	} while (count != 0);			// While count non-zero (brackets not matched)

	std::cout << "Output: " << output << std::endl;
}