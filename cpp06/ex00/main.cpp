#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
  if (argc != 2)
    std::cout << "input invalid!" << std::endl;
  else
    ScalarConverter::convert(argv[1]);
  return (0);
}