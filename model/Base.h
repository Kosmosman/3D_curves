#ifndef CURVES_BASE_H
#define CURVES_BASE_H

#include <vector>
#include <iostream>

namespace crv {

    struct Point {
        double x, y, z;

        friend std::ostream &operator<<(std::ostream &stream, const Point &p) {
            stream << p.x << ' ' << p.y << ' ' << p.z;
            return stream;
        };
    };

    class BaseCurve {
    public:
        virtual Point GetPoint(double) = 0;

        virtual double GetFirstDerivative(double) = 0;

        virtual ~BaseCurve() = default;
    };

} // crv

#endif //CURVES_BASE_H
