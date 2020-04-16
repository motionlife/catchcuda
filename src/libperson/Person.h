//
// Created by haoxiong on 12/26/2019.
//
#pragma once
#ifndef LEARNCPP_PERSON_H
#define LEARNCPP_PERSON_H
#endif // LEARNCPP_PERSON_H

#include "Resource.h"
#include <memory>
#include <string>
#include <utility>

using namespace std;

class Person {
private:
  string first_name;
  string last_name;
  int id;
  //    Resource pRes;
public:
  Person(string fn, string ln, int id);

  string GetName();

  [[nodiscard]] int GetId() const { return id; }

  static void SetId(int id) { id = id; }

  void SetFirstName(string fn) { first_name = std::move(fn); }

  void SetLastName(string ln) { last_name = std::move(ln); }

  //    std::string GetResourceName() const { return pRes.name; };
};
