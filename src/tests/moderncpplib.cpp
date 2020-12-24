//
// Created by Hao Xiong on 4/7/2020.
//

#include "catch.hpp"
#include <iostream>
#include <map>
#include <vector>

auto myfunc() -> int { return 3; }

TEST_CASE("associative_containers") {
  std::unordered_map<int, double> mymap{{1, 2.1}, {7, 6.5}};
  CHECK(mymap[7] == 6.5);

  std::unordered_map<std::string, std::string> dict{{"a", "A"}, {"b", "B"}};
  CHECK(dict["a"] == "A");
  std::unordered_map<char, int> cnt;
  std::string x = "amazing";
  for (char c : x)
    cnt[c]++;
  CHECK(cnt['a'] == 2);
  CHECK(cnt['x'] == 0);
  CHECK(cnt.find('b') == cnt.end());

  SECTION("MISC"){
    std::cout << dict["a"] << std::endl;
    std::cout << dict["none"] << std::endl;
    std::cout << dict["b"] << std::endl;
  }
}

TEST_CASE("linear container") {
  std::vector v1{1, 2, 3, 4, 5};
  auto v2 = v1;
  v2[2] = -9;
  CHECK(v1[2] == 3);
  CHECK(v2[2] == -9);

  int i = 0, j = 0;

  for (auto [x, y] : std::vector<std::pair<int, int>>{
           {i + 1, j}, {i - 1, j}, {i, j + 1}, {i, j - 1}}) {
    std::cout << "(" << x << " " << y << ") ";
  }
  std::cout << v1.capacity()
            << " v1[v1.capacity()+1]==" << v1[v1.capacity() + 1] << " "
            << v1.capacity();
}