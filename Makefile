#
#
#  COMP 15 Project 1 - CalcYouLater
#
#  Makefile
# Makefile for CalcYouLater
#  Modified By (UTLN): rserot01
#          On       : 10/14/2017
#
#


CXX 	 = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11
LDFLAGS  = -g3


CalcYouLater: 	main.o RPNCalc.o DatumStack.o Datum.o 
	${CXX} ${CXXFLAGS} ${LDFLAGS} -o CalcYouLater main.o RPNCalc.o \
									DatumStack.o Datum.o


main.o:		  main.cpp RPNCalc.h
RPNCalc.o:    RPNCalc.h 
DatumStack.o: DatumStack.h

