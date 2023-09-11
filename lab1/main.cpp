#include "matrix_input.h"
#include "matrix.h"
#include "vector_maker.h"

#define DATA_TYPE int

using namespace MatrixSpace;


int main() {
    auto matrix = inputMatrix<DATA_TYPE>();
    printMatrix(matrix);
    cout << endl;
    printVector(makeVector(matrix, criteria));
}