#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>

class Span {
private:
  std::vector<int> _v;
  unsigned int _N;

public:
  Span();
  Span(unsigned int N);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();

  void addNumber(int N);
  void addRange(std::vector<int>::iterator begin,
                std::vector<int>::iterator end);
  int shortestSpan();
  int longestSpan();
};

#endif