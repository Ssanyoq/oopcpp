#ifndef OOPCPP_MATRIX_H
#define OOPCPP_MATRIX_H

#include <cstddef>
#include <vector>


#include <vector>
#include <iostream>
#include <stdexcept>
#include <map>

using std::cout;
using std::cin;
using std::endl;

namespace MatrixSpace {
/**
 * Universal Matrix class
 * @tparam T - any type that can be printed out
 */
    template<typename T>
    class Matrix {
    private:

        std::map<std::size_t, std::map<std::size_t, T> > lines;
    public:
        const std::size_t height;
        const std::size_t width;

        Matrix(std::size_t colsNum, std::size_t rowsNum) : width(colsNum), height(rowsNum),
                                                           lines(std::map<std::size_t, std::map<std::size_t, T> >()) {
        };

        /**
         * Value setter for the matrix
         * @param i row index
         * @param j column index
         * @param value value to be set
         * @throws std::invalid_argument if i or j are out of bounds
         */
        void setValue(std::size_t i, std::size_t j, const T value) {
            if (i < height && j < width) {
                if (value == NULL) {
                    if (getValue(i, j) != NULL) {
                        lines[i][j] = value;
                        return;
                    }
                }
                if (lines.find(i) == std::end(lines)) {
                    lines[i] = std::map<std::size_t, T>();
                }
                lines[i][j] = value;
            } else {
                throw std::range_error("Indices are out of bounds");
            }
        }

        /**
         * Value getter for the matrix, gets [i][j] element
         * @param i row index
         * @param j column index
         * @throws std::invalid_argument if i or j are out of bounds
         */
        T getValue(std::size_t i, std::size_t j) {
            if (i < height && j < width) {
                if (lines[i].find(j) != std::end(lines[i])) {
                    return lines[i].at(j);
                } else {
                    return 0;
                }
            } else {
                throw std::range_error("Indices are out of bounds");
            }
        }

//    /**
//     * Overloading << operator for correct printing of the Matrix
//     */
//    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
//        os << "Matrix " << matrix.width << "x" << matrix.height << std::endl;
//        for (int i = 0; i < matrix.height; ++i) {
//            for (int j = 0; j < matrix.width; j++) {
//                os << matrix.getValue(i, j);
//                if (j != matrix.width) {
//                    os << " ";
//                }
//            }
//            os << std::endl;
//        }
//        return os;
//    }
    };

    template<typename T>
    void printMatrix(Matrix<T> &matrix) {
        cout << "Matrix " << matrix.height << "x" << matrix.width << endl;
        for (int i = 0; i < matrix.height; i++) {
            for (int j = 0; j < matrix.width; j++) {
                cout << matrix.getValue(i, j);
                if (j != matrix.width - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
}
#endif
