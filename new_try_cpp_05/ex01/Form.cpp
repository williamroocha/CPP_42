#include "Form.hpp"

Form::Form()
    : _name("DefaultForm"), _isSigned(false), _gradeRequired(150),
      _gradeToExecute(150) {
  std::cout << "Form Default Constructor Called." << std::endl;
}

Form::Form(std::string name, int gradeRequired, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeRequired(gradeRequired),
      _gradeToExecute(gradeToExecute) {
  std::cout << "Form Constructor Called" << std::endl;
  if (gradeRequired < 1 || gradeToExecute < 1)
    throw GradeTooHighException();
  if (gradeRequired > 150 || gradeToExecute > 150)
    throw GradeTooLowException();
}

Form::Form(const Form &copy)
    : _name(copy._name), _isSigned(copy._isSigned),
      _gradeRequired(copy._gradeRequired),
      _gradeToExecute(copy._gradeToExecute) {
  std::cout << "Form Copy Constructor Called." << std::endl;
}

Form &Form::operator=(const Form &copy) {
  std::cout << "Form Assignation Operator Called." << std::endl;
  if (this != &copy) {
    _isSigned = copy._isSigned;
  }
  return *this;
}

Form::~Form() { std::cout << "Form Destructor Called." << std::endl; }

std::string Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _isSigned; }
int Form::getGradeRequired() const { return _gradeRequired; }
int Form::getGradeToExecute() const { return _gradeToExecute; }

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() > _gradeRequired)
    throw GradeTooLowException();
  else
    _isSigned = true;
}

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade Too High.";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade Too Low.";
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "Form " << form.getName()
     << ", signed: " << (form.getIsSigned() ? "yes" : "no")
     << ", grade to sign: " << form.getGradeRequired()
     << ", grade to execute: " << form.getGradeToExecute();
  return os;
}
