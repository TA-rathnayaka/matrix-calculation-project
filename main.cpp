#include <iostream>
#include <vector>
#include "Matrix.h"


int main() {
    int input;
    do {
        std::cin >> input;
        switch (input) {
            case 0:
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;

        }
    } while (input != );
    std::vector<std::vector<double>> matrix1vector{{1, 2, 4, 5},
                                                   {3, 4, 5, 6},
                                                   {4, 5, 6, 7},
                                                   {1, 3, 4, 5}
    };
    std::vector<std::vector<double>> matrix2vector{{1, 2, 4},
                                                   {3, 4, 5},
                                                   {4, 5, 6}
    };
    Matrix matrix3{matrix1vector};
    std::cout << matrix3.determinant();


    return 0;
}

