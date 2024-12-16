#include "PresidentialPardonForm.hpp"

// Default constructor
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("default_target") {}

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &other)
    : AForm(other), _target(other._target) {}

// Copy assignment operator
PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    _target = other._target;
  }
  return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Overridden execute method
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (!isSigned())
    throw std::runtime_error("Form is not signed!");
  if (executor.getGrade() > getGradeToExecute())
    throw GradeTooLowException();

  std::cout << _target << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
