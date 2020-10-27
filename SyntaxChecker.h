#include "Stack.cpp"
#include "FileIO.h"

using namespace std;

class SyntaxChecker() {
  public:
    SyntaxChecker();
    ~SyntaxChecker();

    bool run(FileIO inputFile);

  private:
    GenStack<char> *delimiters;

    bool checkLineForDelimiterAndRespond(string toCheck, int lineNumber);
};
