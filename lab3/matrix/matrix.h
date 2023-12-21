#ifndef LAB3_MATRIX_H
#define LAB3_MATRIX_H

#include "../utility/coords.h"
#include <vector>



template<typename T>
class Matrix {
    /**
     * 2-dimensional matrix of any type
     */
private:
    unsigned long width;
    unsigned long height;

    T *data;

public:
    size_t getWidth() const
    /**
     * @returns width of matrix
     *
     */
     {return width;};

    size_t getHeight() const
    /**
     * @returns height of matrix
     */
    {return height;};


    explicit Matrix(std::vector<std::vector<T>> map)
    /**
     * vector to matrix transformer, mostly for tests
     */
    {
        height = map.size();
        width = map[0].size();
        data = new T[height * width];
        for (size_t i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                data[i * width + j] = map[i][j];
            }
        }
    }

    Matrix(size_t width, size_t height, T filler=T()): width(width), height(height)
    /**
     * @param width  width of new matrix
     * @param height height of new matrix
     * @param filler element that will be used to fill
     */
    {
        data = new T[height * width];
        for (auto i = 0; i < height * width; i++) {
            data[i] = filler;
        }
    };
    Matrix(const Matrix& other) : width(other.width), height(other.height) {
        // Allocate memory for the new matrix
        data = new T[height * width];
        for (size_t i = 0; i < height * width; i++) {
            data[i] = other.data[i];
        }
    }
    Matrix<T>& operator=(const Matrix& other) {
        if (this != &other) {  // Check for self-assignment
            // Deallocate existing memory
            delete[] data;

            // Copy the width and height
            width = other.getWidth();
            height = other.getHeight();

            // Allocate memory for the new matrix
            data = new T[height * width];
            for (size_t i = 0; i < height * width; i++) {
                // Copy the elements from the other matrix
                data[i] = other.data[i];
            }
        }

        return *this;
    }

    T *operator[](int index) {
        if (index >= height || index < 0) {
            throw std::out_of_range("Index is out of range");
        }
        return &(data[index * width]);
    };

    T &operator[](Coordinates elementPos) const {
        if (elementPos.y >= height || elementPos.y < 0 || elementPos.x < 0 || elementPos.x >= width) {
            throw std::out_of_range("Coordinates are out of range");
        }
        return data[elementPos.y * width + elementPos.x];
    };

    T *&operator[](Coordinates elementPos) {
        if (elementPos.y >= height || elementPos.y < 0 || elementPos.x < 0 || elementPos.x >= width) {
            throw std::out_of_range("Coordinates are out of range");
        }
        return data[elementPos.y * width + elementPos.x];
    }

    size_t size() const {
        return height;
    }

    void addToBottom(unsigned n, T filler=T()) {

        auto newData = new T[width * (height + n)];
        for (int i = 0; i < width * height; i++) {
            newData[i] = data[i];
        }

        for (int i = width * height; i < width * (height + n); i++) {
            newData[i] = filler;
        }
        height += n;
        delete data;
        data = newData;
    }
    void addToTop(unsigned n, T filler=T()) {

        auto newData = new T[width * (height + n)];
        for (int i = 0; i < width * n; i++) {
            newData[i] = filler;
        }
        for (int i = width * n; i < width * (height + n); i++) {
            newData[i] = data[i - (width * n)];
        }
        height += n;
        delete data;
        data = newData;
    }

    void addToLeft(unsigned n, T filler=T()) {

        auto newData = new T[(width + n) * height];

        for (int i = 0; i < (width + n) * height; i++) {
            if (i % (width + n) < n) {
                newData[i] = filler;
            } else {
                newData[i] = data[i - (i / (width + n) + 1) * n];
            }
        }
        width += n;
        delete data;
        data = newData;
    }

    void addToRight(unsigned n, T filler=T()) {

        auto newData = new T[(width + n) * height];

        for (int i = 0; i < (width + n) * height; i++) {
            if (i % (width + n) >= width) {
                newData[i] = filler;
            } else {
                newData[i] = data[i - (i / (width + n)) * n];
            }
        }
        width += n;
        delete data;
        data = newData;
    }
    void setElement(Coordinates target, T value) {
        this->operator[](target.y)[target.x] = value;
    }

    void fillLine(Coordinates from, Coordinates to, T filler) {
        auto current = from;
        setElement(current, filler);
        while (current.x != to.x || current.y != to.y) {
            if (current.x < to.x) {
                current.x++;
            } else if (current.x > to.x) {
                current.x--;
            }
            if (current.y < to.y) {
                current.y++;
            } else if (current.y > to.y) {
                current.y--;
            }
            setElement(current, filler);
        }
        setElement(current, filler);
    }


    virtual ~Matrix() {
        delete[] data;
    }

};

#endif //LAB3_MATRIX_H
