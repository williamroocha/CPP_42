#include "Array.hpp"

template <typename T> Array<T>::Array() : data(0), len(0) {}

template <typename T> Array<T>::Array(unsigned int n) : data(new T[n]), len(n) {
  for (unsigned int i = 0; i < n; i++) {
    data[i] = T();
  }
}

template <typename T>
Array<T>::Array(const Array &other) : data(new T[other.len]), len(other.len) {
  for (unsigned int i = 0; i < len; i++) {
    data[i] = other.data[i];
  }
}

template <typename T> Array<T>::~Array() { delete[] data; }

template <typename T> Array<T> &Array<T>::operator=(const Array &other) {
  if (this != &other) {
    T *newData = new T[other.len];
    for (unsigned int i = 0; i < other.len; i++) {
      newData[i] = other.data[i];
    }
    delete[] data;
    data = newData;
    len = other.len;
  }
  return *this;
}

template <typename T> T &Array<T>::operator[](unsigned int index) {
  if (index >= len) {
    throw std::out_of_range("Index out of bounds");
  }
  return data[index];
}

template <typename T> const T &Array<T>::operator[](unsigned int index) const {
  if (index >= len) {
    throw std::out_of_range("Index out of bounds");
  }
  return data[index];
}

template <typename T> unsigned int Array<T>::size() const { return len; }
