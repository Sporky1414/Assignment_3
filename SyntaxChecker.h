/*
  Name: AJ Keenan
  Student ID: 2316808
  Class Name: CPSC 350: Data Structures and Algorithms
  Class Section: 2
  Assignment Name: Assignment 3
*/

#include "Stack.cpp"
#include "FileIO.h"

using namespace std;

//Class to check the syntax of a file and return if it is has any delimiter mistakes or not.
class SyntaxChecker {
  public:
    //Constructor/Destructor
    SyntaxChecker();
    ~SyntaxChecker();

    //Runs the syntax check on a file
    bool run(FileIO* inputFile);

  private:
    //The stack containing the starting delimiters of the code being checked.
    GenStack<char> *delimiters;

    //Searches each line for delimiters and acts accordingly.
    bool checkLineForDelimiterAndRespond(string toCheck, int lineNumber);
};
