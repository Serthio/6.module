#include "matrix.h"
#include <cmath>
#include <sstream>

using namespace math;

// Access operators
real& Matrix::operator()(int row, int col)
{
    if (row < 0 || row >= rows_ || col < 0 || col >= cols_)
        throw std::out_of_range("Matrix: index out of bounds");
    return mvec_[cols_ * row + col];
}

const real& Matrix::operator()(int row, int col) const
{
    if (row < 0 || row >= rows_ || col < 0 || col >= cols_)
        throw std::out_of_range("Matrix: index out of bounds");
    return mvec_[cols_ * row + col];
}

// Assignment operators
Matrix& Matrix::operator+=(const Matrix& other)
{
    if (rows_ != other.rows_ || cols_ != other.cols_)
        throw std::invalid_argument("Matrix dimensions don't match for addition");
    
    for (size_t i = 0; i < mvec_.size(); ++i)
        mvec_[i] += other.mvec_[i];
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
    if (rows_ != other.rows_ || cols_ != other.cols_)
        throw std::invalid_argument("Matrix dimensions don't match for subtraction");
    
    for (size_t i = 0; i < mvec_.size(); ++i)
        mvec_[i] -= other.mvec_[i];
    return *this;
}

Matrix& Matrix::operator*=(real scalar)
{
    for (auto& element : mvec_)
        element *= scalar;
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
    *this = *this * other;
    return *this;
}

// Arithmetic operators
Matrix math::operator+(Matrix lhs, const Matrix& rhs)
{
    lhs += rhs;
    return lhs;
}

Matrix math::operator-(Matrix lhs, const Matrix& rhs)
{
    lhs -= rhs;
    return lhs;
}

Matrix math::operator*(const Matrix& A, const Matrix& B)
{
    if (A.cols_ != B.rows_)
        throw std::invalid_argument("Matrix dimensions don't match for multiplication");
    
    Matrix result(A.rows_, B.cols_);
    
    for (int i = 0; i < A.rows_; ++i) {
        for (int j = 0; j < B.cols_; ++j) {
            real sum = 0;
            for (int k = 0; k < A.cols_; ++k)
                sum += A(i, k) * B(k, j);
            result(i, j) = sum;
        }
    }
    return result;
}

Matrix math::operator*(Matrix matrix, real scalar)
{
    matrix *= scalar;
    return matrix;
}

Matrix math::operator*(real scalar, Matrix matrix)
{
    return matrix * scalar;
}

// I/O operators
std::ostream& math::operator<<(std::ostream& os, const Matrix& matrix)
{
    for (int i = 0; i < matrix.rows_; ++i) {
        for (int j = 0; j < matrix.cols_; ++j) {
            os << matrix(i, j);
            if (j < matrix.cols_ - 1) os << ' ';
        }
        if (i < matrix.rows_ - 1) os << '\n';
    }
    return os;
}

std::istream& math::operator>>(std::istream& is, Matrix& matrix)
{
    for (int i = 0; i < matrix.rows_; ++i)
        for (int j = 0; j < matrix.cols_; ++j)
            is >> matrix(i, j);
    return is;
}