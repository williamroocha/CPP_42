#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("default_target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : AForm(copy), _target(copy._target) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
  if (this != &copy) {
    AForm::operator=(copy);
    _target = copy._target;
  }
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

std::string RobotomyRequestForm::getTarget() const { return _target; }

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!isSigned()) {
    throw FormNotSignedException();
  }
  if (executor.getGrade() > getGradeToExecute()) {
    throw GradeTooLowException();
  }

  srand(time(NULL));
  if (rand() % 2) {
    std::cout << "Drilling noises... " << getTarget()
              << " has been robotomized successfully." << std::endl;
  } else {
    std::cout << "Drilling noises... " << getTarget()
              << " has failed to be robotomized." << std::endl;
  }
}
