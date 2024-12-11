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

// Execute method
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  // Validate execution permissions
  if (!isSigned())
    throw GradeTooLowException();
  if (executor.getGrade() > getGradeToExecute())
    throw GradeTooLowException();

  // Create the file
  std::ofstream outfile((_target + "_shrubbery").c_str());
  if (!outfile.is_open()) {
    throw std::ios_base::failure("Failed to create file");
  }

  // Write ASCII trees
  outfile << "      /\\      \n";
  outfile << "     /\\*\\     \n";
  outfile << "    /\\O\\*\\    \n";
  outfile << "   /*/\\/\\/\\   \n";
  outfile << "  /\\O\\/\\*\\/\\  \n";
  outfile << " /\\*\\/\\*\\/\\/\\ \n";
  outfile << "/\\O\\/\\/*/\\/O/\\\n";
  outfile << "      ||      \n";
  outfile << "      ||      \n";
  outfile << "      ||      \n";

  outfile.close();
}