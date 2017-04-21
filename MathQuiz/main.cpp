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
#include <ctime>
#include <cstdlib>
using namespace std;

// void validateUserResponse(int);
void credits(char &, string &, bool &, double &, int &, int &);
void clearScreen();
void retrieveStats(string &, double &, int &, int &);
void menu (string, double &, int &, int &, bool &);
bool validateUserResponse(char, string, double &, int &, int &);
bool generateAddition(string, double &, int &, int &);
bool generateSubtraction(string, double &, int &, int &);
bool validateUserAnswer(string, int, int, double &, int &, int &);
void updateStats(double, int, int, double &, int &, int &);
void saveStats (string, double, int, int);

int main() {
  srand(time(NULL));
  char userResponse;
  string userName;
  double totalCredit = 0.0;
  int totalCorrect = 0, totalIncorrect = 0;
  bool quizEnd = false;

  credits(userResponse, userName, quizEnd, totalCredit, totalCorrect, totalIncorrect);
  while(!quizEnd) {
    menu(userName, totalCredit, totalCorrect, totalIncorrect, quizEnd);
  }
  return 0;
}

void credits(char &userResponse, string &userName, bool &quizEnd, double &totalCredit, int &totalCorrect, int &totalIncorrect) {
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
    retrieveStats(userName, totalCredit, totalCorrect, totalIncorrect);
  } else {
    quizEnd = true;
  }
}

void clearScreen () {
  for (int i = 0; i < 10; i++) {
    cout << "\n\n\n\n\n\n\n\n\n\n";
  }
}

