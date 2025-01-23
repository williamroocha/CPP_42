#include "Array.hpp"
#include <iostream>

int main() {
  try {
    // Test default constructor
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    // Test parameterized constructor
    Array<int> intArray(5);
    std::cout << "Array size: " << intArray.size() << std::endl;

    // Access and modify elements
    for (unsigned int i = 0; i < intArray.size(); i++) {
      intArray[i] = i * 2;
    }

    for (unsigned int i = 0; i < intArray.size(); i++) {
      std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    // Test copy constructor
    Array<int> copiedArray = intArray;
    copiedArray[0] = 99;
    std::cout << "Copied array: " << copiedArray[0] << std::endl;
    std::cout << "Original array: " << intArray[0] << std::endl;

    // Test assignment operator
    Array<int> assignedArray;
    assignedArray = intArray;
    assignedArray[1] = 88;
    std::cout << "Assigned array: " << assignedArray[1] << std::endl;
    std::cout << "Original array: " << intArray[1] << std::endl;

    // Test out-of-bounds access
    std::cout << intArray[10] << std::endl;

  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}
