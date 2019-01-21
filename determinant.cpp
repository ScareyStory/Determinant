/***************************************************************************
** Program Name: readMatrix.cpp
** Name:         Story Caplain
** Date:         01/07/19
** Description:  This function lets the user fill their matrix
***************************************************************************/
#include "determinant.hpp"
#include <iostream>

int determinant(int** matrix, int size) {

  int dval = 0;

  //if 2x2
  if (size == 2) {
    int a = (matrix[0][0]);
    int b = (matrix[0][1]);
    int c = (matrix[1][0]);
    int d = (matrix[1][1]);

    dval = (a*d - b*c);
  }

  //if 3x3
  else if (size == 3) {
    int a = (matrix[0][0]);
    int b = (matrix[0][1]);
    int c = (matrix[0][2]);
    int d = (matrix[1][0]);
    int e = (matrix[1][1]);
    int f = (matrix[1][2]);
    int g = (matrix[2][0]);
    int h = (matrix[2][1]);
    int i = (matrix[2][2]);

    dval = (a*(e*i - f*h) - b*(d*i - f*g) + c*(d*h - e*g));
  }

  return dval;
}
