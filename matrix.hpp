#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <string>

// Declare all the matrix operation functions
void loadMatrices(const std::string &inputFile, int &size, int** &firstMatrix, int** &secondMatrix);
void printMatrix(int **matrix, int size);
int** addMatrices(int **firstMatrix, int **secondMatrix, int size);
int** multiplyMatrices(int **firstMatrix, int **secondMatrix, int size);
int sumDiagonals(int **matrix, int size);
void swapRows(int **matrix, int size, int rowOne, int rowTwo);
void swapColumns(int **matrix, int size, int colOne, int colTwo);
void updateMatrixElement(int **matrix, int size, int row, int col, int newValue);

#endif
