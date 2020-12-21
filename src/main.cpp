//
// Created by haoxiong on 12/28/2019.
//
#include <algorithm>
#include <iostream>
//#include <memory>
#include <string>
#include <vector>

#include <Person.h>
#include <vectorAdd.h>
#include <utils.h>

using namespace std;

#if _DEBUG
void foo() {}
#endif
#define MUL(a, b) a *b

int main(int argc, char **argv) {
  auto str = "Modern C++ is awesome!"s;

  //    auto sp = std::unique_ptr<int>{nullptr};
  //    auto sp2 = std::make_unique<int>(123);
  //    cout << str << *sp << *sp2 << endl;

  std::cout << "Hello, World!" << std::endl;
  //    system("cat /etc/os-release");
  std::vector nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  std::sort(std::begin(nums), std::end(nums));
  for (auto const &n : nums) {
    std::cout << MUL(n, 5) << std::endl;
  }
  static_assert(MUL(3, 2 + 2) == 8, "DANGER!");

  int arr[17]; // C style array
  std::cout << "The array length is: " << sizeof(arr) / 4 << std::endl;

  std::array my_arr{1, 2, 3, 4, 5, 6, 7};
  for (auto const &n : my_arr) {
    std::cout << n << std::endl;
  }
  //    std::array<double, 200000000000> dba{};

  Person person("Fighting", "For Freedom", 31);
  cout << person.GetName() << endl;
  cout << "person id is: " << person.GetId() << endl;

  add_gpu(22);
  bandwidthTest(argc, argv);
  deviceQuery(argc, argv);
  return 0;
}
