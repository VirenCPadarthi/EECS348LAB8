#include "matrix.hpp"
#include <iostream>
#include <fstream>

void loadMatrices(const std::string &inputFile, int &size, int** &firstMatrix, int** &secondMatrix) {
    std::ifstream file(inputFile);
    file >> size; // Read the matrix size
    firstMatrix = new int*[size];
    secondMatrix = new int*[size];
    
    // Initialize matrices
    for (int i = 0; i < size; ++i) {
        firstMatrix[i] = new int[size];
        secondMatrix[i] = new int[size];
    }

    // Read matrix data from file
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            file >> firstMatrix[i][j];

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            file >> secondMatrix[i][j];
}

void printMatrix(int **matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int** addMatrices(int **firstMatrix, int **secondMatrix, int size) {
    int **result = new int*[size];
    for (int i = 0; i < size; ++i)
        result[i] = new int[size];

    // Add the two matrices element by element
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j)
            result[i][j] = firstMatrix[i][j] + secondMatrix[i][j];

    return result;
}

int** multiplyMatrices(int **firstMatrix, int **secondMatrix, int size) {
    int **result = new int*[size];
    for (int i = 0; i < size; ++i)
        result[i] = new int[size];

    // Multiply the matrices using the standard matrix multiplication formula
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < size; ++k)
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
        }

    return result;
}

int sumDiagonals(int **matrix, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += matrix[i][i]; // Add main diagonal
        sum += matrix[i][size-i-1]; // Add secondary diagonal
    }
    return sum;
}

void swapRows(int **matrix, int size, int rowOne, int rowTwo) {
    for (int i = 0; i < size; ++i) {
        std::swap(matrix[rowOne][i], matrix[rowTwo][i]);
    }
}

void swapColumns(int **matrix, int size, int colOne, int colTwo) {
    for (int i = 0; i < size; ++i) {
        std::swap(matrix[i][colOne], matrix[i][colTwo]);
    }
}

void updateMatrixElement(int **matrix, int size, int row, int col, int newValue) {
    matrix[row][col] = newValue;
}
