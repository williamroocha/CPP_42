#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form {
private:
  const std::string _name;
  bool _isSigned;
  int _gradeRequired;
  int _gradeToExecute;

public:
  Form();
  Form(std::string name, int gradeRequired, int gradeToExecute);
  Form(const Form &copy);
  Form &operator=(const Form &copy);
  ~Form();

  std::string getName() const;
  bool getIsSigned() const;
  int getGradeRequired() const;
  int getGradeToExecute() const;

  void beSigned(const Bureaucrat &bureaucrat);

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &output, const Form &form);

#endif