/*
 *
 *  COMP 15 Project 1 - CalcYouLater
 *
 *  DatumStack.h
 *  DatumStack class definition
 *  Modified By (UTLN): rserot01
 *           On       : 10/14/2017
 *
 */

#include "Datum.h"

#ifndef DATUMSTACK_H_
#define DATUMSTACK_H_


class DatumStack {

	public:

		DatumStack();
		DatumStack(Datum [], int);

		~DatumStack();

		bool isEmpty();
		void clear();
		int  size();
		Datum top();
		void pop();
		void push(Datum*);

	private:

		struct Node
		{
			Datum *dtp;
			Node *next;
			Node *prev;
		};

		Node *basep;	// base pointer
		Node *topp; 	// top pointer	
		Node *thisNode;

		void swap();

};


#endif