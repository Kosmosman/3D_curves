#ifndef CURVES_BASE_H
#define CURVES_BASE_H

#include <vector>

namespace crv {

    struct Point {
        int x, y, z;
    };

    using Points = std::vector<Point>;

    class BaseCurve {
    public:
        virtual Point GetPoint(double) = 0;
        virtual std::vector<Point> GetFirstDerivative(double) = 0;
        virtual ~BaseCurve()= default;
    };

} // crv

#endif //CURVES_BASE_H
