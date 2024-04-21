//
// Created by Tharanga on 2022-12-17.
//

#include "Matrix.h"

Matrix::Matrix(const size_t &numberOfRows, const size_t &numberOfColumn)
        : size_of_matrix{.rows = numberOfRows, .column = numberOfColumn} {
    matrix.resize(numberOfRows);
    for (int row = 0; row < size_of_matrix.rows; row++) {
        matrix.resize(numberOfColumn);
    }
}

Matrix::Matrix(const Matrix &obj) : matrix{obj.matrix}, size_of_matrix{obj.matrix.size(), obj.matrix[0].size()} {

}


bool Matrix::setElement(const int &rowNumber, const int &columnNumber, const double &value) {
    if (columnNumber > size_of_matrix.column || rowNumber > size_of_matrix.rows) {
        return false;
    }
    matrix[rowNumber][columnNumber] = value;
    return true;
}

Matrix Matrix::add(const Matrix &operand) {
    Matrix tempMatrix{matrix};
    if (size_of_matrix.rows == operand.size_of_matrix.rows && size_of_matrix.column == operand.size_of_matrix.column) {
        for (int row = 0; row < size_of_matrix.rows; row++) {
            for (int column = 0; column < size_of_matrix.column; column++) {
                double total = tempMatrix.getElements(row, column) + operand.getElements(row, column);
                tempMatrix.setElement(row, column, total);

            }
        }
    }
    return tempMatrix;
}


Matrix Matrix::subtract(const Matrix &operand) {
    Matrix temp{*this};
    if (size_of_matrix.rows == operand.size_of_matrix.rows && size_of_matrix.column == operand.size_of_matrix.column) {
        for (int row = 0; row < size_of_matrix.rows; row++) {
            for (int column = 0; column < size_of_matrix.column; column++) {
                double difference = temp.getElements(row, column) - operand.getElements(row, column);
                temp.setElement(row, column, difference);
            }
        }
    }
    return temp;
}

Matrix::Matrix(std::vector<std::vector<double>> matrix) : size_of_matrix{matrix.size(), matrix[0].size()} {
    this->matrix = matrix;
}

double Matrix::getElements(const int &rowNumber, const int &columnNumber) const {
    return matrix[rowNumber][columnNumber];
}


Matrix Matrix::scalarMultiplication(const double &scale) {
    std::vector<std::vector<double>> temp{matrix};

    for (auto &row: temp) {
        for (auto &column: row) {
            column *= scale;
        }
    }
    return Matrix{temp};
}

void Matrix::print() const {
    for (auto &row: matrix) {
        std::cout << "[ ";
        for (auto &column: row) {
            std::cout << " " << column << " ";
        }
        std::cout << "] " << std::endl;
    }
}

Matrix Matrix::multiply(const Matrix &operand) {
    Matrix newMatrix{*this};
    if (size_of_matrix.column == operand.size_of_matrix.rows) {

        for (int i = 0; i < size_of_matrix.rows; i++) {
            for (int operand_i = 0; operand_i < operand.size_of_matrix.column; operand_i++) {
                double value = 0;
                for (int j = 0; j < size_of_matrix.column; j++) {
                    value += getElements(i, j) * operand.getElements(j, operand_i);
                }
                newMatrix.setElement(i, operand_i, value);

            }
        }
    }
    return newMatrix;
}

Matrix Matrix::transpose() {

    std::vector<std::vector<double>> arrayMatrix;
    for (int row = 0; row < size_of_matrix.rows; row++) {
        arrayMatrix.resize(size_of_matrix.column);
        for (int column = 0; column < size_of_matrix.column; column++)
            arrayMatrix[row].resize(size_of_matrix.rows);
    }


    for (int row = 0; row < size_of_matrix.rows; row++) {
        for (int column = 0; column < size_of_matrix.column; column++) {
            arrayMatrix[column][row] = matrix[row][column];
        }
    }
    return Matrix(arrayMatrix);
}


int Matrix::rank() {
    int rank = size_of_matrix.rows;
    std::vector<std::vector<double>> temp{matrix};
    for (int i = 0; i < size_of_matrix.rows; i++) {
        temp[i] = divideRow(temp[i]);
        for (int j = i + 1; j < size_of_matrix.rows; j++) {
            temp[j] = divideRow(temp[j]);
            temp[j] = subtractRows(temp[i], temp[j]);
        }
    }
    return numberOfZeroRows(temp);

}


std::vector<double> &Matrix::subtractRows(const std::vector<double> &subtracter, std::vector<double> row) {
    for (int i = 0; i < subtracter.size(); i++) {
        row[i] -= subtracter[i];
    }
    return row;
}

double Matrix::getDivider(const std::vector<double> &rowElements) const {
    for (int column = 0; column < size_of_matrix.column; column++) {
        if (rowElements[column] != 0) {
            return rowElements[column];
        }
    }
}

std::vector<double> Matrix::divideRow(std::vector<double> &rowElements) {
    double divider = getDivider(rowElements);
    for (auto &elements: rowElements) {
        elements /= divider;

    }
    return rowElements;
}

