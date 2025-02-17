#include "PmergeMe.hpp"

int main(int ac, char **av) {
  if (ac < 2) {
    std::cerr << "Usage: " << av[0] << " <numbers...>" << std::endl;
    return 1;
  }

  try {
    PmergeMe sorter;
    sorter.parseInput(ac, av);
    sorter.sortAndDisplay();
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}