#include "lib/MathUtils.hpp"

int main() {
    Matrix A(3,3);
    std::cin >> A;

    Matrix B(3,3);
    std::cin >> B;

    Matrix C(3,3);

    C = A*B;
    std::cout << C << std::endl;

    C = A-B;
    std::cout << C << std::endl;

    std::cout << A.inverse(A) << std::endl;
    std::cout << A.determinant(A) << std::endl;
    std::cout << A.transposition(A) << std::endl;
    return 0;
}
