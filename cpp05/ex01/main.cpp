#include "Bureaucrat.hpp"
#include "Form.hpp"

void testForm(const std::string &name, int gradeRequired, int gradeToExecute) {
  try {
    std::cout << "Testing Form creation with name \"" << name
              << "\", grade required " << gradeRequired
              << ", and grade to execute " << gradeToExecute << "..."
              << std::endl;
    Form form(name, gradeRequired, gradeToExecute);
    std::cout << "Created: " << form << std::endl;

    std::cout << "Attempting to sign form with grade 1..." << std::endl;
    Bureaucrat bureaucrat("Bureaucrat", 1);
    form.beSigned(bureaucrat);
    std::cout << "After signing: " << form << std::endl;

    std::cout << "Attempting to sign form with grade 150..." << std::endl;
    Bureaucrat bureaucrat2("Bureaucrat2", 150);
    form.beSigned(bureaucrat2);
    std::cout << "After signing: " << form << std::endl;

    std::cout << "Attempting to sign form with grade 151..." << std::endl;
    Bureaucrat bureaucrat3("Bureaucrat3", 151);
    form.beSigned(bureaucrat3);
    std::cout << "After signing: " << form << std::endl;
  } catch (std::exception &e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }
  std::cout << "-----------------------------------------" << std::endl;
}

int main() {
  testForm("Form1", 1, 1);
  testForm("Form2", 150, 150);
  testForm("Form3", 151, 151);
  testForm("Form4", 0, 0);
  testForm("Form5", 1, 150);
  return (0);
}
