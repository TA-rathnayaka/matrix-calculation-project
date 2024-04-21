#include <iostream>
#include <vector>
#include "Matrix.h"


void printAllMatrices(const std::vector<Matrix> &matrices);

void display();

Matrix createMatrix(int numberOfRows, int numberOfColumns);

int main() {
    int input, matrixIndex, scalar;
    Matrix operandOne, operandTwo;
    std::vector<Matrix> matrices;
    do {
        display();
        std::cout << "Enter the option you want to select" << std::endl;
        std::cin >> input;
        switch (input) {
            case 0:
                int NumberOfRows, NumberOfColumns;
                std::cout << "Enter the number of Rows you want for the matrix" << std::endl;
                std::cin >> NumberOfRows;
                std::cout << "Enter the number of Column you want for the matrix" << std::endl;
                std::cin >> NumberOfColumns;
                matrices.push_back(createMatrix(NumberOfRows, NumberOfColumns));
                break;
            case 1:
                printAllMatrices(matrices);
                break;
            case 2:
                printAllMatrices(matrices);
                if (matrices.size() > 0) {
                    std::cout << "Enter the first matrix index you want to add " << std::endl;
                    std::cin >> matrixIndex;
                    if (matrices.size() > matrixIndex) {
                        operandOne = matrices.at(matrixIndex);
                        std::cout << "Enter the second matrix index you want to add " << std::endl;
                        std::cin >> matrixIndex;
                        if (matrices.size() > matrixIndex) {
                            operandTwo = matrices.at(matrixIndex);
                            std::cout << operandOne + operandTwo << std::endl;
                        } else {
                            std::cout << "Wrong Input" << std::endl;
                        }
                    } else {
                        std::cout << "Wrong Input" << std::endl;
                    }


                } else {
                    std::cout << "No matrices found" << std::endl;
                }
                break;
            case 3:
                printAllMatrices(matrices);
                if (matrices.size() > 0) {
                    std::cout << "Enter the first matrix index you want to subtract " << std::endl;
                    std::cin >> matrixIndex;
                    if (matrices.size() > matrixIndex) {
                        operandOne = matrices.at(matrixIndex);
                        std::cout << "Enter the second matrix index you want to subtract " << std::endl;
                        std::cin >> matrixIndex;
                        if (matrices.size() > matrixIndex) {
                            operandTwo = matrices.at(matrixIndex);
                            std::cout << operandOne - operandTwo << std::endl;
                        } else {
                            std::cout << "Wrong Input" << std::endl;
                        }
                    } else {
                        std::cout << "Wrong Input" << std::endl;
                    }


                } else {
                    std::cout << "No matrices found" << std::endl;
                }
                break;
            case 4:
                printAllMatrices(matrices);
                if (matrices.size() > 0) {
                    std::cout << "Enter the first matrix index you want to multiply " << std::endl;
                    std::cin >> matrixIndex;
                    if (matrices.size() > matrixIndex) {
                        operandOne = matrices.at(matrixIndex);
                        std::cout << "Enter the second matrix index you want to multiply " << std::endl;
                        std::cin >> matrixIndex;
                        if (matrices.size() > matrixIndex) {
                            operandTwo = matrices.at(matrixIndex);
                            std::cout << operandOne * operandTwo << std::endl;
                        } else {
                            std::cout << "Wrong Input" << std::endl;
                        }
                    } else {
                        std::cout << "Wrong Input" << std::endl;
                    }


                } else {
                    std::cout << "No matrices found" << std::endl;
                }
                break;
            case 5:
                printAllMatrices(matrices);
                if (matrices.size() > 0) {
                    std::cout << "Enter the matrix index you want to scale " << std::endl;
                    std::cin >> matrixIndex;
                    std::cout << "Enter the scalar you want to multiply the matrix" << std::endl;
                    std::cin >> scalar;
                    operandOne = matrices.at(matrixIndex);
                    if (matrixIndex < matrices.size()) {
                        std::cout << operandOne * scalar << std::endl;
                    } else {
                        std::cout << "Wrong input" << std::endl;
                    }
                } else {
                    std::cout << "No matrices found" << std::endl;
                }

                break;
            case 6:
                printAllMatrices(matrices);
                if (matrices.size() > 0) {
                    std::cout << "Enter the matrix index you want to get the transpose of " << std::endl;
                    std::cin >> matrixIndex;
                    operandOne = matrices.at(matrixIndex);
                    if (matrixIndex < matrices.size()) {
                        std::cout << ~operandOne << std::endl;
                    } else {
                        std::cout << "Wrong input" << std::endl;
                    }
                } else {
                    std::cout << "No matrices found" << std::endl;
                }
                break;
            case 7:
                printAllMatrices(matrices);
                if (matrices.size() > 0) {
                    std::cout << "Enter the matrix index you want to get rank of " << std::endl;
                    std::cin >> matrixIndex;
                    operandOne = matrices.at(matrixIndex);
                    if (matrixIndex < matrices.size()) {
                        operandOne.rank();
                    } else {
                        std::cout << "Wrong input" << std::endl;
                    }
                } else {
                    std::cout << "No matrices found" << std::endl;
                }
                break;
            case 8:
                printAllMatrices(matrices);
                if (matrices.size() > 0) {
                    std::cout << "Enter the matrix index you want to get adjoint of " << std::endl;
                    std::cin >> matrixIndex;
                    operandOne = matrices.at(matrixIndex);
                    if (matrixIndex < matrices.size()) {
                        operandOne.getAdjoint().print();
                    } else {
                        std::cout << "Wrong input" << std::endl;
                    }
                } else {
                    std::cout << "No matrices found" << std::endl;
                }
                break;
            case 9:
                printAllMatrices(matrices);
                if (matrices.size() > 0) {
                    std::cout << "Enter the matrix index you want to get the inverse of " << std::endl;
                    std::cin >> matrixIndex;
                    operandOne = matrices.at(matrixIndex);
                    if (matrixIndex < matrices.size()) {
                        operandOne.inverse().print();
                    } else {
                        std::cout << "Wrong input" << std::endl;
                    }
                } else {
                    std::cout << "No matrices found" << std::endl;
                }
                break;


        }
    } while (input != 7);

    return 0;
}

