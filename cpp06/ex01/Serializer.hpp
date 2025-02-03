#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

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
