#ifndef RPN_HPP
#define RPN_HPP

#include <cctype>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>

class RPN {
private:
  std::stack<int> _stack;

public:
  RPN();
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);
  ~RPN();

  void validateExpression(const std::string &expression);
  int evaluate(const std::string &expression);
  void processToken(const std::string &token);
};

#endif