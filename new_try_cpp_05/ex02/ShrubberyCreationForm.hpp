#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

#define tree                                                                   \
  " \n\
            ^ \n\
           ^^^ \n\
          ^^^^^ \n\
         ^^^^^^^ \n\
        ^^^^^^^^^ \n\
       ^^^^^^^^^^^ \n\
      ^^^^^^^^^^^^^ \n\
     ^^^^^^^^^^^^^^^ \n\
    ^^^^^^^^^^^^^^^^^ \n\
          ||||| \n\
          ||||| \n\
          ||||| \n\
          ||||| \n\
"

class ShrubberyCreationForm : public AForm {
private:
  std::string _target;

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm &copy);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
  ~ShrubberyCreationForm();

  std::string getTarget() const;
  void execute() const;
};

#endif