void retrieveStats(string &userName, double &totalCredit, int &totalCorrect, int &totalIncorrect) {
  bool validName = false;
  int stringErrorCounter = 0, fileWordCounter = 0;
  string userFileName, readFile;
  ofstream newUserFile;

  cin.ignore();
  cout << "Enter your name and press <ENTER> \n";
  while(!validName) {
    getline(cin, userName);
    for (int i = 0; i < userName.length(); i++) { // Loop through name
      if(!isalpha(userName[i]) || isblank(userName[i])) {
        stringErrorCounter++; // update the counter
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

  // userFile.ignore(numeric_limits<streamsize>::max(), '\n');
  // userFile.open(userFileName);
  int i = 1;
  if (userFile.is_open()) {
    // Loop through file
    // Assign lines to correct variables
    while (getline(userFile, readFile)) {
      if (i == 1) {
        userName = readFile;
      } else if (i == 2) {
        totalCredit = stod(readFile);
      } else if (i == 3) {
        totalCorrect = stoi(readFile);
      } else if (i == 4) {
        totalIncorrect = stoi(readFile);
      }
      i++;
    }
    userFile.ignore(numeric_limits<streamsize>::max(), '\n');
    userFile.close();
  } else {
    newUserFile.open(userFileName);
    newUserFile << userName << endl << totalCredit << endl << totalCorrect << endl << totalIncorrect << endl;
    newUserFile.close();
  }
}

void menu (string userName, double &totalCredit, int &totalCorrect, int &totalIncorrect, bool &quizEnd) {
  char userInput;
  bool closeMenu = false;
  do {
    // cout << userName << endl << totalCredit << endl << totalCorrect << endl << totalIncorrect << endl;
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

    closeMenu = validateUserResponse(userInput, userName, totalCredit, totalCorrect, totalIncorrect);
  } while(!closeMenu);
  quizEnd = true;
}

bool validateUserResponse(char response, string userName, double &totalCredit, int &totalCorrect, int &totalIncorrect) {
  if (response == '1') {
    cin.clear();
    clearScreen();
    return generateAddition(userName, totalCredit, totalCorrect, totalIncorrect);
  } else if (response == '2') {
    cin.clear();
    clearScreen();
    return generateSubtraction(userName, totalCredit, totalCorrect, totalIncorrect);
  } else if (response == '3') {
    cout << response << endl; // Generate the problems here instead.
    cin.clear();
    clearScreen();
  } else if (response == '4') {
    cout << response << endl; // Generate the problems here instead.
    cin.clear();
    clearScreen();
  } else if (response == '5') {
    cout << response << endl; // Generate the problems here instead.
    cin.clear();
    clearScreen();
  } else if (toupper(response) == 'N') {
    clearScreen();
    saveStats (userName, totalCredit, totalCorrect, totalIncorrect);
    return true;
  } else {
    cout << "This is not a valid menu option \n";
    cin.clear();
  }

  return false;
}

bool generateAddition(string userName, double &totalCredit, int &totalCorrect, int &totalIncorrect) {
  int num1, num2;
  string fileName;
  bool userAnswerInt = false;
  fileName = userName + ".txt";

  num1 = rand() % 9 + 1;
  num2 = rand() % 9 + 1;

  cout << string(6, '*') << "  ADDITION   " << string(6, '*') << endl;
  cout << string(25, '*') << endl;
  cout << string(25, '*') << endl;
  cout << string(6, '*') << string(13, ' ') << string(6, '*') << endl;
  cout << string(6, '*') << string(13, ' ') << string(6, '*') << endl;
  cout << string(6, '*') << "   " << num1 << " + " << num2 << " = ? " << string(6, '*') << endl;
  cout << string(6, '*') << string(13, ' ') << string(6, '*') << endl;
  cout << string(6, '*') << string(13, ' ') << string(6, '*') << endl;
  cout << string(25, '*') << endl;
  cout << string(25, '*') << endl;

  while (!userAnswerInt) {
    userAnswerInt = validateUserAnswer("Addition", num1, num2, totalCredit, totalCorrect, totalIncorrect);
  }

  return false;
}

bool generateSubtraction(string userName, double &totalCredit, int &totalCorrect, int &totalIncorrect) {
  int num1, num2, minuend, subtrahend;
  string fileName;
  bool userAnswerInt = false;
  fileName = userName + ".txt";

  minuend = rand() % 9 + 1;
  subtrahend = rand() % 9 + 1;
  if (minuend > subtrahend || minuend == subtrahend) {
    num1 = minuend;
    num2 = subtrahend;
  } else {
    num2 = minuend;
    num1 = subtrahend;
  }

  cout << string(6, '*') << " SUBTRACTION " << string(6, '*') << endl;
  cout << string(25, '*') << endl;
  cout << string(25, '*') << endl;
  cout << string(6, '*') << string(13, ' ') << string(6, '*') << endl;
  cout << string(6, '*') << string(13, ' ') << string(6, '*') << endl;
  cout << string(6, '*') << "   " << num1 << " - " << num2 << " = ? " << string(6, '*') << endl;
  cout << string(6, '*') << string(13, ' ') << string(6, '*') << endl;
  cout << string(6, '*') << string(13, ' ') << string(6, '*') << endl;
  cout << string(25, '*') << endl;
  cout << string(25, '*') << endl;

  while (!userAnswerInt) {
    userAnswerInt = validateUserAnswer("Subtraction", num1, num2, totalCredit, totalCorrect, totalIncorrect);
  }

  return false;
}

bool validateUserAnswer(string operation, int num1, int num2, double &totalCredit, int &totalCorrect, int &totalIncorrect) {
  string userInput;
  int stringErrorCounter = 0;
  bool userInputValid = false;

  cin.ignore();
  do {
    cin.clear(); // Clear the input
    getline(cin, userInput);
    for (int i = 0; i < userInput.length(); i++) { // Loop through name
      // int digit = userInput[i];
      if(!isdigit(userInput[i])) {
        stringErrorCounter++; // update the counter
      }
    }

    if (stringErrorCounter > 0) { // if the counter has value other than zero or cin input stream breaks.
      cout << "Invalid entry. Try again! \n";
      stringErrorCounter = 0; // Reset the counter
    } else {
      userInputValid = true;
    }
  } while (!userInputValid);

  if(operation == "Addition") {
    if ((num1 + num2) == stoi(userInput)) {
      clearScreen();
      updateStats(0.05, 1, 0, totalCredit, totalCorrect, totalIncorrect);
      cout << string(6, '*') << "    RIGHT    " << string(6, '*') << endl;
    } else {
      clearScreen();
      updateStats(0.03, 0, 1, totalCredit, totalCorrect, totalIncorrect);
      cout << string(6, '*') << "    WRONG    " << string(6, '*') << endl;
    }
  } else if (operation == "Subtraction") {
    if ((num1 - num2) == stoi(userInput)) {
      clearScreen();
      updateStats(0.05, 1, 0, totalCredit, totalCorrect, totalIncorrect);
      cout << string(6, '*') << "    RIGHT    " << string(6, '*') << endl;
    } else {
      clearScreen();
      updateStats(0.03, 0, 1, totalCredit, totalCorrect, totalIncorrect);
      cout << string(6, '*') << "    WRONG    " << string(6, '*') << endl;
    }
  }

  return true;
}

void updateStats(double addCredit, int addCorrect, int addIncorrect, double &totalCredit, int &totalCorrect, int &totalIncorrect) {
  if (addCredit == 0.05 && addCorrect && !addIncorrect) {
    totalCredit += addCredit;
    totalCorrect += addCorrect;
  } else if (totalCredit > 0 && addCredit == 0.03 && !addCorrect && addIncorrect) {
    totalCredit -= addCredit;
    totalIncorrect += addIncorrect;
  } else if (totalCredit == 0 && addCredit == 0.03 && !addCorrect && addIncorrect) {
    totalIncorrect += addIncorrect;
  }
}

void saveStats (string userName, double totalCredit, int totalCorrect, int totalIncorrect) {
  string fileName = userName + ".txt";
  ofstream userFile;
  userFile.open(fileName);
  userFile << userName << endl << totalCredit << endl << totalCorrect << endl << totalIncorrect << endl;
  userFile.close();
}
