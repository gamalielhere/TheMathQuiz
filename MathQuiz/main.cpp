//
//  main.cpp
//  MathQuiz
//
//  Created by Gamaliel Padillo on 4/17/17.
//  Copyright © 2017 Gamaliel Padillo. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

void validateUserResponse(bool);
void credits(char &, string &);
void clearScreen();
void retrieveStats(string &);
void menu (string);

int main() {
  char userResponse;
  string userName;
  credits(userResponse, userName);
  menu(userName);
  return 0;
}

void credits(char &userResponse, string &userName) {
  // Creating the menu box
  cout << string(24, '*') << endl;
  cout << string(24, '*') << endl;
  cout << string(6, '*') << string(12, ' ') << string(6, '*') << endl;
  cout << string(6, '*') << string(4, ' ') << " The" << string(4, ' ') << string(6, '*') << endl;
  cout << string(6, '*') << "  MathGame  " << string(6, '*') << endl;
  cout << string(6, '*') << string(4, ' ') << " By " << string(4, ' ') << string(6, '*') << endl;
  cout << string(6, '*') << "  Gamaliel  " << string(6, '*') << endl;
  cout << string(6, '*') << string(12, ' ') << string(6, '*') << endl;
  cout << string(24, '*') << endl;
  cout << string(24, '*') << endl;
  cout << endl;
  cout << "y/Y to continue, any other char to exit \n";
  cin >> userResponse;
  if (toupper(userResponse) == 'Y') { // Convert user response to upper case.
    clearScreen();
    retrieveStats(userName);
  }
}

void clearScreen () {
  for (int i = 0; i < 10; i++) {
    cout << "\n\n\n\n\n\n\n\n\n\n";
  }
}

void retrieveStats(string &userName) {
  bool validName = false;
  int stringErrorCounter = 0;
  string userFileName;

  cin.ignore();
  cout << "Enter your name and press <ENTER> \n";
  while(!validName) {
    getline(cin, userName);
    for (int i = 0; i < userName.length(); i++) { // Loop through name
      if(!isalpha(userName[i]) || isblank(userName[i])) {
        stringErrorCounter++; // update the counter
        cout << stringErrorCounter << endl;
      }
    }

    if (stringErrorCounter > 0 || cin.fail()) { // if the counter has value other than zero or cin input stream breaks.
      cout << "Invalid entry. Try again! \n";
      cin.clear(); // Clear the input
      stringErrorCounter = 0; // Reset the counter
    } else {
      validName = true;
    }
  }
}

void menu (string userName) {
  string textLine, userFileName;
  userFileName = userName + ".txt";
  ifstream userFile(userFileName);
  ofstream newUserFile;

  if (!userFile) {
    newUserFile.open(userFileName);
    newUserFile << userName;
    newUserFile.close();
  } else {
    while (getline(userFile, textLine)) { // loop through file by string
      cout << textLine << endl;
    }
  }
}
