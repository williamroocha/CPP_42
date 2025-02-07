#include "MutantStack.hpp"

int main() {
  std::cout << "===== TEST 1: MutantStack Basic Functionality ====="
            << std::endl;

  MutantStack<int> mstack;

  mstack.push(5);
  mstack.push(17);
  mstack.push(3);
  mstack.push(9);
  mstack.push(11);

  std::cout << "Top element: " << mstack.top() << std::endl;

  mstack.pop();

  std::cout << "New top after pop: " << mstack.top() << std::endl;

  std::cout << "\n===== TEST 2: Iterating through MutantStack ====="
            << std::endl;

  // Iterate using begin() and end()
  std::cout << "MutantStack elements: ";
  for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end();
       ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  std::cout << "\n===== TEST 3: Comparing with std::list<int> ====="
            << std::endl;

  std::list<int> lstack;

  lstack.push_back(5);
  lstack.push_back(17);
  lstack.push_back(3);
  lstack.push_back(9);
  lstack.push_back(11);

  lstack.pop_back();

  std::cout << "std::list<int> elements: ";
  for (std::list<int>::iterator it = lstack.begin(); it != lstack.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  // Ensure both have same behavior
  if (std::equal(mstack.begin(), mstack.end(), lstack.begin())) {
    std::cout << "\n✅ MutantStack behaves like std::list<int> in iteration!"
              << std::endl;
  } else {
    std::cout << "\n❌ MutantStack iteration differs from std::list<int>!"
              << std::endl;
  }

  return 0;
}
