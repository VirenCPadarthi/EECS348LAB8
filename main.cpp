// EECS 348 Assignment 2
// Author: Viren Padarthi
// Student ID: 3131950
// Date: 3/28/2025
// Date Last Modified: 4/2/2025
// Input: A text file containing matrix data (matrix size followed by matrix elements)
// Output: Prints the matrices, results of operations (addition, multiplication, diagonal sums), and updated matrices.
// Collaborators: None
//sources: Lecture SLIDES, GeeksforGeeks,W3Schools, Youtube, TutorialsPoint, Grammarly, stackoverflow,



#include <iostream>
#include <fstream>
#include "matrix.hpp"

int main() {
    std::string inputFile;
    std::cout << "Enter the filename that contains matrix data: ";
    std::cin >> inputFile;

    // Load matrices from the file
    int size;
    int **firstMatrix, **secondMatrix;
    loadMatrices(inputFile, size, firstMatrix, secondMatrix);

    // Display the matrices
    std::cout << "First Matrix:" << std::endl;
    printMatrix(firstMatrix, size);
    std::cout << "Second Matrix:" << std::endl;
    printMatrix(secondMatrix, size);

    // Add the matrices
    int **sumMatrix = addMatrices(firstMatrix, secondMatrix, size);
    std::cout << "Result of Addition:" << std::endl;
    printMatrix(sumMatrix, size);

    // Multiply the matrices
    int **productMatrix = multiplyMatrices(firstMatrix, secondMatrix, size);
    std::cout << "Result of Multiplication:" << std::endl;
    printMatrix(productMatrix, size);

    // Sum of diagonals
    int diagonalTotal = sumDiagonals(firstMatrix, size);
    std::cout << "Diagonal Sum: " << diagonalTotal << std::endl;

    // Row swapping
    int rowOne, rowTwo;
    std::cout << "Enter the row numbers to swap: ";
    std::cin >> rowOne >> rowTwo;
    swapRows(firstMatrix, size, rowOne, rowTwo);
    std::cout << "Matrix after swapping rows:" << std::endl;
    printMatrix(firstMatrix, size);

    // Column swapping
    int colOne, colTwo;
    std::cout << "Enter the column numbers to swap: ";
    std::cin >> colOne >> colTwo;
    swapColumns(firstMatrix, size, colOne, colTwo);
    std::cout << "Matrix after swapping columns:" << std::endl;
    printMatrix(firstMatrix, size);

    // Update matrix element
    int targetRow, targetCol, newValue;
    std::cout << "Enter row, column, and new value to update the matrix: ";
    std::cin >> targetRow >> targetCol >> newValue;
    updateMatrixElement(firstMatrix, size, targetRow, targetCol, newValue);
    std::cout << "Updated Matrix:" << std::endl;
    printMatrix(firstMatrix, size);

    return 0;
}
