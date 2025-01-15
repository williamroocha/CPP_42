#include "ScalarConverter.hpp"
#include <cctype>

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "Error: Invalid number of arguments" << std::endl;
    return 1;
  }

  std::string input = av[1];

  // Check for empty input
  if (input.empty()) {
    std::cout << "Error: Input is empty" << std::endl;
    return 1;
  }

  // Check for non-printable characters
  for (size_t i = 0; i < input.length(); ++i) {
    if (!isprint(input[i])) {
      std::cout << "Error: Input contains non-printable characters"
                << std::endl;
      return 1;
    }
  }

  // Perform the conversion
  ScalarConverter::convert(input);

  return 0;
}
