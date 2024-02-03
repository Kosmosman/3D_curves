#ifndef INC_3DCURVES_ELLIPSE_H
#define INC_3DCURVES_ELLIPSE_H

#include "Base.h"
#include <cmath>

namespace crv {

    class Ellipse :  public BaseCurve {
    public:
        Ellipse()= default;
        explicit Ellipse(double x_radius, double y_radius) : x_radius_{x_radius}, y_radius_{y_radius} {}

        void SetRadius(double new_x_radius, double new_y_radius) {
            x_radius_ = new_x_radius;
            y_radius_ = new_y_radius;
        }
        Point GetPoint(double angle) override { return {x_radius_ * cos(angle), y_radius_ * sin(angle), 0}; }
        double GetFirstDerivative(double angle) override {
            return tan(M_PI_2);
        }


    private:
        double x_radius_{1};
        double y_radius_{1};
    };

} // crv

#endif //INC_3DCURVES_ELLIPSE_H
