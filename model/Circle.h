#ifndef CURVES_CIRCLE_H
#define CURVES_CIRCLE_H

#include <cmath>
#include "Base.h"

namespace crv {

    class Circle : public BaseCurve {
    public:
        Circle() = default;

        explicit Circle(double radius) : radius_{radius} {
            if (radius_ < 0) throw std::invalid_argument("radius can't be negative");
        }

        void SetRadius(double new_radius) {
            if (new_radius < 0) throw std::invalid_argument("radius can't be negative");
            radius_ = new_radius;
        }

        [[nodiscard]] double GetRadius() const { return radius_; }

        Point GetPoint(double angle) override { return {radius_ * cos(angle), radius_ * sin(angle), 0}; }

        double GetFirstDerivative(double angle) override { return tan(M_PI_2 + angle); }

        bool operator<(const Circle& other) const { return radius_ < other.radius_; }

        bool operator==(const Circle& other) const { return radius_ == other.radius_; }

    private:
        double radius_{1};
    };

} // crv

#endif //CURVES_CIRCLE_H
