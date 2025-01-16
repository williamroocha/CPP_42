#include "Data.hpp"

Data::Data() : intValue(0), stringValue("default") {}

Data::Data(const Data &copy)
    : intValue(copy.intValue), stringValue(copy.stringValue) {}

Data &Data::operator=(const Data &copy) {
  if (this != &copy) {
    intValue = copy.intValue;
    stringValue = copy.stringValue;
  }
  return *this;
}
Data::~Data() {}
