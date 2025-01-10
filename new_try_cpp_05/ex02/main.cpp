#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
  try {
    ShrubberyCreationForm shrubberyForm("home");
    RobotomyRequestForm robotomyForm("target");
    PresidentialPardonForm pardonForm("target");

    Bureaucrat highRankBureaucrat("HighRank", 3);

    std::cout << shrubberyForm;
    std::cout << robotomyForm;
    std::cout << pardonForm;

    highRankBureaucrat.signForm(shrubberyForm);
    highRankBureaucrat.signForm(robotomyForm);
    highRankBureaucrat.signForm(pardonForm);

    highRankBureaucrat.executeForm(shrubberyForm);
    highRankBureaucrat.executeForm(robotomyForm);
    highRankBureaucrat.executeForm(pardonForm);
  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}