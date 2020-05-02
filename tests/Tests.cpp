//
// Created by haoxiong on 12/27/2019.
//
#include "catch.hpp"
#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

using namespace std;

enum class Color { RED, GREEN, BLUE, MAGENTA, BLACK };

template <typename T, typename U> auto add(T t, U u) { return t + 2 * u; }

auto sum_product(double a, double b) { return make_pair(a + b, a * b); }

TEST_CASE("modern cpp") {
  auto res(3);
  vector v{1, 2, 3, 4, 5, 6, 7}; // Uniform initialization, initializer lists.
  auto n = count_if(begin(v), end(v), [&](auto e) { return e > v.size() / 2; });
  REQUIRE(n == res + 1);
  REQUIRE(add(4.2, 7.7) == 4.2 + 7.7 * 2);
  function<int(int)> fib = [&fib](int x) {
    return x < 2 ? 1 : fib(x - 1) + fib(x - 2);
  };
  REQUIRE(fib(10) == 89);
  REQUIRE_FALSE(Color::BLUE == Color::MAGENTA);
  SECTION("test variadic") {
    double p;
    tie(ignore, p) = sum_product(4.5, 8.2);
    REQUIRE(p == 4.5 * 8.2);
  }
  SECTION("test smart pointers, lambda init-captures and move semantics") {
    auto ptr = make_unique<double[]>(10);
    [p2 = move(ptr)]() {
      cout << "move(steal) unique pointer into lambda " << p2[9] << endl;
    }();
  }
  SECTION("generic_lambdas") {
    vector lines{"cpp is awesome"s, "real developer's language"s,
                 "let's do cool stuff"s, "brilliant a"s};
    sort(begin(lines), end(lines),
         [](auto const &a, auto const &b) { return a.length() < b.length(); });
    for (const auto &l : lines)
      cout << l << endl;
    REQUIRE(lines.size() == lines.capacity());
  }
  SECTION("declare variable in if") {
    vector str{"Jack", "Jimmy", "Jenny"};
    if (const auto it = find(begin(str), end(str), "Jack"); it != end(str)) {
      *it = "***";
    }
    vector names = {"hello", "world"};
    if (const auto it = find(begin(names), end(names), "world");
        it != end(names)) {
      cout << "Hooray!" << endl;
    }
  }
  SECTION("structured bindings") {
    map<string, string> mydict{
        {"hao", "xiong"}, {"Jenny", "Penny"}, {"John", "doe"}};
    auto [position, success] = mydict.insert({"Teddy", "Bear"});
    pair test_pair{"Teddy", "Bear"};
    REQUIRE(success == 1); // success == true
    REQUIRE(position->first == "Teddy");
    REQUIRE(position->second == "Bear");
    for (const auto &[fn, ln] : mydict)
      cout << fn << " " << ln << endl;
  }
  SECTION("BDD") {
    GIVEN("some container") {
      array a{1, 2, 3, 4};
      auto &ra = a;
      WHEN("called with some condition") {
        int b(10);
        int c{5};
        // int & d;//reference must be initialized
        cout << "b=" << b << " c=" << c << endl;
      }
      THEN("the result should be") {
        REQUIRE(a[3] == 4);
        REQUIRE(ra[2] == 3);
        ra = {6, 7, 8, 9};
        REQUIRE(ra[1] == 7);

        vector<double> distance{1.0, 2.0, 3.0, 4.0, 7.7};
        auto total = accumulate(begin(distance), end(distance), 0.0);
        cout << "total accumulation of distance is: " << total << endl;
      }
    }
  }
  SECTION("queue") {
    deque myq{make_pair("love", 1)};
    //        deque<pair<string,int>> myq{{"love", 0}};
    auto [s, d] = myq.front();
    cout << s << d << endl;
  }
}
