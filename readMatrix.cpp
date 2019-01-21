/***************************************************************************
** Program Name: readMatrix.cpp
** Name:         Story Caplain
** Date:         01/07/19
** Description:  This function lets the user fill their matrix
***************************************************************************/
#include "readMatrix.hpp"
#include <iostream>
#include <limits>
using std::cin;
using std::cout;
void readMatrix(int** matrix, int size) {

  cout << "Please enter " << size*size << " numbers: " << std::endl;
  cout << "\n";

  int val = 1;

  //loop through matrix and fill with user input
  for(int i=0; i<size; i++) {
    for(int j=0; j<size; j++) {
      cin >> matrix[i][j];
      //input validation
        val = 1;
        while(val == 1) {
          if(cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "\nYou have entered bad input" << std::endl;
            cout << "Enter an integer: " << std::endl;
            cin >> matrix[i][j];
          }
          else if(!cin.fail()) {
            val = 0;
          }
        }
        cin.clear();
        cin.ignore(256, '\n');
    }
  }
  cout << "\n";
}
