#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>

class Bureaucrat {
private:
  std::string _name;
  int _grade;

public:
  Bureaucrat();
  Bureaucrat(std::string name, int grade);
  
  Bureaucrat(const Bureaucrat &copy);
  Bureaucrat &operator=(const Bureaucrat &copy);
  ~Bureaucrat();

  int getGrade() const;
  std::string getName() const;
  void incrementGrade(int grade);
  void decrementGrade(int grade);

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &bureaucrat);

#endif