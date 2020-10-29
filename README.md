# Assignment_3

## Identifying Information: 
1. AJ Keenan
1. Student ID: 2316808
1. akeenan@chapman.edu
1. CPSC 350-02
1. Assignment: Assignment 3

## Application Purpose
The purpose of this application is to check a piece of code for any mistakes regarding the delimiters (), [], and {}. It will take in a file from the user (either as a command line argument or in the program itself) and check for any delimiter errors. If an error exists, the syntax checker will report the error to the user and quit. If the file is clean, the program will either run the check again on a different file or exit the program, depending on what the user wishes to do.

## Source Files 
1. Stack.cpp
1. FileIO.h
1. FileIO.cpp
1. SyntaxChecker.h
1. SyntaxChecker.cpp
1. main.cpp

## Known Errors: 
An exception will be thrown if the stack ever gets empty and data tries to be read for it, causing the program to abort. The user will be alerted that the stack  is empty.

## References
1. Class Notes (Stack Implementation, Syntax Checker logic)
1. CPlusPlus.com (Templates, exit)
1. Stack Overflow (Throw exception and return result from a function, Reading a full line of input)


## Compilation Instructions
Use the "make all" command, courtesy of the included MAKEFILE, to compile all source files. To run the program, run the assignment3.exe program from any linux terminal, such as in docker. If you wish to pass through the file as a command line argument, please do so (after typing in the run command, type in the file path being used before hitting enter). However, it is not required to pass through the file path as an argument, since the program will ask for the path if one is not given.


