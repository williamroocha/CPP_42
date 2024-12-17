#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(100) {
  std::cout << "Bureaucrat Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {

  std::cout << "Bureaucrat constructor called" << std::endl;

  if (grade < 1)
    throw GradeTooHighException();
  else if (grade > 150)
    throw GradeTooLowException();
  else
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
  std::cout << "Bureaucrat copy constructor called" << std::endl;
  *this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy) {
  std::cout << "Bureaucrat assignation operator called" << std::endl;
  if (this != &copy)
    this->_grade = copy._grade;
  return (*this);
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat destructor called" << std::endl;
}

int Bureaucrat::getGrade() const { return (_grade); }

std::string Bureaucrat::getName() const { return (_name); }

void Bureaucrat::incrementGrade(int grade) {
  if (_grade - grade < 1)
    throw GradeTooHighException();
  else
    _grade -= grade;
}

void Bureaucrat::decrementGrade(int grade) {
  if (_grade + grade > 150)
    throw GradeTooLowException();
  else
    _grade += grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade is too high.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade is too low.");
}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &bureaucrat) {
  output << bureaucrat.getName() << ", bureaucrat grade "
         << bureaucrat.getGrade() << std::endl;
  return (output);
}