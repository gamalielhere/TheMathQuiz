//
//  main.cpp
//  MathQuiz
//
//  Created by Gamaliel Padillo on 4/17/17.
//  Copyright © 2017 Gamaliel Padillo. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

void validateUserResponse(bool);
void credits(char &, string &);
void clearScreen();

int main() {
  char userResponse;
  string userName;
  credits(userResponse, userName);
  return 0;
}

void credits(char &userResponse, string &userName) {
  // Creating the menu box
  string userChoice;
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
    cout << "Enter your name and press <ENTER> \n";
  }
}

void clearScreen () {
  for (int i = 0; i < 10; i++) {
    cout << "\n\n\n\n\n\n\n\n\n\n";
  }
}
