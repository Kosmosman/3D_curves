#include <iostream>
#include "Circle.h"
#include "Ellipse.h"

int main() {
    crv::Circle c(5);
    std::cout << "Point circle - {" << c.GetPoint(M_PI_4) << "}\n";
    std::cout << "Derivative circle - " << c.GetFirstDerivative(M_PI_4) << '\n';

    crv::Ellipse e(5, 5);
    std::cout << "Point ellipse - {" << e.GetPoint(M_PI_4) << "}\n";
    std::cout << "Derivative ellipse - " << e.GetFirstDerivative(M_PI_4) << '\n';
    return 0;
}
