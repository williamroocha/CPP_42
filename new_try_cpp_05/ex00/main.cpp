#include "Bureaucrat.hpp"

void testBureaucrat(const std::string &name, int grade) {
  try {
    std::cout << "Testing Bureaucrat creation with name \"" << name
              << "\" and grade " << grade << "..." << std::endl;
    Bureaucrat bureaucrat(name, grade);
    std::cout << "Created: " << bureaucrat << std::endl;

    std::cout << "Attempting to increment grade by 10..." << std::endl;
    bureaucrat.incrementGrade(10);
    std::cout << "After increment: " << bureaucrat << std::endl;

    std::cout << "Attempting to decrement grade by 10..." << std::endl;
    bureaucrat.decrementGrade(10);
    std::cout << "After decrement: " << bureaucrat << std::endl;

    std::cout << "Attempting to decrement grade by another 10..." << std::endl;
    bureaucrat.decrementGrade(10);
    std::cout << "After second decrement: " << bureaucrat << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
  std::cout << "-----------------------------------------" << std::endl;
}

int main() {
  testBureaucrat("Bureaucrat1", 1);
  testBureaucrat("Bureaucrat2", 150);
  testBureaucrat("Bureaucrat3", 75);
  testBureaucrat("Bureaucrat4", 0);
  testBureaucrat("Bureaucrat5", 151);
  return (0);
}
