#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5), _target("default_target") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &copy)
    : AForm(copy), _target(copy._target) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
  if (this != &copy) {
    AForm::operator=(copy);
    _target = copy._target;
  }
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

std::string PresidentialPardonForm::getTarget() const { return _target; }

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (!isSigned()) {
    throw FormNotSignedException();
  }
  if (executor.getGrade() > getGradeToExecute()) {
    throw GradeTooLowException();
  }

  std::cout << getTarget() << " has been pardoned by Zafod Beeblebrox."
            << std::endl;
}
