//
// Created by Hao Xiong on 4/6/2020.
//

#include "catch.hpp"
#include <iostream>
#include <typeinfo>
#include <algorithm>
#include <random>

using namespace std;

unsigned int Factorial(unsigned int number) {
    return number <= 1 ? number : Factorial(number - 1) * number;
}

TEST_CASE("Factorials are computed", "[my test]") {
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}

TEST_CASE("dummy test", "[my test]") {
    REQUIRE(45 * 2 == 90);
}

TEST_CASE("generators", "[my test]") {
    auto x = GENERATE(range(1, 10));
    auto y = GENERATE(range(11, 15));
    CHECK(x < y);
}

using Catch::Matchers::EndsWith;

TEST_CASE("test lambda", "[my test]") {
    auto lbd = []() {};
    REQUIRE_THAT(typeid(lbd).name(), EndsWith("EUlvE_"));
}

TEST_CASE("lambda_capture_rv", "[lambda]") {
    int x{1};
    int y{2};
    vector v{1, 2, 3, 4, 5, 6, 7};
    for_each(begin(v), end(v), [&](int e) {
        x += e;
        y += e;
    });
    CHECK(x == 29);
    CHECK(y == 30);
};

TEST_CASE("algorithm_basics", "[algorithm]") {
    vector<double> v;
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(0, 1.0);
    generate_n(back_inserter(v), 10, [&]() { return dist(mt); });
    for (auto const e : v) cout << e << " ";
    cout << endl;
    auto num = count_if(begin(v), end(v), [](auto e) { return e > 0.5; });
    cout << num << endl;
    REQUIRE(v.size() == 10);
    SECTION("misc") {
        auto bd = 0b010101010111001;
        CHECK(bd == 10937);
        CHECK(bd == 0x2ab9);
        auto ptr = make_unique<double[]>(1000);
        CHECK(ptr[0] == 0);
    }SECTION("chrono") {
        auto str = "c-string-deduced";
        auto str0 = "std string deduced"s;
        auto s = 10s;
//        auto h = 20h;
        auto m = 2min;
        CHECK((--s).count() == 9);
        CHECK((s + m).count() == 129);
    }

}
