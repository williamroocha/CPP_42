#include "Serializer.hpp"

bool isNumber(const std::string &str) {
  if (str.empty())
    return false;

  char *end = NULL;
  errno = 0;

  long value = std::strtol(str.c_str(), &end, 10);

  if (*end != '\0' || errno == ERANGE) {
    return false;
  }

  if (value < INT_MIN || value > INT_MAX) {
    return false;
  }

  return true;
}

int main(int ac, char **av) {
  if (ac != 3) {
    std::cerr << "Error: Invalid number of arguments." << std::endl;
    std::cerr << "Usage: ./serializer <intValue> <stringValue>" << std::endl;
    return 1;
  }

  if (!isNumber(av[1])) {
    std::cerr << "Error: First argument must be a valid integer." << std::endl;
    return 1;
  }
  int intValue;
  std::stringstream(av[1]) >> intValue;

  std::string stringValue = av[2];

  Data data;
  data.intValue = intValue;
  data.stringValue = stringValue;

  std::cout << "Original Data Address: " << &data << std::endl;
  std::cout << "Original Data Content: " << data.intValue << ", "
            << data.stringValue << std::endl;

  uintptr_t raw = Serializer::serialize(&data);
  std::cout << "Serialized Data: " << raw << std::endl;

  Data *deserializedData = Serializer::deserialize(raw);
  std::cout << "Deserialized Data Address: " << deserializedData << std::endl;
  std::cout << "Deserialized Data Content: " << deserializedData->intValue
            << ", " << deserializedData->stringValue << std::endl;

  if (deserializedData == &data) {
    std::cout
        << "Success: The deserialized pointer matches the original pointer."
        << std::endl;
  } else {
    std::cout << "Error: The deserialized pointer does not match the original "
                 "pointer."
              << std::endl;
    return 1;
  }

  return 0;
}
