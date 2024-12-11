#include "Bureaucrat.hpp"
#include "Form.hpp"

// Test invalid Form creation
void testInvalidForm() {
  try {
    std::cout << "Trying a high exception" << std::endl;
    Form invalidForm("InvalidForm", 0, 10);
  } catch (const Form::GradeTooHighException &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  try {
    std::cout << "Trying a high exception" << std::endl;
    Form invalidForm("InvalidForm", 151, 10);
  } catch (const Form::GradeTooLowException &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

// Test valid Form creation and signing
void testValidForm() {
  try {
    Bureaucrat b("John", 50);
    Form validForm("ValidForm", 100, 50);

    std::cout << "Trying a valid form" << std::endl;

    std::cout << "Before signing: " << validForm << std::endl;
    validForm.beSigned(b);
    std::cout << "After signing: " << validForm << std::endl;
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

// Test Form signing with insufficient grade
void testFormSigningFailure() {
  try {
    Bureaucrat lowRankBureaucrat("LowRank", 120);
    Form highLevelForm("HighLevelForm", 50, 50);

    std::cout << "Trying to sign form with insufficient grade:" << std::endl;
    highLevelForm.beSigned(lowRankBureaucrat);
  } catch (const std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
}

int main() {
  std::cout << "Testing Form class:" << std::endl;
  std::cout << "----------------------------------" << std::endl;
  testInvalidForm();
  std::cout << "----------------------------------" << std::endl;
  testValidForm();
  std::cout << "----------------------------------" << std::endl;
  testFormSigningFailure();

  return 0;
}