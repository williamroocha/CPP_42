#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    : AForm(copy), _target(copy._target) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
  if (this != &copy) {
    AForm::operator=(copy);
    _target = copy._target;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string ShrubberyCreationForm::getTarget() const { return _target; }

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!isSigned()) {
    throw FormNotSignedException();
  }
  if (executor.getGrade() > getGradeToExecute()) {
    throw GradeTooLowException();
  }

  std::ofstream ofs((getTarget() + "_shrubbery").c_str());
  if (!ofs) {
    throw std::invalid_argument("Error: could not open file for writing.");
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
