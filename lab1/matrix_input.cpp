#include "matrix.h"
#include <vector>
#include <iostream>
#include <stdexcept>

static void printNZeros(std::size_t n, char delim) {
    for (int i = 0; i < n; i++) {
        std::cout << "0";
        if (i != n - 1) {
            std::cout << delim;
        }
    }
}

template<typename T>
T safe_input() {
    T out;
    std::cin >> out;
    while (not std::cin) {
        if (std::cin.eof()) {
            throw std::runtime_error("EOF");
        } else if (std::cin.fail()) {
            throw std::runtime_error("Unknown input error");
        }
        std::cout << "Incorrect input, try again: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> out;
    }
    return out;
}

template<typename T>
Matrix<T> input_matrix() {
    std::cout << "Input matrix width: ";
    auto width = safe_input<std::size_t>();
    std::cout << "Input matrix height: ";
    auto height = safe_input<std::size_t>();
    Matrix<T> matrix(width, height);
    std::cout << "Now change some cells if you want, ^D to stop:" << std::endl;
    while (true) {
        size_t row, col;
        T val;
        try {
            std::cout << "Input row number: ";
            row = safe_input<size_t>();
            std::cout << "Input column number: ";
            col = safe_input<size_t>();
            std::cout << "Input value to put in this cell: ";
            val = safe_input<T>();
        } catch (std::exception &e) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        try {
            matrix.setValue(row, col, val);
        } catch (std::invalid_argument &e) {
            std::cout << "Invalid row or column number" << std::endl;
        }
    }
    return matrix;
}

int main() {
    Matrix<int> m = input_matrix<int>();
    std::cout << m;
    return 0;
}