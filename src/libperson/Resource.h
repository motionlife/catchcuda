#pragma once

#include <string>

using namespace std;

class Resource {
private:
  string name;

public:
  explicit Resource(string);
  Resource(Resource &&) noexcept;
  Resource(const Resource &);

  Resource &operator=(const Resource &);

  ~Resource();

  [[nodiscard]] string GetName() const { return name; }
};
