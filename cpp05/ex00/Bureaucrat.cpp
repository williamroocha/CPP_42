#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(100) {}

Bureaucrat::Bureaucrat(int grade) : _name("Default") {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  else {
    std::cout << "Bureaucrat grade constructor called" << std::endl;
    _grade = grade;
  }
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  else {
    std::cout << "Bureaucrat name constructor called" << std::endl;
    _grade = grade;
  }
}

Bureaucrat::Bureaucrat(Bureaucrat &copy) {
  std::cout << "Bureaucrat copy constructor called" << std::endl;
  *this = copy;
}

Bureaucrat::~Bureaucrat() {
  std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &copy) {
  std::cout << "Bureaucrat assignation operator called" << std::endl;
  if (this != &copy) {
    _grade = copy._grade;
  }
  return (*this);
}

void Bureaucrat::incrementGrade(int amount) {
  try {
    if ((_grade - amount) < 1)
      throw Bureaucrat::GradeTooHighException();
    else
      _grade -= amount;
  } catch (GradeTooHighException &e) {
    std::cout << e.what();
  }
}

void Bureaucrat::decrementGrade(int amount) {
  try {
    if ((_grade + amount) > 150)
      throw Bureaucrat::GradeTooLowException();
    else
      _grade += amount;
  } catch (GradeTooLowException &e) {
    std::cout << e.what();
  }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade, " << bureaucrat.getGrade();
  return os;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return ("Grade Too High\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return ("Grade Too Low\n");
}

int Bureaucrat::getGrade() const { return (_grade); }

std::string Bureaucrat::getName() const { return (_name); }