#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T *array, size_t length, void (*func)(T const &)) {
  for (size_t i = 0; i < length; i++) {
    func(array[i]);
  }
}

template <typename T> void printData(T const &data) {
  std::cout << data << std::endl;
}

template <typename T>
void printArray(T *array, int length, const std::string &typeName) {
  std::cout << typeName << ": " << std::endl;
  iter<T>(array, length, printData<T>);
  std::cout << std::endl;
}

#endif