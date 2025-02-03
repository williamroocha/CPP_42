#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  for (int i = 0; i < 10; i++) {
    v.push_back(i);
  }

  try {
    std::vector<int>::const_iterator it = easyfind(v, 5);
    std::cout << "Element found: " << *it << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "❌ Exception: " << e.what() << std::endl;
  }

  try {
    std::vector<int>::const_iterator it = easyfind(v, 10);
    std::cout << "Element found: " << *it << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "❌ Exception: " << e.what() << std::endl;
  }

  return 0;
}
