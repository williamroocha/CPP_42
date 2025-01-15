#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

enum ConvertType { INT, CHAR, FLOAT, DOUBLE, PSLITERAL, NONE };

class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(ScalarConverter const &copy);
  ScalarConverter &operator=(ScalarConverter const &copy);
  ~ScalarConverter();

public:
  static void convert(const std::string &str);
};

#endif