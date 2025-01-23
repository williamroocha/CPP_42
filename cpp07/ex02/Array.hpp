#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T> class Array {
private:
  T *data;
  unsigned int len;

public:
  Array();

  Array(unsigned int n);

  Array(const Array &other);

  ~Array();

  Array &operator=(const Array &other);

  T &operator[](unsigned int index);
  const T &operator[](unsigned int index) const;

  unsigned int size() const;
};

#include "Array.tpp"

#endif
