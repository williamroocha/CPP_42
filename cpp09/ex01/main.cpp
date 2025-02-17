#include "RPN.hpp"

int main(int ac, char **av) {

  if (ac != 2) {
    std::cerr << "Usage: ./rpn \"expression\"" << std::endl;
    return 1;
  }

  RPN rpn;
  try {
    std::cout << rpn.evaluate(av[1]) << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}