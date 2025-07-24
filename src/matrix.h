#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>

namespace math
{
    typedef double real;

    class Matrix
    {
    private:
        int rows_;
        int cols_;
        std::vector<real> mvec_;

    public:
        Matrix() : rows_(0), cols_(0) {};
        Matrix(int rows, int cols) : rows_(rows), cols_(cols), mvec_(rows * cols) {};

        // Access operators
        real& operator()(int row, int col);
        const real& operator()(int row, int col) const;

        // Assignment operators
        Matrix& operator+=(const Matrix& other);
        Matrix& operator-=(const Matrix& other);
        Matrix& operator*=(real scalar);
        Matrix& operator*=(const Matrix& other);

        // Informational methods
        int rows() const { return rows_; }
        int cols() const { return cols_; }

        // Friends
        friend Matrix operator+(Matrix lhs, const Matrix& rhs);
        friend Matrix operator-(Matrix lhs, const Matrix& rhs);
        friend Matrix operator*(const Matrix& A, const Matrix& B);
        friend Matrix operator*(Matrix matrix, real scalar);
        friend Matrix operator*(real scalar, Matrix matrix);

        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
        friend std::istream& operator>>(std::istream& is, Matrix& matrix);
    };
}