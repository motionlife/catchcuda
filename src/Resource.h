#pragma once

#include <string>

using namespace std;

class Resource {
private:
    string name;
public:
    Resource(string);
    Resource(Resource&&) noexcept;
    Resource(const Resource&);

    Resource &operator=(const Resource &);

    ~Resource();

    string GetName() const { return name; }

};
