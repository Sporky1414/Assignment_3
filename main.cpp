#include "SyntaxChecker.h"

using namespace std;
//Main method to run the syntax checker. File name can be taken in as a command line argument or in the program itself.
int main (int argc, char** argv) {
  //Creates file handler and syntax checker objects.
  FileIO *inputFile;
  SyntaxChecker *syntaxChecker = new SyntaxChecker();
  //Checks for arguments
  if(argc < 2) {
    //If no argument was entered, use the FileIO default constructor to do it in the program.
    cout << "You did not enter a command line argument. Now taking in file path." << endl;
    inputFile = new FileIO();
  } else {
    //If an argument was entered, use the FileIO constructor with a string passed through as an argument
    //to create the file handler object and get the input file. The constructor will ensure the file is valid.
    inputFile = new FileIO(argv[1]);
  }
  //Loops through program continuously until the syntax checker finds an error or the user wishes to exit the program.
  while(true) {
    //Runs the syntax checker on the file.
    if(!syntaxChecker->run(inputFile)) {
      //An error was found in the file, so close the program (user is alerted of issue in run method)
      delete inputFile;
      delete syntaxChecker;
      return 0;
    } else {
      //The file is clear, so the user is told as such.
      cout << "File check complete. No errors found. Would you like to input a new file? Type as your first letter 'y' for yes or 'n' for no. Capitals also count." << endl;
      //Sets up a string to take in a user response.
      string response = "";
      //Deletes the original inputFile to reset it for a potential new file.
      delete inputFile;
      //Loops through response until a valid user response is entered.
      while(true) {
        //Takes in user response
        cin >> response;
        if(response[0] == 'y' || response[0] == 'Y') {
          //If the first letter of the user response is a y, the inputFile is recreated with a default constructor and this nested while loop breaks
          //allowing for the syntax checker to be run again.
          inputFile = new FileIO();
          break;
        } else if (response[0] == 'n' || response[0] == 'N'){
          //If the first letter of the user response is an n, the program exits.
          cout << "Good bye." << endl;
          delete syntaxChecker;
          return 0;
        } else {
          //If an invalid response was entered, the user is told to try again.
          cout << "INVALID RESPONSE. Please try again.\nWould you like to input a new file? Type as your first letter 'y' for yes or 'n' for no. Capitals also count." << endl;
        }
      }
    }
  }
}