int Matrix::numberOfZeroRows(const std::vector<std::vector<double>> &matrix) {
    int zeroRows = matrix.size();

    for (auto row: matrix) {
        bool checked = true;
        for (auto element: row) {
            if (zeroRows != 0) {
                checked = false;
            }
        }
        if (checked) {
            zeroRows--;
        }
    }
    return zeroRows;
}

Matrix Matrix::getMinorMatrix(int row, int column) {
    std::vector<std::vector<double>> matrixVector(size_of_matrix.rows - 1,
                                                  std::vector<double>(size_of_matrix.column - 1));

    for (int rowNumber = 0, rowIndex = 0; rowNumber < size_of_matrix.rows; rowNumber++) {
        if (rowNumber == row) {
            continue;
        }
        for (int columnNumber = 0, columnIndex = 0; columnNumber < size_of_matrix.column; columnNumber++) {
            if (columnNumber == column) {
                continue;
            }
            matrixVector[rowIndex][columnIndex] = getElements(rowNumber, columnNumber);
            columnIndex++;
        }
        rowIndex++;
    }
    Matrix tempMatrix{matrixVector};
    return tempMatrix;

}


double Matrix::determinant() {
    double determinantValue = 0;
    if (size_of_matrix.rows == 2 || size_of_matrix.column == 2) {
        determinantValue = determinant2x2(*this);
    } else {
        for (int i = 0; i < size_of_matrix.column; i++) {
            determinantValue += getElements(0, i) * pow(-1, i) * getMinorMatrix(0, i).determinant();
        }

    }
    return determinantValue;

}


std::vector<Matrix> Matrix::get2x2Mirrors(Matrix subMatrix) {
    std::vector<Matrix> subMatrices;
    std::vector<Matrix> minorMatrices;

    if (subMatrix.size_of_matrix.rows == 2 && subMatrix.size_of_matrix.column == 2) {
        minorMatrices.push_back(subMatrix);


    } else {
        for (int i = 0; i < subMatrix.size_of_matrix.rows; i++) {
            for (int j = 0; j < subMatrix.size_of_matrix.column; j++) {
                subMatrices.push_back(subMatrix.getMinorMatrix(i, j));
            }
        }
        for (auto &subSubMatrix: subMatrices) {
            for (auto i: get2x2Mirrors(subSubMatrix)) {
                minorMatrices.push_back(i);
            }

        }
    }
    return minorMatrices;
}


double Matrix::determinant2x2(const Matrix &determinant_2x2) {
    return determinant_2x2.getElements(0, 0) * determinant_2x2.getElements(1, 1) -
           determinant_2x2.getElements(0, 1) * determinant_2x2.getElements(1, 0);

}

Matrix Matrix::getCofactor() {
    std::vector<std::vector<double>> cofactors(size_of_matrix.rows, std::vector<double>(size_of_matrix.column));
    for (int i = 0; i < size_of_matrix.rows; i++) {
        for (int j = 0; j < size_of_matrix.column; j++) {
            cofactors[i][j] = getMinorMatrix(i, j).determinant() * pow(-1, i + j);

        }
    }
    return Matrix{cofactors};
}

Matrix Matrix::getAdjoint() {
    return getCofactor().transpose();
}

Matrix Matrix::inverse() {
    return getAdjoint().scalarMultiplication(1 / determinant());
}

Matrix Matrix::operator=(const Matrix &rhs) {
    if (this == &rhs) {
        return *this;
    }
    matrix = rhs.matrix;
    size_of_matrix.rows = rhs.size_of_matrix.rows;
    size_of_matrix.column = rhs.size_of_matrix.column;
    return (*this);

}

Matrix Matrix::operator+(const Matrix &rhs) {
    return add(rhs);
}

Matrix Matrix::operator-(const Matrix &rhs) {
    return subtract(rhs);
}

Matrix Matrix::operator*(const Matrix &rhs) {
    return multiply(rhs);
}

Matrix Matrix::operator/(const double &scaler) {
    return scalarMultiplication(1 / scaler);
}

bool Matrix::operator==(const Matrix &rhs) {
    if (this == &rhs) {
        return true;
    } else {
        if (size_of_matrix.rows == rhs.size_of_matrix.rows && size_of_matrix.column == rhs.size_of_matrix.column) {
            for (int i = 0; i < size_of_matrix.rows; i++) {
                for (int j = 0; j < size_of_matrix.column; j++) {
                    if (getElements(i, j) != getElements(i, j)) {
                        return false;
                    }

                }
            }
            return true;
        }
    }

}

bool Matrix::operator!=(const Matrix &rhs) {
    return (!(*this == rhs));
}

Matrix Matrix::operator*(int &scaler) {
    return scalarMultiplication(scaler);
}

std::ostream &operator<<(std::ostream &os, const Matrix &lhs) {
    for (auto &row: lhs.matrix) {
        std::cout << "[ ";
        for (auto &column: row) {
            std::cout << " " << column << " ";
        }
        std::cout << "] " << std::endl;
    }
    return os;
}
Matrix Matrix::operator~(){
    return transpose();
}




