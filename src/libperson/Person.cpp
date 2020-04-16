#include "Person.h"

#include <utility>

Person::Person(string fn, string ln, int id)
    : first_name(std::move(fn)), last_name(std::move(ln)), id(id) {}
string Person::GetName() { return first_name + " " + last_name; }
