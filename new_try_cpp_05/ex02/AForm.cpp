#include "AForm.hpp"

AForm::AForm()
    : _name("DefaultAFom"), _isSigned(false), _gradeRequired(150),
      _gradeToExecute(150) {
  std::cout << "AForm Default Constructor Called." << std::endl;
}

AForm::AForm(std::string name, int gradeRequired, int gradeToExecute){ : _name(name)

};