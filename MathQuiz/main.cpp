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

// void validateUserResponse(int);
void credits(char &, string &, bool &);
void clearScreen();
void retrieveStats(string &);
void menu (string, bool &);

int main() {
  char userResponse;
  string userName;
  bool quizEnd = false;
  credits(userResponse, userName, quizEnd);
  while(!quizEnd) {
    menu(userName, quizEnd);
  }
  return 0;
}

void credits(char &userResponse, string &userName, bool &quizEnd) {
  // Creating the menu box
  cout << string(24, '*') << endl;
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
  cout << string(24, '*') << endl;
  cout << endl;
  cout << "y/Y to continue, any other char to exit \n";
  cin >> userResponse;
  if (toupper(userResponse) == 'Y') { // Convert user response to upper case.
    clearScreen();
    retrieveStats(userName);
  } else {
    quizEnd = true;
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
  ofstream newUserFile;

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

  userFileName = userName + ".txt";
  ifstream userFile(userFileName);

  if (!userFile) {
    newUserFile.open(userFileName);
    newUserFile << userName << endl << 0 << endl << 0 << endl << 0 << endl;
    newUserFile.close();
  }
}

void menu (string userName, bool &quizEnd) {
  char userInput;
  bool closeMenu = false;

  do {
    cout << string(4, '*') << " CHOOSE A PROBLEM " << string(3, '*') << endl;
    cout << string(25, '*') << endl;
    cout << string(25, '*') << endl;
    cout << string(6, '*') << string(13, ' ') << string(6, '*') << endl;
    cout << string(6, '*') << " 1. ADD      " << string(6, '*') << endl;
    cout << string(6, '*') << " 2. SUBTRACT " << string(6, '*') << endl;
    cout << string(6, '*') << " 3. MULTIPLY " << string(6, '*') << endl;
    cout << string(6, '*') << " 4. DIVIDE   " << string(6, '*') << endl;
    cout << string(6, '*') << " 5. STATS    " << string(6, '*') << endl;
    cout << string(6, '*') << " n/N to QUIT " << string(6, '*') << endl;
    cout << string(6, '*') << string(13, ' ') << string(6, '*') << endl;
    cout << string(25, '*') << endl;
    cout << string(25, '*') << endl;
    cin >> userInput;

    switch (toupper(userInput)) { // Use switch to check the input for know cases
      case '1':
        cout << userInput << endl; // Generate the problems here instead.
        cin.clear();
        clearScreen();
        break;
      case '2':
        cout << userInput << endl; // Generate the problems here instead.
        cin.clear();
        clearScreen();
        break;
      case '3':
        cout << userInput << endl; // Generate the problems here instead.
        cin.clear();
        clearScreen();
        break;
      case '4':
        cout << userInput << endl; // Generate the problems here instead.
        cin.clear();
        clearScreen();
        break;
      case '5':
        cout << userInput << endl; // Generate the problems here instead.
        cin.clear();
        clearScreen();
        break;
      case 'N':
        closeMenu = true;
        clearScreen();
        break;
      default:
        cout << "This is not a valid menu option \n";
        cin.clear();
        break;
    }
  } while(!closeMenu);
  quizEnd = true;
}
