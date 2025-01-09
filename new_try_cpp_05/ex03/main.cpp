#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  try {
    Intern intern;
    AForm *form;

    // Test creating ShrubberyCreationForm
    form = intern.makeForm("ShrubberyCreationForm", "home");
    if (form) {
      std::cout << *form << std::endl;
      delete form;
    }

    // Test creating RobotomyRequestForm
    form = intern.makeForm("RobotomyRequestForm", "target");
    if (form) {
      std::cout << *form << std::endl;
      delete form;
    }

    // Test creating PresidentialPardonForm
    form = intern.makeForm("PresidentialPardonForm", "target");
    if (form) {
      std::cout << *form << std::endl;
      delete form;
    }

    // Test creating an unknown form
    form = intern.makeForm("UnknownForm", "target");
    if (form) {
      std::cout << *form << std::endl;
      delete form;
    }
  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}

