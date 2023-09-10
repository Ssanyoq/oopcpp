#ifndef LAB1_MATRIX_INPUT_H
#define LAB1_MATRIX_INPUT_H

#include "matrix.h"

template<class T>
T getNum(T min = std::numeric_limits<T>::lowest(), T max = std::numeric_limits<T>::max()) {
    T a;
    while (true) {
        std::cin >> a;
        if (std::cin.eof())
            throw std::runtime_error("EOF");
        else if (std::cin.bad())
            throw std::runtime_error(std::string("Failed to read number: ") + strerror(errno));
        else if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bad input, try again: " << std::endl;
        } else if (a >= min && a <= max)
            return a;
        else {
            cout << "Not in range, again: ";
        }
    }
}

template<typename T>
Matrix<T> inputMatrix() {
    cout << "Input width and height of the matrix, ^D to stop: ";
    std::size_t width = getNum<std::size_t>();
    std::size_t height = getNum<std::size_t>();
    Matrix<T> matrix(width, height);
    while (true) {
        try {
            cout << "Input x(-1 to stop): ";
            long long x = getNum<long long>(-1, width - 1);
            if (x == -1) {
                break;
            }
            cout << "Input y(-1 to stop): ";
            long long y = getNum<long long>(-1, height - 1);
            if (y == -1) {
                break;
            }
            cout << "Input value: ";
            T val = getNum<T>();
            matrix.setValue(x, y, val);
            cout << "Value is set" << endl;
        } catch (std::runtime_error &e) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return matrix;
        }
    }
    return matrix;
}

#endif //LAB1_MATRIX_INPUT_H
