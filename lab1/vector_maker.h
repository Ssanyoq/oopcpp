#ifndef LAB1_VECTOR_MAKER_H
#define LAB1_VECTOR_MAKER_H
#include "matrix.h"
#include <vector>
#include <iostream>

template<typename T>
std::vector<T> makeVector(Matrix<T> matrix, bool(*f)(T)) {
    std::vector<T> vector(matrix.height);
    for (int i = 0; i < matrix.height; i++) {
        for (int j = 0; j < matrix.width; j++) {
            T val = matrix.getValue(i, j);
            if (f(val)) {
                vector[i] += val;
            }
        }
    }
    return vector;
}

template <typename T>
bool criteria(T element) {
    return element > 10;
}
#endif //LAB1_VECTOR_MAKER_H
