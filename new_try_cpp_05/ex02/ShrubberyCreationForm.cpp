#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default_target") {}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

// Copy assignment operator
ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
  if (this != &other) {
    AForm::operator=(other);
    _target = other._target;
  }
  return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Get target
std::string ShrubberyCreationForm::getTarget() const { return _target; }

// Execute method
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  // Perform necessary checks to ensure executor has the proper grade
  if (!isSigned()) {
    throw FormNotSignedException();
  }
  if (executor.getGrade() > getGradeToExecute()) {
    throw GradeTooLowException();
  }

  // Execute the form's logic, e.g., create a file
  std::ofstream ofs((getTarget() + "_shrubbery").c_str());
  if (!ofs) {
    throw std::runtime_error("Error: could not open file for writing.");
  }

  ofs << "       _-_\n"
      << "    /~~   ~~\\\n"
      << " /~~         ~~\\\n"
      << "{               }\n"
      << " \\  _-     -_  /\n"
      << "   ~  \\\\ //  ~\n"
      << " _- -   | | _- _\n"
      << "   _ -  | |   -_\n"
      << "       // \\\\\n";
  ofs.close();
}
