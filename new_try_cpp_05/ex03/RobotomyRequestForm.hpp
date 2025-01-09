#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>

class RobotomyRequestForm : public AForm {
private:
  std::string _target;

public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &copy);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
  ~RobotomyRequestForm();

  void execute(Bureaucrat const &executor) const;
  std::string getTarget() const;
};

#endif