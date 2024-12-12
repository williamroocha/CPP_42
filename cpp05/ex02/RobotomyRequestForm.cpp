#include "RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("default_target") {}

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

// Copy contructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target) {}

// Copy assignement operator
RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    _target = other._target;
  }
  return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  // Validate execution permissions
  if (!isSigned())
    throw std::runtime_error("Form is not signed!");
  if (executor.getGrade() > getGradeToExecute())
    throw GradeTooLowException();

  // Make drilling noises
  std::cout << "BRRRRZZZZZ... drilling noises... BRRRRZZZZZ..." << std::endl;

  // Seed the random number generator (only once)
  static bool seeded = false;
  if (!seeded) {
    std::srand(std::time(0)); // Use current time as seed
    seeded = true;
  }

  // Simulate a 50% success rate
  if (std::rand() % 2 == 0) {
    std::cout << _target << " has been robotomized successfully!" << std::endl;
  } else {
    std::cout << "Robotomy of " << _target << " has failed!" << std::endl;
  }
}