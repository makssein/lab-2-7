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
    Matrix tmp(m_n, mat.m_m);
    for (int i = 0; i < m_n; i++){
        for (int j = 0; j < mat.m_m; j++){
            tmp.m_mat[i][j] = 0;
            for (int k = 0; k < m_m; k++)
                tmp.m_mat[i][j] += m_mat[i][k] * mat.m_mat[k][j];
        }
    }
    return tmp;
}
Matrix Matrix::operator-(const Matrix& mat) {
    std::cout << "operator-" << std::endl;
    Matrix tmp(m_n, m_m);
    for (int i = 0; i < m_n; i++)
        for (int j = 0; j < m_m; j++)
            tmp.m_mat[i][j] = m_mat[i][j] - mat.m_mat[i][j];
    return tmp;
}
Matrix Matrix::operator-=(const Matrix& mat) {
    std::cout << "operator+=" << std::endl;
    Matrix tmp(m_n, m_m);
    for (int i = 0; i < m_n; i++)
        for (int j = 0; j < m_m; j++)
            tmp.m_mat[i][j] = m_mat[i][j] - mat.m_mat[i][j];
    return tmp;
}
Matrix Matrix::transposition(const Matrix& mat){
    std::cout << "transposition" << std::endl;
    Matrix tmp(m_n,m_m);
    for(int i = 0; i < m_n; i++)
        for(int j = 0; j < m_m; j++)
            tmp.m_mat[i][j] = mat.m_mat[j][i];
    return tmp;
}
int Matrix::determinant(const Matrix& mat){
    int det = 0;
    if(m_n == 2 && m_m == 2){
        det = m_mat[0][0] * m_mat [1][1] - m_mat[0][1]*m_mat[1][0];
        return det;
    } else if(m_n == 3 && m_m == 3){
        det = m_mat[0][0]*(m_mat[1][1]*m_mat[2][2] - m_mat[1][2]*m_mat[2][1]) -
                m_mat[0][1]*(m_mat[1][0]*m_mat[2][2] - m_mat[1][2]*m_mat[2][0]) +
                m_mat[0][2]*(m_mat[1][0]*m_mat[2][1] - m_mat[1][1]*m_mat[2][0]);
        return det;
    } else {
        std::cout << "Вычисление определителя такого порядка не поддерживается" << std::endl;
    }
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

