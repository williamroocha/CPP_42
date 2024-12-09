#include "Bureaucrat.hpp"

void testInvalidGradeHigh() {
  try {
    Bureaucrat failA("Test A", -1);
    std::cout << failA << std::endl;
  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cout << "Exception: " << e.what();
  }
}

void testInvalidGradeLow() {
  try {
    Bureaucrat failB("Fail B", 151);
    std::cout << failB << std::endl;
  } catch (Bureaucrat::GradeTooLowException &e) {
    std::cout << "Exception: " << e.what();
  }
}

void testValidBureaucratA() {
  Bureaucrat a("Test A", 6);
  std::cout << "---------------Test A-------------" << std::endl;
  std::cout << a << std::endl;
  a.decrementGrade(5);
  std::cout << a << std::endl;
  a.decrementGrade(1);
  std::cout << a << std::endl;
  a.incrementGrade(10);
  std::cout << a << std::endl;
  a.incrementGrade(2);
  std::cout << a << std::endl;
  std::cout << "----------------------------------" << std::endl;
}

void testValidBureaucratB() {
  Bureaucrat b("Test B", 145);
  std::cout << "---------------Test B-------------" << std::endl;
  std::cout << b << std::endl;
  b.incrementGrade(9);
  std::cout << b << std::endl;
  b.incrementGrade(1);
  try {
    b.decrementGrade(332);
  } catch (Bureaucrat::GradeTooLowException &e) {
    std::cout << "Exception: " << e.what();
  }
  std::cout << b << std::endl;
  std::cout << "----------------------------------" << std::endl;
}

int main() {
  testInvalidGradeHigh();
  testInvalidGradeLow();
  testValidBureaucratA();
  testValidBureaucratB();
  return 0;
}