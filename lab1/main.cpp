#include "matrix_input.h"
#include "matrix.h"
#include "vector_maker.h"

#define DATA_TYPE int

using namespace MatrixSpace;

bool criteria(int element) {
    return element > 10;
}

int main() {
    auto matrix = inputMatrix<DATA_TYPE>();
    cout << matrix;
//    printMatrix(matrix);
    cout << endl;
    printVector(makeVector(matrix, criteria));
}