#include "lib/MathUtils.hpp"

int main() {
    Matrix A(3,3);
    std::cin >> A;

    std::cout << A.inverse(A) << std::endl;
    return 0;
}
