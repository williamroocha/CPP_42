#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  try {
    ShrubberyCreationForm treeForm("tree");
    // RobotomyRequestForm robotForm("robot");
    // PresidentialPardonForm presidentialForm("pardon");
    // Bureaucrat vip("President", 3);
    // std::cout << treeForm;
    // std::cout << robotForm;
    // std::cout << presidentialForm;
    // vip.signForm(presidentialForm);
    // vip.signForm(treeForm);
    // vip.executeForm(presidentialForm);
    // vip.executeForm(treeForm);
    // vip.executeForm(robotForm);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
