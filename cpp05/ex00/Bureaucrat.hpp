/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:00:25 by wiferrei          #+#    #+#             */
/*   Updated: 2024/10/22 15:30:26 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdlib.h>

class Bureaucrat {
private:
  const std::string _name;
  int _grade;

public:
  Bureaucrat();
  Bureaucrat(int grade);
  Bureaucrat(std::string name, int grade);
  Bureaucrat(Bureaucrat &copy);
  Bureaucrat &operator=(Bureaucrat const &copy);
  ~Bureaucrat();

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw();
  };
  
  void incrementGrade(int amount);
  void decrementGrade(int amount);
  int getGrade() const;
  std::string getName() const;
};


std::ostream &operator<<(std::ostream &os, Bureaucrat const &bureaucrat);

#endif
