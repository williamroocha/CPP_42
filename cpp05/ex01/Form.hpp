#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Form {
private:
  const std::string _name;
  bool _signed;
  const int _gradeToSign;
  const int _gradeToExecute;

public:
  Form();
  Form(const std::string &name, int gradeToSign, int gradeToExecute);
  Form(const Form &other);
  Form &operator=(const Form &other);
  ~Form();

  std::string getName() const;
  bool isSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(const Bureaucrat &Bureaucrat);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif