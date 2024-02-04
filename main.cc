#include <iostream>
#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"
#include <random>

// Part 2 - Populate a container (e.g. vector or list) of objects of these types created in random manner with
// random parameters.
std::vector<crv::BaseCurve *> GetRandomCurveObjects(int count) {
    std::vector<crv::BaseCurve *> objects{};
    objects.reserve(count);

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(1, 3);
    std::uniform_real_distribution<> dist20(0., 20.);

    for (int i{}; i < count; ++i) {
        switch (dist6(rng)) {
            case 1:
                objects.emplace_back(new crv::Circle{dist20(rng)});
                break;
            case 2:
                objects.emplace_back(
                        new crv::Ellipse{dist20(rng), dist20(rng)});
                break;
            case 3:
                objects.emplace_back(
                        new crv::Helix{dist20(rng), dist20(rng)});
                break;
        }
    }
    return objects;
}

// Part 3 - Print coordinates of points and derivatives of all curves in the container at t=PI/4.
void PrintPointsData(const std::vector<crv::BaseCurve *> &curves) {
    for (const auto &i: curves) {
        std::cout << "Figure class - " << typeid(*i).name() << '\n';
        std::cout << "Point coordinate - {" << i->GetPoint(M_PI_4) << "}\n";
        std::cout << "Point derivative - " << i->GetFirstDerivative(M_PI_4) << '\n';
        std::cout << "-----------\n";
    }
}

// Part 4 - Populate a second container that would contain only circles from the first container. Make sure the
// second container shares (i.e. not clones) circles of the first one, e.g. via pointers.
std::vector<crv::Circle *> GetCirclesFromCurves(const std::vector<crv::BaseCurve *> &objects) {
    std::vector<crv::Circle *> circles{};
    circles.reserve(objects.size());
    auto t = typeid(crv::Circle).hash_code();
    for (auto &i: objects) {
        if (typeid(*i).hash_code() == t) {
            circles.push_back(dynamic_cast<crv::Circle *>(i));
        }
    }
    return circles;
}

// Part 5 - Sort the second container in the ascending order of circles’ radii. That is, the first element has the
// smallest radius, the last - the greatest.
void SortCircles(std::vector<crv::Circle *> &circles) {
    std::sort(circles.begin(), circles.end(), [&](crv::Circle *c, crv::Circle *other) { return *c < *other; });
}

// Part 6 - Compute the total sum of radii of all curves in the second container.
double CirclesRadiusSum(const std::vector<crv::Circle *> &circles) {
    double result{};
    for (auto &i: circles) {
        result += i->GetRadius();
    }
    return result;
}

int main() {
    auto obj = GetRandomCurveObjects(30);
    PrintPointsData(obj);
    auto circles = GetCirclesFromCurves(obj);
    SortCircles(circles);
    std::cout << "Sum of radii - " << CirclesRadiusSum(circles) << '\n';
    for (auto i: obj)
        delete i;
    return 0;
}

