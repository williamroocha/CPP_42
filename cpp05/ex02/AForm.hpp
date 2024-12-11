#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class AForm {
private:
  const std::string _name;
  bool _isSigned;
  const int _gradeToSign;
  const int _gradeToExecute;

public:
  AForm();
  AForm(const std::string &name, int gradeToSign, int gradeToExecute);
  AForm(const AForm &other);
  AForm &operator=(const AForm &other);
  virtual ~AForm();

  std::string getName() const;
  bool isSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(const Bureaucrat &bureaucrat);
  virtual void
  execute(Bureaucrat const &executor) const = 0;

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
