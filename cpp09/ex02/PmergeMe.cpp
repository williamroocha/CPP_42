#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
    : _vecSequence(0), _dequeSequence(0), _vecStartTime(0), _vecEndTime(0),
      _dequeStartTime(0), _dequeEndTime(0) {}

PmergeMe::PmergeMe(const PmergeMe &other) { *this = other; }

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
  if (this != &other) {
    _vecSequence = other._vecSequence;
    _dequeSequence = other._dequeSequence;
    _vecStartTime = other._vecStartTime;
    _vecEndTime = other._vecEndTime;
    _dequeStartTime = other._dequeStartTime;
    _dequeEndTime = other._dequeEndTime;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::validateInput(const std::string &input) {
  if (input.empty()) {
    throw std::invalid_argument("Empty input.");
  }

  for (std::string::const_iterator it = input.begin(); it != input.end();
       ++it) {
    if (!isdigit(*it)) {
      throw std::invalid_argument("Invalid character in input.");
    }
  }
}

void PmergeMe::parseInput(int ac, char **av) {
  for (int i = 1; i < ac; ++i) {
    std::string arg = av[i];

    std::stringstream ss(arg);
    int num;
    ss >> num;

    if (ss.fail() || !ss.eof()) {
      throw std::invalid_argument("Invalid number format.");
    }

    if (num < 0) {
      throw std::invalid_argument("Negative numbers not allowed.");
    }

    _vecSequence.push_back(num);
    _dequeSequence.push_back(num);
  }
}

size_t PmergeMe::binarySearch(const std::vector<int> &sequence, int value) {
  size_t low = 0;
  size_t high = sequence.size();

  while (low < high) {
    size_t mid = (low + high) / 2;
    if (sequence[mid] < value) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return low;
}

void PmergeMe::insertionSort(std::vector<int> &sequence) {
  for (size_t i = 1; i < sequence.size(); ++i) {
    int key = sequence[i];
    size_t j = i;

    while (j > 0 && sequence[j - 1] > key) {
      sequence[j] = sequence[j - 1];
      --j;
    }
    sequence[j] = key;
  }
}

void PmergeMe::insertionSort(std::deque<int> &sequence) {
  for (size_t i = 1; i < sequence.size(); ++i) {
    int key = sequence[i];
    size_t j = i;

    while (j > 0 && sequence[j - 1] > key) {
      sequence[j] = sequence[j - 1];
      --j;
    }
    sequence[j] = key;
  }
}

template <typename Container>
void PmergeMe::sortContainer(Container &sequence, std::clock_t &startTime,
                             std::clock_t &endTime) {
  startTime = std::clock();

  if (sequence.size() <= 1) {
    endTime = std::clock();
    return;
  }

  if (sequence.size() <= 10) {
    insertionSort(sequence);
    endTime = std::clock();
    return;
  }

  size_t mid = sequence.size() / 2;
  Container left(sequence.begin(), sequence.begin() + mid);
  Container right(sequence.begin() + mid, sequence.end());

  PmergeMe leftSorter;
  leftSorter._vecSequence = left;
  leftSorter.sortContainer(leftSorter._vecSequence, leftSorter._vecStartTime,
                           leftSorter._vecEndTime);

  PmergeMe rightSorter;
  rightSorter._vecSequence = right;
  rightSorter.sortContainer(rightSorter._vecSequence, rightSorter._vecStartTime,
                            rightSorter._vecEndTime);

  std::merge(leftSorter._vecSequence.begin(), leftSorter._vecSequence.end(),
             rightSorter._vecSequence.begin(), rightSorter._vecSequence.end(),
             sequence.begin());

  endTime = std::clock();
}

void PmergeMe::displayBefore() const {
  std::cout << "Before: ";
  for (size_t i = 0; i < _vecSequence.size(); ++i) {
    std::cout << _vecSequence[i] << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::displayResults() const {
  std::cout << "After: ";
  for (size_t i = 0; i < _vecSequence.size(); ++i) {
    std::cout << _vecSequence[i] << " ";
  }
  std::cout << std::endl;

  double vecTime =
      (_vecEndTime - _vecStartTime) / (double)CLOCKS_PER_SEC * 1000000;
  double dequeTime =
      (_dequeEndTime - _dequeStartTime) / (double)CLOCKS_PER_SEC * 1000000;

  std::cout << "Time to process a range of " << _vecSequence.size()
            << " elements with std::vector: " << std::fixed
            << std::setprecision(5) << vecTime << " us" << std::endl;

  std::cout << "Time to process a range of " << _dequeSequence.size()
            << " elements with std::deque: " << std::fixed
            << std::setprecision(5) << dequeTime << " us" << std::endl;
}

void PmergeMe::sortAndDisplay() {
  try {
    if (_vecSequence.empty()) {
      std::cout << "Error: No valid input provided." << std::endl;
      return;
    }

    displayBefore();
    sortContainer(_vecSequence, _vecStartTime, _vecEndTime);
    _dequeSequence.assign(_vecSequence.begin(), _vecSequence.end());
    _dequeStartTime = _vecStartTime;
    _dequeEndTime = _vecEndTime;

    displayResults();
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}