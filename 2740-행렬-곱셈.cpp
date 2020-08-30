#include <iostream>
#include <stdexcept>
#include <valarray>

class matrix
{
    std::valarray<int> data{};
    int row_{0};
    int col_{0};

    std::valarray<int> row_vec(int row) const {
        return data[std::slice(row * col_, col_, 1)];
    }

    std::valarray<int> col_vec(int col) const {
        return data[std::slice(col, row_, col_)];
    }

public:
    matrix(int row, int col) : row_{row}, col_{col}, data(row * col) {}

    int row() { return row_; }
    int col() { return col_; }

    int& operator()(int row, int col)
    {
        return data[row * col_ + col];
    }

    int operator()(int row, int col) const
    {
        return data[row * col_ + col];
    }

    friend matrix operator*(const matrix&, const matrix&);
    friend std::istream& operator>>(std::istream&, matrix&);
    friend std::ostream& operator<<(std::ostream&, const matrix&);
};

matrix operator*(const matrix& lhs, const matrix& rhs)
{
    if (lhs.col_ != rhs.row_) {
        throw std::runtime_error("Matrix dimensions must agree.");
    }

    matrix res(lhs.row_, rhs.col_);
    for (int r = 0; r < res.row_; ++r) {
        for (int c = 0; c < res.col_; ++c) {
            res(r, c) = (lhs.row_vec(r) * rhs.col_vec(c)).sum();
        }
    }

    return res;
}

std::istream& operator>>(std::istream& is, matrix& mat)
{
    for (int r = 0; r < mat.row_; ++r) {
        for (int c = 0; c < mat.col_; ++c) {
            is >> mat(r, c);
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const matrix& mat)
{
    for (int r = 0; r < mat.row_; ++r) {
        for (int c = 0; c < mat.col_; ++c) {
            os << mat(r, c);
            if (c != mat.col_ - 1) {
                os << ' ';
            }
        }
        os << '\n';
    }
    return os;
}

matrix read_matrix()
{
    int row, col;
    std::cin >> row >> col;
    matrix mat(row, col);
    std::cin >> mat;
    return mat;
}

int main()
{
    matrix a{read_matrix()};
    matrix b{read_matrix()};
    std::cout << a * b;
    return 0;
}
