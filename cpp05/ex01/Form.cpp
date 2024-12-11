#include "Form.hpp"

// Default constructor
Form::Form()
    : _name("Default"), _signed(false), _gradeToSign(1), _gradeToExecute(1) {}

// Parameterized constructor
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign),
      _gradeToExecute(gradeToExecute) {
  if (gradeToSign < 1 || gradeToExecute < 1)
    throw GradeTooHighException();
  if (gradeToSign > 150 || gradeToExecute > 150)
    throw GradeTooLowException();
}

// Copy constructor
Form::Form(const Form &other)
    : _name(other._name), _signed(other._signed),
      _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

// Copy assignment operator
// Note: _name, _gradeToSign, and _gradeToExecute cannot be reassigned
Form &Form::operator=(const Form &other) {
  if (this != &other) {
    _signed = other._signed;
  }
  return *this;
}

// Destructor
Form::~Form() {}

// Getters
std::string Form::getName() const { return _name; }
bool Form::isSigned() const { return _signed; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

// Sign function
void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > _gradeToSign)
    throw GradeTooLowException();
  _signed = true;
}

// Exception classes
const char *Form::GradeTooHighException::what() const throw() {
  return "Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade too low!";
}

// Operator overload
std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "Form " << form.getName()
     << ", signed: " << (form.isSigned() ? "yes" : "no")
     << ", grade to sign: " << form.getGradeToSign()
     << ", grade to execute: " << form.getGradeToExecute();
  return os;
}
