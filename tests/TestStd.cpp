//
// Created by haoxiong on 12/30/2019.
//
#include "catch.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
//#include <memory>

using namespace std;

TEST_CASE("Test_standard_library") {
    SECTION("reverse") {
        string s = "this is a dummy string";
        auto s1 = s;
        std::reverse(begin(s), end(s));
        REQUIRE(s == string(s1.rbegin(), s1.rend()));
    }SECTION("transform") {
        string s = "Microsoft Google Amazon";
        transform(begin(s), end(s), begin(s), ::tolower);
        CHECK(s == "microsoft google amazon");
    }SECTION("partition") {
        vector nums{1, 2, 3, 4, 5, 6, 7};
        stable_partition(begin(nums), end(nums), [](auto e) { return e % 2 == 0; });
        vector corr{2, 4, 6, 1, 3, 5, 7};
        CHECK(nums == corr);
    }SECTION("psedo_reverse_if") {
//        string s = "sf12hk8jh3h567kh4gc345fg";
        string s = "gwertyuisghcn";
        partition(begin(s), end(s), [b = true](auto e) mutable {
            if (isalpha(e)) b = !b;
            return b;
        });
        cout << s << endl;
    }
}