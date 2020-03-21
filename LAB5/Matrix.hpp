#include "Matrix.h"

template<class T>
Matrix<T>::Matrix()
{
    columns_ = 0;
    rows_ = 0;
    buff = nullptr;
}

template<class T>
Matrix<T>::Matrix(int row, int column)
{
    columns_ = column;
    rows_ = row;
    buff = new T[columns_ * rows_];
}

template<class T>
Matrix<T>::~Matrix()
{
    delete[] buff;
}

template<class T>
T Matrix<T>::GetDigit(int row, int column) const
{
    if (row > rows_ || column > columns_ || row < 1 || column < 1) {
        throw MyException("Invalid Index");
    }
    return buff[(row - 1) * columns_ + column - 1];
}

template <class T>
void Matrix<T>::SetDigit(T value, int row, int column)
{
    if (row > rows_ || column > columns_ || row < 1 || column < 1) {
        throw MyException("Invalid Index");
    }
    buff[(row - 1) * columns_ + column - 1] = value;
}