void printAllMatrices(const std::vector<Matrix> &matrices) {
    int index = 0;
    for (auto matrix: matrices) {
        std::cout << "Matrix index " << index << std::endl;
        matrix.print();
        index++;
    }
}

void display() {
    std::cout << "===============================================================" << std::endl;
    std::cout << """"
                 "███╗░░░███╗░█████╗░████████╗██████╗░██╗░█████╗░███████╗░██████╗\n"
                 "████╗░████║██╔══██╗╚══██╔══╝██╔══██╗██║██╔══██╗██╔════╝██╔════╝\n"
                 "██╔████╔██║███████║░░░██║░░░██████╔╝██║██║░░╚═╝█████╗░░╚█████╗░\n"
                 "██║╚██╔╝██║██╔══██║░░░██║░░░██╔══██╗██║██║░░██╗██╔══╝░░░╚═══██╗\n"
                 "██║░╚═╝░██║██║░░██║░░░██║░░░██║░░██║██║╚█████╔╝███████╗██████╔╝\n"
                 "╚═╝░░░░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚═╝░╚════╝░╚══════╝╚═════╝░"
                 "" << std::endl;
    std::cout << "===============================================================" << std::endl;
    std::cout << "0 - Create a matrix " << std::endl;
    std::cout << "1 - Print all saved Matrices" << std::endl;
    std::cout << "2 - Add matrices" << std::endl;
    std::cout << "3 - Subtract matrices" << std::endl;
    std::cout << "4 - Multiply matrices" << std::endl;
    std::cout << "5 - Scalar multiplication of matrix" << std::endl;
    std::cout << "6 - Transpose of matrix" << std::endl;
    std::cout << "7 - Rank of the matrix" << std::endl;
    std::cout << "8 - Adjoint of the matrix" << std::endl;
    std::cout << "9 - Inverse of the matrix" << std::endl;
    std::cout << "===============================================================" << std::endl;

}

Matrix createMatrix(int numberOfRows, int numberOfColumns) {
    std::vector<std::vector<double>> matrices(numberOfRows, std::vector<double>(numberOfColumns));
    Matrix matrix{matrices};
    double value;
    for (int i = 0; i < numberOfRows; i++) {
        for (int j = 0; j < numberOfColumns; j++) {
            std::cout << "Enter the values you want to fill in " << i << "," << j << " location" << std::endl;
            std::cin >> value;
            matrix.setElement(i, j, value);
            matrix.print();
            std::cout << std::endl;
        }
    }
    return matrix;
}


