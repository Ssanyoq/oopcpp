#ifndef LAB3_MATRIX_H
#define LAB3_MATRIX_H

#include "../utility/coords.h"
#include <vector>

template<typename T>
class Matrix {
private:
    const size_t width;
    const size_t height;

    T **data;

public:
    size_t getWidth() const {return width;};
    size_t getHeight() const  {return height;};

    Matrix(size_t width, size_t height, T filler=T()): width(width), height(height){
        data = new T*[height];
        for (size_t i = 0; i < height; i++) {
            data[i] = new T[width];
            std::fill(data[i], data[i] + width, filler); // Fill the row with the filler value
        }
    };

    Matrix(const Matrix& other) : width(other.width), height(other.height) {
        // Allocate memory for the new matrix
        data = new T*[height];
        for (size_t i = 0; i < height; i++) {
            data[i] = new T[width];
            // Copy the elements from the other matrix
            std::copy(other.data[i], other.data[i] + width, data[i]);
        }
    }
    Matrix<T>& operator=(const Matrix& other) {
        if (this != &other) {  // Check for self-assignment
            // Deallocate existing memory
            for (size_t i = 0; i < height; i++) {
                delete[] data[i];
            }
            delete[] data;

            // Copy the width and height
            width = other.width;
            height = other.height;

            // Allocate memory for the new matrix
            data = new T*[height];
            for (size_t i = 0; i < height; i++) {
                data[i] = new T[width];
                // Copy the elements from the other matrix
                std::copy(other.data[i], other.data[i] + width, data[i]);
            }
        }

        return *this;
    }

    T *&operator[](int index) {
        if (index >= height || index < 0) {
            throw std::out_of_range("Index is out of range");
        }
        return data[index];
    };

    T &operator[](Coordinates elementPos) {
        if (elementPos.y >= height || elementPos.y < 0 || elementPos.x < 0 || elementPos.x >= width) {
            throw std::out_of_range("Coordinates are out of range");
        }
        return data[elementPos.y][elementPos.x];
    }

    size_t size() {
        return height;
    }

    virtual ~Matrix() {
        for (int i = 0; i < height; i++) {
            delete data[i];
        }
        delete[] data;
    }

};

#endif //LAB3_MATRIX_H
