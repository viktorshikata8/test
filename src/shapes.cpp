#include <cmath>
#include <numbers>
#include "shapes.h"

lib::Square::Square(const int side) {
    this->m_side = side;
}

auto lib::Square::side() const -> int {
    return this->m_side;
}

auto lib::Square::setSide(const int new_side) -> void {
    if(new_side == this->side())
        return;
    this->m_side = new_side;
}

auto lib::Square::area() const -> float {
    return static_cast<float>(std::pow(this->side(), 2));
}

lib::Circle::Circle(const int radius) {
    this->m_radius = radius;
}

auto lib::Circle::radius() const -> int {
    return this->m_radius;
}

auto lib::Circle::setRadius(const int new_radius) -> void {
    if(new_radius == this->radius())
        return;
    this->m_radius = new_radius;
}

auto lib::Circle::area() const -> float {
    using std::pow;
    using std::numbers::pi;
    return static_cast<float>(pow(this->radius(), 2) * pi);
}

lib::Big::Big() {
    this->a = 1337;
    this->b = 23098234;
    this->c = 1234123;
    this->d = 1234123;
    this->e = 1234123;
    this->f = 1234123;
}
