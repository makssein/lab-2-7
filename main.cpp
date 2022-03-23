#include "lib/MathUtils.hpp"

int main() {
    Matrix A(3,3);
    std::cin >> A;

    A.transposition(A);
    std::cout << A;
    return 0;
}
