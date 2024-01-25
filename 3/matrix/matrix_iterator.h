
#ifndef LAB3_MATRIX_ITERATOR_H
#define LAB3_MATRIX_ITERATOR_H

#include "matrix.h"
#include <utility>
template<typename T>
class Matrix;

template<typename T>
class MatrixIterator {
private:
    size_t currentRow;
    size_t currentCol;
    const Matrix<T>& matrix;

public:
    explicit MatrixIterator(const Matrix<T>& mat, size_t row = 0, size_t col = 0)
            : currentRow(row), currentCol(col), matrix(mat) {}

    MatrixIterator& operator++() {
        currentCol++;
        if (currentCol == matrix.getWidth()) {
            currentCol = 0;
            currentRow++;
        }
        return *this;
    }

    bool operator!=(const MatrixIterator& other) const {
        return currentRow != other.currentRow || currentCol != other.currentCol;
    }

    T& operator*() const {
        return matrix[currentRow][currentCol];
    }
};




#endif
