#ifndef CURVES_CIRCLE_H
#define CURVES_CIRCLE_H

#include <cmath>
#include "Base.h"

namespace crv {

    class Circle : public BaseCurve {
    public:
        Circle()= default;
        explicit Circle(double radius) : radius_{radius} {}

        void SetRadius(double new_radius) { radius_ = new_radius; }
        Point GetPoint(double angle) override { return {radius_ * cos(angle), radius_ * sin(angle), 0}; }
        double GetFirstDerivative(double angle) override { return tan(M_PI_2 - radius_ / sin(angle)); }

    private:
        double radius_{1};
    };

} // crv

#endif //CURVES_CIRCLE_H
