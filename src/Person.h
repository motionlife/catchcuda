//
// Created by haoxiong on 12/26/2019.
//
#pragma once
#ifndef LEARNCPP_PERSON_H
#define LEARNCPP_PERSON_H
#endif //LEARNCPP_PERSON_H

#include <string>
#include <memory>
#include "Resource.h"

using namespace std;

class Person {
private:
    string first_name;
    string last_name;
    int id;
    Resource pRes;
public:
    Person(string fn, string ln, int id);

    string GetName() const;

    int GetId() const { return id; }

    void SetId(int id) { id = id; }

    void SetFirstName(string fn) { first_name = fn; }

    void SetLastName(string ln) { last_name = ln; }

//    std::string GetResourceName() const { return pRes.name; };
};
