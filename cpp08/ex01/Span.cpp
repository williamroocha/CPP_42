#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int num) : _N(num) {}

Span::Span(const Span &other) { *this = other; }

Span &Span::operator=(const Span &other) {
  if (this != &other) {
    this->_N = other._N;
    this->_v = other._v;
  }
  return *this;
}
Span::~Span() {}

void Span::addNumber(int num) {
  if (_v.size() >= this->_N)
    throw std::out_of_range("Span is already full");

  _v.push_back(num);
}

void Span::addRange(std::vector<int>::iterator begin,
                    std::vector<int>::iterator end) {
  if (std::distance(begin, end) > static_cast<long>(this->_N - _v.size())) {
    throw std::out_of_range("Not enough space to add the range of numbers");
  }
  _v.insert(_v.end(), begin, end);
}

int Span::shortestSpan() {
  if (_v.size() < 2)
    throw std::out_of_range("Not enough numbers to calculate span");

  std::vector<int> sortedVec = _v;
  std::sort(sortedVec.begin(), sortedVec.end());

  int minDiff = sortedVec[1] - sortedVec[0];

  for (size_t i = 0; i < sortedVec.size() - 1; i++) {
    int diff = sortedVec[i + 1] - sortedVec[i];
    if (diff < minDiff)
      minDiff = diff;
  }
  return minDiff;
}

int Span::longestSpan() {
  if (_v.size() < 2)
    throw std::out_of_range("Not enough numbers to calculate span");
  int min = *std::min_element(_v.begin(), _v.end());
  int max = *std::max_element(_v.begin(), _v.end());
  return (max - min);
}