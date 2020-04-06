//
// Created by haoxiong on 12/30/2019.
//
#include "catch.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <map>
#include <random>
#include <tuple>
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
        //string s = "sf12hk8jh3h567kh4gc345fg";
        string s = "gwertyuisghcn";
        partition(begin(s), end(s), [b = true](auto e) mutable {
            if (isalpha(e)) b = !b;
            return b;
        });
        cout << s << endl;
    }SECTION("minmax_element") {
        vector v{1, 2, 3, 4, 5, 6, 7, 2};
        auto pair = minmax_element(begin(v), end(v));
        CHECK((*pair.second - *pair.first) == 6);
        auto[a, b] = minmax_element(begin(v), end(v));
        CHECK(*b - *a == 6);
    }
}

TEST_CASE("Counting and Finding") {
    vector<int> v{1, 2, 3, 4, 5, 6, 7, 2};
    map<int, int> m{{1, 10},
                    {2, 19},
                    {3, 30}};
    SECTION("count") {
        auto n1 = count(v.begin(), v.end(), 2);
        auto n2 = count(begin(v), end(v), 2);
        CHECK(n1 == n2);
        CHECK(count_if(begin(v), end(v), [](auto e) { return e % 2 != 0; }) == 4);
        CHECK(count_if(begin(m), end(m), [](const auto e) { return e.second > 18; }) == 2);
        CHECK(all_of(begin(v), end(v), [](auto e) { return e > 0; }));
        CHECK(none_of(begin(v), end(v), [](auto e) { return e < 0; }));
        CHECK(any_of(begin(m), end(m), [](const auto e) { return e.first == 2; }));
    }SECTION("finding") {
        auto res = find_if(begin(m), end(m), [](const auto e) { return e.second > 10; });
        CHECK(res->first == 2);
    }SECTION("sort") {
        vector<int> v1{-3, -2, -1, 0, 1, 2, 3};
        auto v2 = v1; //copy constructor
        sort(begin(v2), end(v2), [](auto e1, auto e2) { return abs(e1) < abs(e2); });
        CHECK(v2[0] == 0);
        for (auto e : v1) cout << e << " ";
        cout << endl;
        for (auto e : v2) cout << e << " ";
        cout << endl;
        random_device rd;
        mt19937 generator(rd());
        shuffle(begin(v1), end(v1), generator);
        for (auto e : v1) cout << e << " ";
        cout << v1.front() << "~" << v1.back() << endl;
    }SECTION("tuple") {
        auto student = make_tuple(1, "Saul Goodman", 999.9);
        cout << get<1>(student) << endl;
        REQUIRE(get<2>(student) == 999.9);
    }
}