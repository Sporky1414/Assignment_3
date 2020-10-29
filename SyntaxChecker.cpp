#include "SyntaxChecker.h"

SyntaxChecker::SyntaxChecker() {
  delimiters = new GenStack<char>();
}

SyntaxChecker::~SyntaxChecker() {
  delete delimiters;
}

bool SyntaxChecker::run(FileIO* inputFile) {
  string temp = "";
  while(inputFile->inputHasDataLeft()) {
    temp = inputFile->readNextLine();
    if(!checkLineForDelimiterAndRespond(temp, inputFile->getLineNumber()-1)) {
      return false;
    }
  }
  if(delimiters->isEmpty()) {
    return true;
  } else {
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
  }
}

bool SyntaxChecker::checkLineForDelimiterAndRespond(string toCheck, int lineNumber) {
  for(int i = 0; i < toCheck.length(); ++i) {
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
  return true;
}
