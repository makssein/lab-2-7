#include "lib/MathUtils.hpp"

int main() {
    Matrix A(3,3);
    std::cin >> A;
    Matrix B(3,3);
    std::cin >> B;
    Matrix C(3,3);

    C = A-B;
    std::cout << C;
    return 0;
}
