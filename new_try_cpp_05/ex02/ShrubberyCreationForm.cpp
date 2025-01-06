#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("DefaultShrubberyCreationForm", 145, 137) {
  std::cout << "ShrubberyCreationForm Default Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ParaShuForm", 145, 137) {
  target = _target;
  std::cout << "ShrubberyCreationForm Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(
    const ShrubberyCreationForm &copy) {
  *this = copy;
}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
  if (this != &copy) {
    AForm::operator=(copy);
    _target = copy._target;
  }
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
  std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget() const { return _target; }

void ShrubberyCreationForm::execute() const {
  std::string fileName;

  fileName = _target + "_shrubbery.txt";

  std::fstream file(fileName.c_str(), std::ios::out);

  if (file.is_open()) {
    file << tree << std::endl;
    file.close();
  } else
    std::cerr << "Error creating the file." << std::endl;
}