#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) { *this = other; }

RPN &RPN::operator=(const RPN &other) {
  if (this != &other) {
    _stack = other._stack;
  }
  return *this;
}

RPN::~RPN() {}

void RPN::validateExpression(const std::string &expression) {
  std::istringstream stream(expression);
  std::string token;
  int operandCount = 0;
  int operatorCount = 0;

  while (stream >> token) {
    if (token.size() == 1 && std::isdigit(token[0])) {
      operandCount++;
    } else if (token == "+" || token == "-" || token == "*" || token == "/") {
      operatorCount++;

      if (operandCount < 2) {
        throw std::invalid_argument("Operator without sufficient operands.");
      }

      operandCount--;
    } else {
      throw std::invalid_argument("Invalid token found: " + token);
    }
  }

  if (operandCount != 1) {
    throw std::invalid_argument(
        "The expression is not valid: unbalanced operands or operators.");
  }
}

void RPN::processToken(const std::string &token) {
  if (isdigit(token[0])) {
    std::stringstream ss(token);
    int value;
    ss >> value;
    RPN::_stack.push(value);
  } else {

    int b = RPN::_stack.top();
    RPN::_stack.pop();

    int a = RPN::_stack.top();
    RPN::_stack.pop();

    if (token == "+") {
      RPN::_stack.push(a + b);
    } else if (token == "-") {
      RPN::_stack.push(a - b);
    } else if (token == "*") {
      RPN::_stack.push(a * b);
    } else if (token == "/") {
      if (b == 0) {
        throw std::invalid_argument("Error: division by zero");
      }
      RPN::_stack.push(a / b);
    }
  }
}
int RPN::evaluate(const std::string &expression) {
  validateExpression(expression);

  std::istringstream stream(expression);
  std::string token;

  while (stream >> token) {
    processToken(token);
  }

  if (_stack.size() != 1) {
    throw std::runtime_error(
        "Error in evaluation: stack should contain exactly one element.");
  }

  return _stack.top();
}