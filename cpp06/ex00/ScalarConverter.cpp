#include "ScalarConverter.hpp"

// Constructors and Destructor
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &copy) { *this = copy; }

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &copy) {
  if (this != &copy) {
    *this = copy;
  }
  return *this;
}

// Type Checking Helper Functions
bool isFloat(const std::string &str) {
  if (str.empty() || str[str.size() - 1] != 'f')
    return false;
  char *end = NULL;
  errno = 0;
  strtof(str.c_str(), &end);
  return errno != ERANGE && end != NULL && *end == 'f' && *(end + 1) == '\0';
}

bool isDouble(const std::string &str) {
  if (str.empty())
    return false;
  char *end = NULL;
  errno = 0;
  strtod(str.c_str(), &end);
  return errno != ERANGE && end != NULL && *end == '\0';
}

bool isInt(const std::string &str) {
  if (str.empty())
    return false;
  char *end = NULL;
  errno = 0;
  long value = strtol(str.c_str(), &end, 10);
  return errno != ERANGE && end != NULL && *end == '\0' && value >= INT_MIN &&
         value <= INT_MAX;
}

bool isPseudoLiteral(const std::string &str) {
  static const char *pseudoLiterals[] = {"-inff", "+inff", "nanf",
                                         "-inf",  "+inf",  "nan"};
  for (size_t i = 0; i < sizeof(pseudoLiterals) / sizeof(pseudoLiterals[0]);
       ++i) {
    if (str == pseudoLiterals[i]) {
      return true;
    }
  }
  return false;
}

// Detect Conversion Type
ConvertType detectConvertType(const std::string &str) {
  if (str.size() == 1 && isprint(str[0]) && !isdigit(str[0]))
    return CHAR;
  if (isInt(str))
    return INT;
  if (isFloat(str))
    return FLOAT;
  if (isDouble(str))
    return DOUBLE;
  if (isPseudoLiteral(str))
    return PSLITERAL;
  return NONE;
}

// Validation Function for Char
void validateChar(char c) {
  if (c >= 0 && c <= 32) {
    std::cout << "char: Non displayable" << std::endl;
  } else if (isprint(c)) {
    std::cout << "char: '" << c << "'" << std::endl;
  } else {
    std::cout << "char: impossible" << std::endl;
  }
}

// Conversion Functions
void convertFromInt(const std::string &str) {
  int value = std::strtol(str.c_str(), NULL, 10);
  char charValue = static_cast<char>(value);
  float floatValue = static_cast<float>(value);
  double doubleValue = static_cast<double>(value);

  validateChar((value >= 0 && value <= 127) ? charValue : -1);

  std::cout << std::fixed << std::setprecision(1);
  std::cout << "int: " << value << std::endl;
  std::cout << "float: " << floatValue << "f" << std::endl;
  std::cout << "double: " << doubleValue << std::endl;
}

void convertFromFloat(const std::string &str) {
  float value = std::strtof(str.c_str(), NULL);
  char charValue = static_cast<char>(value);
  double doubleValue = static_cast<double>(value);
  int intValue = static_cast<int>(value);

  validateChar((value >= 0 && value <= 127) ? charValue : -1);

  std::cout << std::fixed << std::setprecision(1);
  if (value > static_cast<float>(std::numeric_limits<int>::max()) ||
      value < static_cast<float>(std::numeric_limits<int>::min())) {
    std::cout << "int: impossible" << std::endl;
  } else {
    std::cout << "int: " << intValue << std::endl;
  }
  std::cout << "float: " << value << "f" << std::endl;
  std::cout << "double: " << doubleValue << std::endl;
}

void convertFromDouble(const std::string &str) {
  double value = std::strtod(str.c_str(), NULL);
  char charValue = static_cast<char>(value);
  float floatValue = static_cast<float>(value);
  int intValue = static_cast<int>(value);

  validateChar((value >= 0 && value <= 127) ? charValue : -1);

  std::cout << std::fixed << std::setprecision(1);
  if (value > static_cast<double>(std::numeric_limits<int>::max()) ||
      value < static_cast<double>(std::numeric_limits<int>::min())) {
    std::cout << "int: impossible" << std::endl;
  } else {
    std::cout << "int: " << intValue << std::endl;
  }
  std::cout << "float: " << floatValue << "f" << std::endl;
  std::cout << "double: " << value << std::endl;
}

void convertFromChar(const std::string &str) {
  char value = str[0];
  int intValue = static_cast<int>(value);
  float floatValue = static_cast<float>(value);
  double doubleValue = static_cast<double>(value);

  validateChar(value);

  std::cout << std::fixed << std::setprecision(1);
  std::cout << "int: " << intValue << std::endl;
  std::cout << "float: " << floatValue << "f" << std::endl;
  std::cout << "double: " << doubleValue << std::endl;
}

void convertFromPseudoLiteral(const std::string &str) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;

  if (str == "-inff" || str == "-inf") {
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl;
  } else if (str == "+inff" || str == "+inf") {
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl;
  } else {
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;
  }
}

// Main Convert Function
void ScalarConverter::convert(const std::string &str) {
  switch (detectConvertType(str)) {
  case INT:
    convertFromInt(str);
    break;
  case CHAR:
    convertFromChar(str);
    break;
  case FLOAT:
    convertFromFloat(str);
    break;
  case DOUBLE:
    convertFromDouble(str);
    break;
  case PSLITERAL:
    convertFromPseudoLiteral(str);
    break;
  default:
    std::cout << "Error: Unsupported or invalid input for conversion."
              << std::endl;
    break;
  }
}
