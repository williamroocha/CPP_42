#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() { std::cout << "Intern default constructor" << std::endl; }

Intern::Intern(const Intern &copy) {
  std::cout << "Intern copy constructor" << std::endl;
  (void)copy; // Suppress unused parameter warning
}

Intern::~Intern() { std::cout << "Intern destructor" << std::endl; }

Intern &Intern::operator=(const Intern &copy) {
  std::cout << "Intern assignation operator" << std::endl;
  (void)copy;
  return *this;
}

AForm *createShrubberyCreationForm(const std::string &target) {
  return new ShrubberyCreationForm(target);
}

AForm *createRobotomyRequestForm(const std::string &target) {
  return new RobotomyRequestForm(target);
}

AForm *createPresidentialPardonForm(const std::string &target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &formTarget) {
  typedef AForm *(*FormCreator)(const std::string &);
  struct FormEntry {
    const char *name;
    FormCreator creator;
  };

  FormEntry formEntries[] = {
      {"ShrubberyCreationForm", createShrubberyCreationForm},
      {"RobotomyRequestForm", createRobotomyRequestForm},
      {"PresidentialPardonForm", createPresidentialPardonForm}};

  for (int i = 0; i < 3; ++i) {
    if (formEntries[i].name == formName) {
      std::cout << "Intern creates " << formName << std::endl;
      return formEntries[i].creator(formTarget);
    }
  }

  std::cout << "Error: No form found" << std::endl;
  return NULL;
}