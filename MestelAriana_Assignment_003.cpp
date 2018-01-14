// MestelAriana_Assignment_003.cpp
/******
  Problem: Write a program to score races:

  Ideas: Set up and initialize an array for the scores, and an array for the amount of runners per team.
  Create an outer loop to that will keep looping if the amount of runners per team is unequal.
  Inside, make another loop that will keep asking for a string until the user inputs done.
  Make another loop that records all the information based on the outcome provvided by the user.
  And the last loop should test whether or not the user entered an invalid outcome with an uneven
  amount of runners.  If the user entered a valid outcome then the loop should break.
  At the end print out oll the results and the winner.
******/

#include <iostream>
using namespace std;

int main () {
  string user_input, outcome;
  bool equal_runners = false;
  int tester, teams = 0;
  int scores['Z' + 1] = {};
  int num_of_runners['Z' + 1] = {};
  cout << "In a race where each team has the same amount of runners, the outcome is represented by a string that you input until you write done. \n";

  while (equal_runners == false) {
    cout << "Enter the outcome: ";
      cin >> outcome;
      if (outcome == "done") return 0;
        // reset everything to zero in case user inputs an outcome with uneven runners
        teams = 0;
        for (int i = 'A'; i < 'Z' + 1; i++) {
          scores[i] = 0;
          num_of_runners[i] = 0;
        }
        // loop to record all the information based on the outcome string
        for (int i = 0; i < outcome.length(); i++) {
          char c = outcome[i];
          scores[c] = scores[c] + (i + 1);  // add the ranking score
          if (num_of_runners[c] == 0) teams++;   // if its  a new letter that has not occured yet add to the number of teams
          num_of_runners[c] += 1;
        }
        // loop to test if there is an equal amount of runners
        tester = num_of_runners[outcome[0]];
        for (int i = 0; i < outcome.length(); i++) {
          char c = outcome[i];
          if (num_of_runners[c] != tester) {
            equal_runners = false;
            cout << "Error, there is not the same amount of runners per team. \n";
            break;
          }
          else equal_runners = true;
        }
        if (equal_runners == true) {
          // Print all the results
              char winner;
              int min = scores[outcome[0]];
              for (int i = 'A'; i < 'Z' + 1; i++) {
                if ((scores[i] != 0) && (scores[i] <= min)) {
                  min = scores[i];
                  winner = i;
              }
            }
            cout << "There are " << teams << " teams." << endl;
            cout << "Each team has " << tester << " runners.\n" << endl;
            cout << "Team:  Score:" << endl;
            for (int i = 'A'; i < 'Z' + 1; i++) {
              if (scores[i] > 0) {
                cout << ((char) i) << "      " << ((double) scores[i]) / tester << endl;
              }
            }
            cout << "The winner is team " << winner << " with a score of " << ((double) min) / tester << "." << endl;
            equal_runners = false; // reset loop
        }
      }


return 0;
}
