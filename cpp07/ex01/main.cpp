#include "iter.hpp"

using namespace std;

template <typename T>
void printArray(T *array, int length, const std::string &typeName) {
  cout << typeName << ": " << std::endl;
  iter(array, length, print<T>);
  cout << std::endl;
}

int main(void) {
  int length = 5;

  int arrInt[] = {1, 2, 3, 4, 5};
  double arrDouble[] = {1.1, 2.2, 3.3, 4.4, 5.5};
  char arrChar[] = {'a', 'b', 'c', 'd', 'e'};
  std::string arrString[] = {"one", "two", "three", "four", "five"};

  printArray(arrInt, length, "int");
  printArray(arrDouble, length, "double");
  printArray(arrChar, length, "char");
  printArray(arrString, length, "str");

  return 0;
}
