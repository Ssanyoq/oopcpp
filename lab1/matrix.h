#ifndef OOPCPP_MATRIX_H
#define OOPCPP_MATRIX_H

#include <cstddef>
#include <vector>


#include <vector>
#include <iostream>
#include <stdexcept>
#include <map>
#include <unordered_map>

using std::cout;
using std::cin;
using std::endl;

namespace MatrixSpace {
    template<typename T>
    class Matrix;
}

template <typename T>
std::ostream &operator<< (std::ostream &os, const MatrixSpace::Matrix<T> &matrix);

namespace MatrixSpace {
/**
 * Universal Matrix class
 * @tparam T - any type that can be printed out
 */
    template<typename T>
    class Matrix {
    private:

        std::unordered_map<std::size_t, std::unordered_map<std::size_t, T> > lines;
    public:
        const std::size_t height;
        const std::size_t width;

        Matrix(std::size_t colsNum, std::size_t rowsNum) : width(colsNum), height(rowsNum),
                                                           lines(std::unordered_map<std::size_t, std::unordered_map<std::size_t, T> >()) {
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
                if (value == 0) {
                    if (getValue(i, j) != 0) {
                        lines[i].erase(j);
                        if (lines[i].size() == 0) {
                            lines.erase(i);
                        }
                        return;
                    }
                }
                if (lines.find(i) == lines.end()) {
                    lines[i] = std::unordered_map<std::size_t, T>();
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
        T getValue(std::size_t i, std::size_t j) const {
            if (i < height && j < width) {
                if (lines.find(i) == lines.end()) {
                    return 0;
                }
                if (lines.at(i).find(j) != lines.at(i).end()) {
                    return lines.at(i).at(j);
                } else {
                    return 0;
                }
            } else {
                throw std::range_error("Indices are out of bounds");
            }
        }

    /**
     * Overloading << operator for correct printing of the Matrix
     */
    friend std::ostream &operator<< <>(std::ostream &os, const Matrix<T> &matrix);
    };

//    template<typename T>
//    void printMatrix(Matrix<T> &matrix) {
//        cout << "Matrix " << matrix.height << "x" << matrix.width << endl;
//        for (int i = 0; i < matrix.height; i++) {
//            for (int j = 0; j < matrix.width; j++) {
//                cout << matrix.getValue(i, j);
//                if (j != matrix.width - 1) {
//                    cout << " ";
//                }
//            }
//            cout << endl;
//        }
//    }
}

template< typename T>
std::ostream &operator<< (std::ostream &os, const MatrixSpace::Matrix<T> &matrix) {
    os << "Matrix " << matrix.width << "x" << matrix.height << std::endl;
    for (int i = 0; i < matrix.height; ++i) {
        for (int j = 0; j < matrix.width; j++) {
            os << matrix.getValue(i, j);
            if (j != matrix.width) {
                os << " ";
            }
        }
        os << std::endl;
    }
    return os;
}
#endif
