#include "SyntaxChecker.h"

SyntaxChecker::SyntaxChecker() {
  delimiters = new GenStack<char>();
}

SyntaxChecker::~SyntaxChecker() {
  delete delimiters;
}

bool SyntaxChecker::run(FileIO inputFile) {
  string temp = "";
  while(inputFile->inputHasDataLeft()) {
    temp = inputFile->readNextLine();
    if(!checkLineForDelimiterAndRespond(temp, inputFile->getLineNumber()) {
      return false;
    }
  }
  if(delimiters->isEmpty()) {
    return true;
  } else {
    cout << "Reached end of file, missing ''";
    while(!delimiters->isEmpty()) {
      cout << delimiters->pop() << "'";
      if(!delimiters->isEmpty()) {
        cout << ", ";
      } else {
        cout << "." << endl;
      }
    }
  }
}

bool SyntaxChecker::checkLineForDelimiterAndRespond(string toCheck, int lineNumber) {
  for(int i = 0; i < toCheck.length; ++i) {
    switch(toCheck[i]) {
      case '(':
      case '[':
      case '{':
        delimiters->push(toCheck[i]);
        break;


      case ')':
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
        break;


      case ']':
        if(delimiters->peek() != '[') {
          cout << "Line " << lineNumber << " contains unexpected ']'.";
          if(delimiters->peek() == '(') {
            cout << "Expected ')'." << endl;
            return false;
          } else {
            cout << "Expected '}'." <<endl;
            return false;
          }
        }
        delimiters->pop();
        break;

      case '}':
        if(delimiters->peek() != '[') {
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
        break;
    }
  }
}
