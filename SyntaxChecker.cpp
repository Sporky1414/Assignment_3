/*
  Name: AJ Keenan
  Student ID: 2316808
  Class Name: CPSC 350: Data Structures and Algorithms
  Class Section: 2
  Assignment Name: Assignment 3
*/

#include "SyntaxChecker.h"

//Constructor: Instantiates the delimiters stack.
SyntaxChecker::SyntaxChecker() {
  delimiters = new GenStack<char>();
}


//Destructor: Deletes the delimiters stack
SyntaxChecker::~SyntaxChecker() {
  delete delimiters;
}

//Checks the input file for any delimiter-based syntax errors. If any errors are found,
//they are printed to the user and false is returned. Otherwise, true is returned.
bool SyntaxChecker::run(FileIO* inputFile) {
  //Creates a temporary string variable to hold each line as it is being checked.
  string temp = "";
  //Loops through each line in the file.
  while(inputFile->inputHasDataLeft()) {
    //Sets the temp variable to the line currently being read by the file manager object.
    temp = inputFile->readNextLine();
    //Runs the checkLineForDelimiterAndRespond method. If false is returned,
    //this method will also return false (outputting to user already done in other method).
    //Line number used is -1 because if the file's actual line number is returned, it will be
    //for the next line as opposed to the line being checked.
    if(!checkLineForDelimiterAndRespond(temp, inputFile->getLineNumber()-1)) {
      return false;
    }
  }
  //If the stack is empty at the end of the loop, all delimiters have been accounted for and
  //true is returned.
  if(delimiters->isEmpty()) {
    return true;
  } else {
    //Opening delimiters are still present in the stack.
    //The corresponding closing delimiters are printed for the user to see.
    //Stack is emptied in the process.
    cout << "Reached end of file, missing '";
    while(!delimiters->isEmpty()) {
      if(delimiters->peek() == '(') {
        cout << ")";
      } else if (delimiters->peek() == '[') {
        cout << "]";
      } else {
        cout << "}";
      }
      delimiters->pop();
      if(!delimiters->isEmpty()) {
        cout << "', ";
      } else {
        cout << "'." << endl;
      }
    }
    //Since extra delimiters were found, the file has errors, so false is returned.
    return false;
  }
}

//Searches each line for delimiters and acts accordingly.
bool SyntaxChecker::checkLineForDelimiterAndRespond(string toCheck, int lineNumber) {
  //Runs a loop to check each character of the string.
  for(int i = 0; i < toCheck.length(); ++i) {
    /*
      If the character being checked is an opening delimiter, it is added to the stack.
      Otherwise, if the character being checked is a closing delimiter, the top delimiter
      in the stack should be the matching opening delimiter if the syntax is correct.
      If a match is present, the opening delimiter is popped from the stack and the loop continues.
      Otherwise, the user is alerted of the mismatch, is told what the actual matching
      delimiter is, where the mismatched delimiter is, and returns false.
      If any other character is present, the loop moves to the next iteration without
      doing anything.
    */
    if(toCheck[i] == '(' || toCheck[i] == '[' || toCheck[i] == '{') {
      delimiters->push(toCheck[i]);
    } else if(toCheck[i] == ')') {
      if(delimiters->peek() != '(') {
        cout << "Line " << lineNumber << " contains unexpected ')'.";
        if(delimiters->peek() == '[') {
          cout << "Expected ']'." << endl;
          return false;
        } else {
          cout << "Expected '}'." <<endl;
          return false;
        }
      }
      delimiters->pop();
    } else if(toCheck[i] == ']') {
      if(delimiters->peek() != '[') {
        cout << "Line " << lineNumber << " contains unexpected ']'.";
        if(delimiters->peek() == '[') {
          cout << "Expected ')'." << endl;
          return false;
        } else {
          cout << "Expected '}'." <<endl;
          return false;
        }
      }
      delimiters->pop();
    } else if(toCheck[i] == '}') {
      if(delimiters->peek() != '{') {
        cout << "Line " << lineNumber << " contains unexpected '}'.";
        if(delimiters->peek() == '(') {
          cout << "Expected ')'." << endl;
          return false;
        } else {
          cout << "Expected ']'." <<endl;
          return false;
        }
      }
      delimiters->pop();
    }
  }
  //Line has been fully checked and no mismatched delimiters were found, so true is returned.
  return true;
}
