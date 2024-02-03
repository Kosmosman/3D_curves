#include <iostream>
#include "Circle.h"

int main() {
    crv::Circle c(5);
    std::cout << "Point - {" << c.GetPoint(M_PI_4) << "}\n";
    std::cout << "Derivative - " << c.GetFirstDerivative(M_PI_4) << '\n';
    return 0;
}
