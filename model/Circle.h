#ifndef CURVES_CIRCLE_H
#define CURVES_CIRCLE_H

#include "Base.h"

namespace crv {

    class Circle : public BaseCurve {
    public:
        Circle()= default;
        explicit Circle(double radius) : radius_(radius) {};
    private:
        double radius_{};
    };

} // crv

#endif //CURVES_CIRCLE_H
