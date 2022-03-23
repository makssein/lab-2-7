#include "lib/MathUtils.hpp"

int main() {
    Matrix A(3,3);
    std::cin >> A;


    std::cout << A.determinant(A);
    return 0;
}
