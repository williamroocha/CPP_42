#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <string>

class PresidentialPardonForm : public AForm {
private:
  std::string _target;

public:
  PresidentialPardonForm();
  PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm &copy);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
  ~PresidentialPardonForm();

  void execute(Bureaucrat const &executor) const;
  std::string getTarget() const;
};

#endif