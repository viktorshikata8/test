#include <cstdint>
#include <format>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>
#include <ranges>
#include "shapes.h"

auto add(int a, int b) -> int;

void print_hello_world() {
    std::cout << "Hello world" << std::endl;
}

void print_big(const lib::Big& big) {
    std::cout << std::format("{} {} {} {} {} {}", big.a, big.b, big.c, big.d, big.e, big.f) << std::endl;
}

auto main() -> int {
    using std::cout;
    using std::endl;
    using std::format;
    using std::string;
    using std::vector;
    using std::array;

    cout << "My name is " << "X" << endl;
    cout << format("My name is {}", "X") << endl;

    auto a = 15;
    auto b = &a;
    cout << format("A is {}, B is {}, *B is {}", a, reinterpret_cast<size_t>(b), *b) << endl;

    string name = "Vitya";
    cout << format("My name is {}", name) << endl;
    name = "Dima";
    cout << format("My name is {}", name) << endl;

    if(name.size() == 5)
        cout << "Name is 5 symbols long" << endl;
    else if(name.starts_with("D"))
        cout << "Name starts with D" << endl;
    else
        cout << "Else" << endl;

    for(auto i = 0; i <= 9; ++i) {
        auto zxc = "ZXC";
        cout << format("Cycle for: i={}, zxc={}", i, zxc) << endl;
    }

    auto numbers = array<int, 10>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    numbers[9] = 1337;
    for(const auto number : numbers)
        cout << number << endl;
    auto numbers_dynamic = vector({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    numbers_dynamic.push_back(1337);
    numbers_dynamic.erase(numbers_dynamic.begin());
    cout << endl;
    auto matrix = vector<vector<int>>();
    matrix.resize(10);
    for(auto row = 0; row < 10; ++row) {
        matrix[row].resize(20);
        for(auto column = 0; column < 20; ++column)
            matrix[row][column] = 1;
    }
    for(const auto number : numbers_dynamic)
        cout << number << " ";
    cout << endl;

    auto phone_book = std::map<string, string>({
        {"Name", "+79802342345"},
        {"Vasya", "+36234234"}
    });
    cout << format("Vasya number is {}\n", phone_book["Vasya"]);
    for(const auto& [name, number] : phone_book)
        cout << format("Name={}, number={}\n", name, number);
    cout << format("Sum of 1 and 11 = {}", add(1, 11)) << endl;
    print_hello_world();

    auto add_lambda = [&](const int _a, const int _b) -> int { return _a + _b + numbers.size(); };
    cout << format("Sum of 1 and 11 = {}", add_lambda(1, 11)) << endl;

    const auto names_list = vector<string>{
        "ASdasd", "asdasd", "assfhjsfigj", "ХУЙУЙУ", "Basdasdas"
    };

    vector<string> new_names;
    for(const auto& n : names_list) {
        // if(n.starts_with("B"))
        //     new_names.push_back(n);
        if(not n.starts_with("B"))
            continue;
        new_names.push_back(n);
    }

    auto square = lib::Square(5);
    cout << format("Square side is {}", square.side()) << endl;
    square.setSide(10);
    cout << format("New square side is {}", square.side()) << endl;
    cout << format("Square area is {} m2", square.area()) << endl;

    auto circle = lib::Circle(5);
    cout << format("Circle area is {} m2", circle.area()) << endl;

    vector<lib::Shape*> shapes = { &circle, &square };
    for(const auto& shape : shapes)
        cout << format("Shape area is {} m2", shape->area()) << endl;

    auto z = 15;
    const auto& x = z;
    lib::Big first;
    const auto& second = first;

    vector<lib::Big> big_structures(100);
    for(const auto& big_structure : big_structures)
        print_big(big_structure);
    std::cout << "qwe" << endl;
    return 0;
}

auto add(const int a, const int b) -> int {
    return a + b;
}