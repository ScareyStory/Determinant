/*************************************************************************
** Program Name: matrixMain.cpp
** Name:         Story Caplain
** Date:         01/07/19
** Description:  This program asks the user for an integer which will be
**               the size of the matrix they wish to use. The program will
**               then have the user fill either a 2x2 or 3x3 matrix with
**               numbers of the user's choice, print the matrix, and give
**               the user the determinant of the matrix.
**************************************************************************/
#include <iostream>
#include "readMatrix.hpp"
#include "determinant.hpp"

int main() {

  int input = 0, size = 0, det;

  std::cout << "\n";
  std::cout << "This program creates either a 2x2 or 3x3 matrix\n"     <<
               "for you to fill with integers (0-9) of your choice.\n" <<
               "It will then print out your matrix and give you the "  <<
               "determinant.\n" << std::endl;

  std::cout << "What size matrix would you like?\n\n";
  std::cout << "Note: Any input after valid input will be ignored,\n";
  std::cout << "      and all decimal values will be rounded down \n";
  std::cout << "      to whole numbers. (i.e. 2.99 will be 2)   \n\n";
  std::cout << "Enter 2 for 2x2 or 3 for 3x3: ";

  std::cin >> input;
  //input validation
  int val = 1;
  while(val == 1) {
    if(std::cin.fail() || input < 2 || input > 3) {
      std::cin.clear();
      std::cin.ignore(256, '\n');
      std::cout << "\nYou have entered bad input" << std::endl;
      std::cout << "Enter a 2 or 3 only: ";
      std::cin >> input;
    }   
    else if(!std::cin.fail() || input == 2 || input == 3) {
      val = 0; //break loop if valid input
    }   
  }   

  //if user enters garbage after valid input, (i.e. "2a") ignore it
  std::cin.clear();
  std::cin.ignore(256, '\n');
  std::cout << "\n";

  //store validated input into size
  size = input;

  //create array of user entered size
  int** matrix = new int*[size];
  for (int i = 0; i < size; i++) {
    matrix[i] = new int[size];
  }

  //call readMatrix to let user fill their matrix
  readMatrix(matrix, size);

  //display matrix
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      //if new row, new line
      if(j % size == 0 && i != 0 && i != size) {
        std::cout << std::endl;
      } 
      std::cout << matrix[i][j] << " ";
    }
  }

  det = determinant(matrix, size);

  std::cout << "\n\nThe determinant of the matrix is: " << det << "\n"; 

  //Loop through matrix and delete dynamically allocated memory
  for(int i = 0; i < size; i++) {
    delete [] matrix[i];
    matrix[i] = 0;
  }

  //Delete matrix and set ptr to null
  delete [] matrix;
  matrix = 0;

  return 0;

}
