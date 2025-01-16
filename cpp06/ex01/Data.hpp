#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>

class Data {
public:
  int intValue;
  std::string stringValue;

  Data();
  Data(const Data &copy);
  Data &operator=(const Data &copy);
  ~Data();
};

#endif
