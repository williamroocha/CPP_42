#include "AForm.hpp"

AForm::AForm()
    : _name("DefaultAFom"), _isSigned(false), _gradeRequired(150),
      _gradeToExecute(150) {
  std::cout << "AForm Default Constructor Called." << std::endl;
}

AForm::AForm(std::string name, int gradeRequired, int gradeToExecute)
    : _name(name), _gradeRequired(gradeRequired),
      _gradeToExecute(gradeToExecute) {
  std::cout << "Aform Constructor Called." << std::endl;
  if (gradeRequired < 1 || gradeToExecute < 1)
    throw GradeTooHighException();
  if (gradeRequired > 150 || gradeToExecute > 150)
    throw GradeTooLowException();
};

AForm::AForm(const AForm &copy)
    : _name(copy._name), _isSigned(copy._isSigned),
      _gradeRequired(copy._gradeRequired),
      _gradeToExecute(copy._gradeToExecute) {
  std::cout << "AForm Copy Constructor Called" << std::endl;
}

AForm &AForm::operator=(const AForm &copy) {
  std::cout << "AForm Assignation Operator Called." << std::endl;
  if (this != &copy)
    _isSigned = copy._isSigned;
  return *this;
}

AForm::~AForm() { std::cout << "AForm Destructor Called" << std::endl; }

std::string AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return _gradeRequired; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() <= _gradeRequired)
    _isSigned = true;
  else
    throw GradeTooLowException();
}

void AForm::checkRequirements(Bureaucrat const &executor) const {
  if (!_isSigned)
    throw FormNotSignedException();
  if (executor.getGrade() <= _gradeToExecute)
    execute();
  else
    throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &output, const AForm &Aform) {
  output << "The name the form is " << Aform.getName() << std::endl;
  output << "The grade to signe is " << Aform.getGradeToSign() << std::endl;
  output << "The grade to execute is " << Aform.getGradeToExecute()
         << std::endl;
  return (output);
}