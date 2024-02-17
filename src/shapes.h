#pragma once

namespace lib {
    class Shape {
        public:
            virtual ~Shape() = default;

            [[nodiscard]] virtual auto area() const -> float = 0;
    };

    class Square : public Shape {
        public:
            explicit Square(int side);
            ~Square() override = default;

            [[nodiscard]] auto side() const -> int;
            auto setSide(int new_side) -> void;

            [[nodiscard]] auto area() const -> float override;

        private:
            int m_side;
    };

    class Circle : public Shape {
        public:
            explicit Circle(int radius);
            ~Circle() override = default;

            [[nodiscard]] auto radius() const -> int;
            auto setRadius(int new_radius) -> void;

            [[nodiscard]] auto area() const -> float override;

        private:
            int m_radius;
    };

    struct Big {
        explicit Big();
        int a, b, c, d, e, f;
    };
}
