#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

void testShrubberyCreationForm() {
  // Test a valid case
  try {
    std::cout << "Testing a valid ShrubberyCreationForm..." << std::endl;
    Bureaucrat bob("Bob", 135); // Grade sufficient to execute
    ShrubberyCreationForm form("home");

    std::cout << "Signing the form..." << std::endl;
    form.beSigned(bob);

    std::cout << "Executing the form..." << std::endl;
    form.execute(bob);

    std::cout << "Shrubbery file created successfully!" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  // Test insufficient grade to execute
  try {
    std::cout << "\nTesting execution with insufficient grade..." << std::endl;
    Bureaucrat lowRank("LowRank", 150); // Grade too low to execute
    ShrubberyCreationForm form("garden");

    std::cout << "Signing the form..." << std::endl;
    form.beSigned(lowRank);

    std::cout << "Executing the form..." << std::endl;
    form.execute(lowRank);
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

int main() {
  std::cout << "----------------------------------" << std::endl;
  testShrubberyCreationForm();
  std::cout << "----------------------------------" << std::endl;
  return 0;
}