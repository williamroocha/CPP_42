#include "iter.hpp"

struct CustomType {
  int id;
  std::string name;
};

void printCustomData(CustomType const &data) {
  std::cout << "ID: " << data.id << ", Name: " << data.name << std::endl;
}

void doubleValue(int const &val) { std::cout << val * 2 << std::endl; }

int main(void) {

  int length = 5;
  int arrInt[] = {1, 2, 3, 4, 5};
  double arrDouble[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  char arrChar[] = {'a', 'b', 'c', 'd', 'e'};
  std::string arrString[] = {"one", "two", "three", "four", "five"};

  // Test with different data types
  std::cout << "int: " << std::endl;
  iter<int>(arrInt, length, printData<int>);

  std::cout << std::endl << "double: " << std::endl;
  iter<double>(arrDouble, length, printData<double>);

  std::cout << std::endl << "char: " << std::endl;
  iter<char>(arrChar, length, printData<char>);

  std::cout << std::endl << "str: " << std::endl;
  iter<std::string>(arrString, length, printData<std::string>);

  // Edge Case: Empty Array
  int emptyArr[] = {};
  std::cout << std::endl << "empty array: " << std::endl;
  iter<int>(emptyArr, 0, printData<int>);

  // Large Array
  int largeArr[1000];
  for (int i = 0; i < 1000; i++)
    largeArr[i] = i;
  std::cout << std::endl << "large array: " << std::endl;
  iter<int>(largeArr, 1000, printData<int>);

  // Custom Data Type
  CustomType arrCustom[3] = {{1, "Alice"}, {2, "Bob"}, {3, "Charlie"}};
  std::cout << std::endl << "custom type: " << std::endl;
  iter<CustomType>(arrCustom, 3, printCustomData);

  // Array of Pointers
  std::string *arrPointer[3];
  arrPointer[0] = new std::string("Hello");
  arrPointer[1] = new std::string("World");
  arrPointer[2] = new std::string("!");

  std::cout << std::endl << "array of pointers: " << std::endl;
  iter<std::string *>(arrPointer, 3, printData<std::string *>);

  for (int i = 0; i < 3; ++i) {
    delete arrPointer[i];
  }

  // Different Function
  std::cout << std::endl << "double values: " << std::endl;
  iter<int>(arrInt, length, doubleValue);

  return 0;
}
