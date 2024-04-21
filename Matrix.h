//
// Created by Tharanga on 2022-12-17.
//
#include <iostream>
#include <vector>
#include "math.h"

#ifndef MATIX_MATRIX_H
#define MATIX_MATRIX_H


class Matrix {
    struct size {
        size_t rows;
        size_t column;
    };

    friend std::ostream &operator<<(std::ostream &os, const Matrix &lhs);

private:
    std::vector<std::vector<double>> matrix;

    std::vector<double> &subtractRows(const std::vector<double> &subtracter, std::vector<double> row);

    double getDivider(const std::vector<double> &rowElements) const;

    std::vector<double> divideRow(std::vector<double> &rowElements);

    int numberOfZeroRows(const std::vector<std::vector<double>> &matrix);

    double determinant2x2(const Matrix &matrix2x2);


public:

    Matrix getAdjoint();

    Matrix getCofactor();

    Matrix getMinorMatrix(int row, int column);

    std::vector<Matrix> get2x2Mirrors(Matrix subMatrix);

    double determinant();

    Matrix(const size_t &numberOfRows = 0, const size_t &numberOfColumn = 0);

    Matrix(std::vector<std::vector<double>> matrix);

    Matrix(const Matrix &obj);

    Matrix add(const Matrix &operand);

    Matrix subtract(const Matrix &operand);

    Matrix scalarMultiplication(const double &scale);

    Matrix multiply(const Matrix &operand);

    Matrix transpose();

    bool setElement(const int &rowNumber, const int &columnNumber, const double &value);

    double getElements(const int &rowNumber, const int &columnNumber) const;

    void print() const;

    int rank();

    Matrix inverse();

    struct size size_of_matrix;

    Matrix operator+(const Matrix &rhs);

    Matrix operator-(const Matrix &rhs);

    Matrix operator*(const Matrix &rhs);

    Matrix operator*(int &rhs);

    Matrix operator/(const double &scaler);

    bool operator==(const Matrix &rhs);

    bool operator!=(const Matrix &rhs);

    Matrix operator=(const Matrix &rhs);

    Matrix operator~();

};


#endif //MATIX_MATRIX_H
