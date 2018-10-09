/*
 *
 *  COMP 15 Project 1 - CalcYouLater
 *
 *  DatumStack.cpp
 *  DatumStack class implmentation
 *  Modified By (UTLN): rserot01
 *           On       : 10/14/2017
 *
 */

#include "DatumStack.h"
#include <iostream>

using namespace std;



// Default Constructor
DatumStack::DatumStack()
{
	basep = topp = NULL;
}

// Parameterized Constructor
DatumStack::DatumStack(Datum dtArray[], int arraySize)
{
	thisNode = new Node;				   // Node pointer
	basep = thisNode;						   // base pointer gets node pointer
	thisNode->prev = NULL;				   // base previous gets NULL

	for (int i = 0; i < arraySize; ++i)		   // iterate through array
	{
		thisNode->dtp = new Datum(dtArray[i]);		   // dtp ptr member gets address of element
		thisNode->next = new Node;		   // create new node
		thisNode->next->prev = thisNode;   // set new node -> prev to current node
		thisNode = thisNode->next;		   // node pointer gets next

	}

	thisNode = thisNode -> prev;	// change to prev node in order to delete last
	delete thisNode -> next;  		// delete unneeded last node created due to loop
	topp = thisNode;				// top pointer gets current node
	thisNode -> next = NULL;		// topp -> next gets NULL
}

DatumStack::~DatumStack()
{
	thisNode = basep;		// Node pointer gets base pointer
 					
	while (thisNode != topp) 	// While not pointing to top
	{
		thisNode = thisNode->next;	// get next
		delete thisNode->prev->dtp;
		delete thisNode->prev;		// delete prev
	}

	delete thisNode; 					// delete last node;
}

bool DatumStack::isEmpty()
{
	if (basep == NULL and topp == NULL) // if empty "flags" set 
		return true;					// return true

	else 
		return false;
}

int DatumStack::size()
{
	thisNode = basep;				// node pointer
	 
	int i = 0;							// counter variable

	while (thisNode != NULL)
	{
		++i;							// increment counter
		thisNode = thisNode->next;		// get next node
	}

	return i;							// return counter
}

void DatumStack::clear()
{
	while (!isEmpty())
	{
		pop();
	}		
		basep = topp = NULL;	// set empty list
}

Datum DatumStack::top()
{
	if (isEmpty())
		throw runtime_error("empty_stack");

	else
		return *(topp -> dtp);			// return dereferenced dtp ptr member
}

void DatumStack::push(Datum* d)
{
	if (isEmpty())
	{
		basep = new Node;				// Allocate new node
		basep->dtp = new Datum(*d);		// Allocate new datum
		basep->prev = NULL;				// previous gets null ptr
		basep->next = NULL;				// next gets null ptr
		topp = basep;					// topp and basep both point to new node
	}

	else
	{
		thisNode = new Node;	// allocate new node
		thisNode->prev = topp;  // new nodes prev points to topp
		thisNode->dtp = d; // dtp pointer gets address of datum input	
		topp->next = thisNode;  // topp next gets new node
		topp = thisNode;		// topp gets new top				
		thisNode->next = NULL;		// topp next set to null ptr
	}	
}

void DatumStack::pop()
{
	if (isEmpty())
		throw runtime_error("empty_stack");

	else if (size() == 1)
	{
		delete topp->dtp;			// delete allocated datum
		delete topp;				// delete node
		basep = topp = NULL;		// topp and basep both get null ptr
	}

	else
	{	
		delete topp->dtp;
		topp = topp->prev;			// rearrange top ptr 
		delete topp->next;			// delete former top of stack
		topp -> next = NULL;			// set new top -> next to NULL
	}
}	
