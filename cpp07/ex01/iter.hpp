#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T> void iter(T *array, unsigned int len, void (*func)(T &)) {
  if (!array || !func)
    return;
  for (unsigned int i = 0; i < len; i++) {
    func(array[i]);
  }
}

template <typename T>
void iter(const T *array, unsigned int len, void (*func)(const T &)) {
  if (!array || !func)
    return;
  for (unsigned int i = 0; i < len; i++) {
    func(array[i]);
  }
}

template <typename T> void print(const T &x) { std::cout << x << std::endl; }

#endif