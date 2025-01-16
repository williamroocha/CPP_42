#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <cerrno>
#include <climits>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>

// uintptr_t defined as unsigned long for portability
typedef unsigned long uintptr_t;

class Serializer {
private:
  Serializer();
  Serializer(Serializer const &copy);
  ~Serializer();
  Serializer &operator=(Serializer const &copy);

public:
  static uintptr_t serialize(Data *data);
  static Data *deserialize(uintptr_t raw);
};

#endif
