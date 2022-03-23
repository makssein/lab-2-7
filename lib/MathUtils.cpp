#include "MathUtils.hpp"

Matrix::Matrix(int n, int m){
    std::cout << "Constructor" << std::endl;
    m_n = n;
    m_m = m;
    m_mat = new int* [m_n];
    for (int i = 0; i < m_n; i++)
        m_mat[i] = new int[m_m];
}
Matrix::~Matrix(){
    std::cout << "Destructor" << std::endl;
    for (int i = 0; i < m_n; i++)
        delete[] m_mat[i];
    delete m_mat;
}
Matrix::Matrix(const Matrix& mat){
    std::cout << "Copy constructor" << std::endl;

    m_n = mat.m_n;
    m_m = mat.m_m;

    m_mat = new int* [m_n];
    for (int i = 0; i < m_n; i++)
        m_mat[i] = new int[m_m];

    for (int i = 0; i < m_n; i++)
        for (int j = 0; j < m_m; j++)
            m_mat[i][j] = mat.m_mat[i][j];
}
Matrix& Matrix::operator=(const Matrix& mat) {
    std::cout << "Operator =" << std::endl;

    m_n = mat.m_n;
    m_m = mat.m_m;

    for (int i = 0; i < m_n; i++)
        for (int j = 0; j < m_m; j++)
            m_mat[i][j] = mat.m_mat[i][j];

    return *this;
}
Matrix Matrix::operator+(const Matrix& mat) {
    std::cout << "operator+" << std::endl;
    Matrix tmp(2, 3);
    for (int i = 0; i < m_n; i++)
        for (int j = 0; j < m_m; j++)
            tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
    return tmp;
}
Matrix Matrix::operator+=(const Matrix& mat) {
    std::cout << "operator+=" << std::endl;
    Matrix tmp(2, 3);
    for (int i = 0; i < m_n; i++)
        for (int j = 0; j < m_m; j++)
            tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
    return tmp;
}
Matrix Matrix::operator*(const Matrix& mat) {
    std::cout << "operator*" << std::endl;
    Matrix tmp(2, 3);
    for (int i = 0; i < m_n; i++)
        for (int j = 0; j < m_m; j++)
            tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
    return tmp;
}

std::istream& operator>>(std::istream& in, Matrix& mat){
    for (int i = 0; i < mat.m_n; i++)
        for (int j = 0; j < mat.m_m; j++)
            in >> mat.m_mat[i][j];
    return in;
}

std::ostream& operator<<(std::ostream& out, const Matrix& mat){
    out << "Matrix " << mat.m_n << "x" << mat.m_m << std::endl;
    for (int i = 0; i < mat.m_n; i++) {
        for (int j = 0; j < mat.m_m; j++)
            out << mat.m_mat[i][j] << " ";
        out << std::endl;
    }
    return out;
}

