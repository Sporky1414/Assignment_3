#include "SyntaxChecker.h"

using namespace std;

int main (int argc, char** argv) {
  FileIO *inputFile;
  SyntaxChecker *syntaxChecker = new SyntaxChecker();
  if(argc < 2) {
    cout << "You did not input a file path as a command line argument. Now taking in file path." << endl;
    inputFile = new FileIO();
  } else {
    inputFile = new FileIO(argv[1]);
  }
  while(true) {
    if(!syntaxChecker->run(inputFile)) {
      delete inputFile;
      delete syntaxChecker;
      return 0;
    } else {
      cout << "File check complete. No errors found. Would you like to input a new file? Type as your first letter 'y' for yes or 'n' for no. Capitals also count." << endl;
      string response = "";
      delete inputFile;
      while(true) {
        cin >> response;
        if(response[0] == 'y' || response[0] == 'Y') {
          inputFile = new inputFile();
          break;
        } else if (response[0] == 'n' || response[0] == 'N'){
          cout << "Good bye." << endl;
          delete syntaxChecker;
          return 0;
        } else {
          cout << "INVALID RESPONSE. Please try again." << endl;
        }
      }
    }
  }
}
