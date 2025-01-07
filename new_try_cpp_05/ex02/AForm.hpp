#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
private:
  const std::string _name;
  bool _isSigned;
  int _gradeRequired;
  int _gradeToExecute;

public:
  AForm();
  AForm(const std::string name, int gradeRequired, int gradeToExecute);
  AForm(const AForm &copy);
  AForm &operator=(const AForm &copy);
  virtual ~AForm();

  std::string getName() const;
  bool isSigned() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;

  void beSigned(const Bureaucrat &bureaucrat);
  virtual void
  execute(Bureaucrat const &executor) const = 0; // Correct signature
  void checkRequirements(Bureaucrat const &executor) const;

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
    // virtual ~GradeTooHighException(){};
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
    // virtual ~GradeTooLowException(){};
  };

  class FormNotSignedException : public std::exception {
  public:
    virtual const char *what() const throw();
    // virtual ~FormNotSignedException (){}
  };
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif