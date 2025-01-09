#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

class Intern {
public:
  Intern();
  Intern(const Intern &copy);
  ~Intern();
  Intern &operator=(const Intern &copy);

  AForm *makeForm(const std::string &formName, const std::string &formTarget);
};

#endif