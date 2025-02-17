#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

class PmergeMe {

private:
  std::vector<int> _vecSequence;
  std::deque<int> _dequeSequence;
  std::clock_t _vecStartTime;
  std::clock_t _vecEndTime;
  std::clock_t _dequeStartTime;
  std::clock_t _dequeEndTime;

public:
  PmergeMe();
  PmergeMe(const PmergeMe &other);
  PmergeMe &operator=(const PmergeMe &other);
  ~PmergeMe();

  void parseInput(int ac, char **av);
  void sortAndDisplay();

  void validateInput(const std::string &input);

  void displayResults() const;
  void displayBefore() const;

  size_t binarySearch(const std::vector<int> &sequence, int value);
  void insertionSort(std::vector<int> &sequence);
  void insertionSort(std::deque<int> &sequence);

  template <typename Container>
  void sortContainer(Container &sequence, std::clock_t &startTime,
                     std::clock_t &endTime);
};

#endif