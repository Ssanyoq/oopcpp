#include "matrix.h"
#include <vector>
#include <iostream>

template<typename T>
std::vector<T> makeVector(Matrix<T> matrix, bool &&criteria(T)) {
    const std::size_t height = matrix.getHeight();
    std::vector<T> vector(height);
    for (int i = 0; i < height; i++) {
        std::vector<T> row = matrix.getNonZeroRow(i);
        for (int j = 0; j < row.size(); j++) {
            if (criteria(row[j])) {
                vector[i] += row[j];
            }
        }
    }
    return vector;
}

template <typename T>
bool criteria(T element) {
    return element > 10;
}

int main() {
    Matrix<int> m(10, 10);
    std::cout << m;
    m.setValue(3, 3, 123);
    std::cout << m << m.getValue(3, 8) << std::endl;
    return 0;
}