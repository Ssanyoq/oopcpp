#ifndef LAB1_VECTOR_MAKER_H
#define LAB1_VECTOR_MAKER_H
#include "matrix.h"
#include <vector>
#include <iostream>



namespace MatrixSpace {

    template<typename T>
    void printVector(const std::vector<T> &vector) {
        cout << "Vector " << vector.size() << "x1:" << endl;
        for (int i = 0; i < vector.size(); i++) {
            cout << vector[i];
            if (i != vector.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    template<typename T>
    std::vector<T> makeVector(const Matrix<T> &matrix, bool(*criteria)(T)) {
        std::vector<T> vector(matrix.height);
        for (int i = 0; i < matrix.height; i++) {
            for (int j = 0; j < matrix.width; j++) {
                T val = matrix.getValue(i, j);
                if (criteria(val)) {
                    vector[i] += val;
                }
            }
        }
        return vector;
    }


}
#endif //LAB1_VECTOR_MAKER_H
