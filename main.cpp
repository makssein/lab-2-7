#include "lib/MathUtils.hpp"

int main() {
    Matrix A(2, 3);

    std::cin >> A;
    //std::cout << A << std::endl;

    Matrix B(2, 3);
    std::cin >> B;
    //std::cout << B << std::endl;

    Matrix C(2, 3);
    C = A + B;

    std::cout << "C = " << C << std::endl;

    C = A * B;
    std::cout << C << std::endl;

    return 0;
}
