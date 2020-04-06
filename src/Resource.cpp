//
// Created by haoxiong on 12/26/2019.
//

#include "Resource.h"
#include <iostream>
#include <utility>

using namespace std;

Resource::Resource(string n) : name(move(n)) {
    cout << "constructing resource :" << name << endl;
}

Resource::Resource(const Resource &r) : name(r.name) {
    cout << "copy constructing resource :" << name << endl;
}

Resource::Resource(Resource &&r) noexcept: name(move(r.name)) {
    cout << "moving constructing resource" << endl;
}

Resource &Resource::operator=(const Resource &r) {
    cout << "copy assigning resource :" << name << endl;
    if (this != &r) { //handle self-assignment properly
        name = r.GetName();
    }
    return *this;
}

Resource::~Resource() {
    cout << "destruction resource:" << name << endl;
}

