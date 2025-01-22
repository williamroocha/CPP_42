#include "Array.hpp"
#include <cmath>
#include <iostream>

int main(void) {
  try {
    // Valid tests
    Array<int> a;
    Array<int> b(5);
    Array<char> c(11);

    // Setting values
    for (int i = 0; i < 5; i++)
      b[i] = i;

    // Copy assignment operator
    a = b;

    for (int i = 0; i < 5; i++)
      b[i] = i * 2;

    // Printing a
    std::cout << "a -> ";
    for (int i = 0; i < 5; i++)
      std::cout << a[i] << " ";
    std::cout << std::endl;
    std::cout << "===========" << std::endl;

    // Printing b
    std::cout << "b -> ";
    for (int i = 0; i < 5; i++)
      std::cout << b[i] << " ";
    std::cout << std::endl;
    std::cout << "===========" << std::endl;

    // Setting values
    c[0] = 'H';
    c[1] = 'e';
    c[2] = 'l';
    c[3] = 'l';
    c[4] = 'o';
    c[5] = ' ';
    c[6] = 'W';
    c[7] = 'o';
    c[8] = 'r';
    c[9] = 'l';
    c[10] = 'd';

    // Printing c
    std::cout << "c -> ";
    for (int i = 0; i < 10; i++)
      std::cout << c[i];
    std::cout << std::endl;
    std::cout << "===========" << std::endl;

    // Invalid tests
    std::cout << "Invalid tests -> ";
    std::cout << c[13];
    std::cout << a[-1];
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}