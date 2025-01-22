#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

#include <iostream>
#include <stdexcept>

template <typename T> class Array {
private:
  T *_array;
  unsigned int _size;

public:
  Array() : _array(NULL), _size(0) {}

  Array(unsigned int n) : _array(n ? new T[n]() : NULL), _size(n) {}

  Array(const Array &src) : _array(new T[src._size]), _size(src._size) {
    for (unsigned int i = 0; i < _size; i++) {
      _array[i] = src._array[i];
    }
  }

  ~Array() { delete[] _array; }

  Array &operator=(const Array &rhs) {
    if (this != &rhs) {
      T *temp = new T[rhs._size];
      for (unsigned int i = 0; i < rhs._size; i++) {
        temp[i] = rhs._array[i];
      }
      delete[] _array;
      _array = temp;
      _size = rhs._size;
    }
    return *this;
  }

  T &operator[](unsigned int i) {
    if (i >= _size) {
      throw std::out_of_range("Index out of range");
    }
    return _array[i];
  }

  const T &operator[](unsigned int i) const {
    if (i >= _size) {
      throw std::out_of_range("Index out of range");
    }
    return _array[i];
  }

  unsigned int size() const { return _size; }
};

#endif
