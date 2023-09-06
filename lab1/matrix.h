#ifndef OOPCPP_MATRIX_H
#define OOPCPP_MATRIX_H

#include <cstddef>
#include <vector>


#include <vector>
#include <iostream>
#include <stdexcept>
#include <map>

/**
 * Universal Matrix class
 * @tparam T - any type that can be printed out
 */
template<typename T>
class Matrix {
private:
    const std::size_t height;
    const std::size_t width;
    std::map<std::size_t, std::map<std::size_t, T> > lines;
public:
    Matrix(std::size_t colsNum, std::size_t rowsNum) : width(colsNum), height(rowsNum),
                                                       lines(std::map<std::size_t, std::map<std::size_t, T> >()) {
    };

    std::size_t getHeight() {
        return height;
    };

    std::size_t getWidth() {
        return width;
    };

    std::size_t getNonZeroWidth(std::size_t row) {
        if (lines.find(row) == std::end(lines)) {
            return 0;
        } else {
            return lines.at(row).size();
        }
    }

    std::size_t getNonZeroHeight() {
        return lines.size();
    }

    std::vector<T> getNonZeroRow(std::size_t row) {
        if (lines.find(row) == std::end(lines)) {
            return std::vector<T>(0);
        }
        std::vector<T> out(lines[row].size());
        int i = 0;
        for (typename std::map<std::size_t, T>::iterator it = lines[row].begin(); it < lines[row].end(); it++) {
            out[i] = it->second;
            i++;
        }
        return out;
    }

    /**
     * Value setter for the matrix
     * @param i row index
     * @param j column index
     * @param value value to be set
     * @throws std::invalid_argument if i or j are out of bounds
     */
    void setValue(std::size_t i, std::size_t j, const T value) {
        if (i < height && j < width) {
            if (lines.find(i) == std::end(lines)) {
                lines[i] = std::map<std::size_t, T>();
            }
            lines[i][j] = value;
        } else {
            throw std::invalid_argument("Indices are out of bounds");
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
            throw std::invalid_argument("Indices are out of bounds");
        }
    }

    /**
     * Overloading << operator for correct printing of the Matrix
     */
    friend std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
        os << "Matrix " << matrix.width << "x" << matrix.height << std::endl;
        for (int i = 0; i < matrix.height; ++i) {
            if (matrix.lines.find(i) == std::end(matrix.lines)) {
                for (int j = 0; i < matrix.width; i++) {
                    std::cout << "0";
                    if (i != matrix.width - 1) {
                        std::cout << " ";
                    }
                }
            } else {
                for (int j = 0; j < matrix.width; ++j) {
                    if (matrix.lines.at(i).find(j) != std::end(matrix.lines.at(i))) {
                        os << matrix.lines.at(i).at(j);
                    } else {
                        os << 0;
                    }
                    os << " ";
                }
            }
            os << std::endl;
        }
        return os;
    }
};

#endif
