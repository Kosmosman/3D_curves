//
// Created by Joaquina Daeron on 2/4/24.
//

#ifndef INC_3DCURVES_HELIX_H
#define INC_3DCURVES_HELIX_H

#include <cmath>
#include "Base.h"

namespace crv {

    class Helix : public BaseCurve {
    public:
        Helix() = default;

        Helix(double radius, double step) : radius_{radius}, step_{step} {
            if (radius < 0) throw std::invalid_argument("radius can't be negative");
        }

        void SetRadius(double new_radius) {
            if (new_radius < 0) throw std::invalid_argument("radius can't be negative");
            radius_ = new_radius;
        }

        Point GetPoint(double angle) override {
            double z_coordinate = angle / (2 * M_PI) * step_;
            return {radius_ * cos(angle), radius_ * sin(angle), z_coordinate};
        }

        double GetFirstDerivative(double angle) override {
            return tan(M_PI_2 + angle);
        }

    private:
        double radius_{1};
        double step_{1};
    };

} // crv

#endif //INC_3DCURVES_HELIX_H
