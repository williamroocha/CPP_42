#include "AForm.hpp"

// Default constructor
AForm::AForm()
    : _name("Default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1) {}

// Parameterized constructor
AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw GradeTooHighException();
  if (gradeToSign > 150 || gradeToExecute > 150)
    throw GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm &other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

// Copy assignment operator
// Only non-const attributes can be assigned
AForm &AForm::operator=(const AForm &other) {
  if (this != &other) {
    _isSigned = other._isSigned;
  }
  return *this;
}

// Virtual destructor
AForm::~AForm() {}

// Getters
std::string AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

// Sign function
void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > _gradeToSign)
    throw GradeTooLowException();
  _isSigned = true;
}

// Exception classes
const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade too low!";
}

// Operator overload
std::ostream &operator<<(std::ostream &os, const AForm &form) {
  os << "Form " << form.getName()
     << ", signed: " << (form.isSigned() ? "yes" : "no")
     << ", grade to sign: " << form.getGradeToSign()
     << ", grade to execute: " << form.getGradeToExecute();
  return os;
}
