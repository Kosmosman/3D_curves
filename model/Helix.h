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

        Helix(double radius, double step) : radius_{radius}, step_{step} {}

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
