#include "Span.hpp"

// Function to test adding numbers and displaying spans
void testBasicFunctionality() {
  std::cout << "===== TEST 1: Basic Functionality =====" << std::endl;
  try {
    Span sp(5);
    sp.addNumber(3);
    sp.addNumber(8);
    sp.addNumber(15);
    sp.addNumber(1);
    sp.addNumber(9);

    std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

    // Should throw an exception
    sp.addNumber(99);
  } catch (const std::exception &e) {
    std::cerr << "✅ Exception Caught (Full Span): " << e.what() << std::endl;
  }
}

// Function to test empty Span exception
void testEmptySpan() {
  std::cout << "\n===== TEST 2: Edge Case - Empty Vector =====" << std::endl;
  try {
    Span emptySpan(5);
    std::cout << "Shortest Span: " << emptySpan.shortestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "✅ Exception Caught (Empty Span): " << e.what() << std::endl;
  }
}

// Function to test one element exception
void testOneElementSpan() {
  std::cout << "\n===== TEST 3: Edge Case - One Element =====" << std::endl;
  try {
    Span oneElementSpan(5);
    oneElementSpan.addNumber(42);
    std::cout << "Shortest Span: " << oneElementSpan.shortestSpan()
              << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "✅ Exception Caught (One Element Span): " << e.what()
              << std::endl;
  }
}

// Function to test adding a range of numbers
void testAddRange() {
  std::cout << "\n===== TEST 4: Adding Multiple Numbers (addRange) ====="
            << std::endl;
  try {
    Span rangeSpan(6);
    int arr[] = {10, 20, 30, 40, 50};

    std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(int));
    rangeSpan.addRange(numbers.begin(), numbers.end());

    std::cout << "Shortest Span: " << rangeSpan.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << rangeSpan.longestSpan() << std::endl;

    // Should throw an exception
    rangeSpan.addNumber(60);

  } catch (const std::exception &e) {
    std::cerr << "✅ Exception Caught (Full Span with addRange): " << e.what()
              << std::endl;
  }
}

// Function to test a large dataset
// Random numbers from 0 to 99,999
void testLargeDataset() {
  std::cout << "\n===== TEST 5: Large Dataset (10,000 numbers) ====="
            << std::endl;
  try {
    Span largeSpan(10000);
    std::srand(std::time(0));

    for (int i = 0; i < 10000; i++) {
      largeSpan.addNumber(std::rand() % 100000);
    }

    std::cout << "Shortest Span: " << largeSpan.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << largeSpan.longestSpan() << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "❌ Error in Large Dataset Test: " << e.what() << std::endl;
  }
}

int main() {
  testBasicFunctionality();
  testEmptySpan();
  testOneElementSpan();
  testAddRange();
  testLargeDataset();
  return 0;
}