#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void testShrubberyCreationForm(int signGrade, int execGrade) {
  std::cout << "Testing ShrubberyCreationForm with Bureaucrat signing grade: "
            << signGrade << " and execution grade: " << execGrade << std::endl;
  try {
    Bureaucrat bobSign("BobSign", signGrade);
    Bureaucrat bobExec("BobExec", execGrade);
    ShrubberyCreationForm form("home");

    std::cout << "Signing the form with BobSign grade " << signGrade << "..."
              << std::endl;
    form.beSigned(bobSign);

    std::cout << "Executing the form with BobExec grade " << execGrade << "..."
              << std::endl;
    form.execute(bobExec);

    std::cout << "Shrubbery file created successfully!" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

void testRobotomyRequestForm(int signGrade, int execGrade) {
  std::cout << "Testing RobotomyRequestForm with Bureaucrat signing grade: "
            << signGrade << " and execution grade: " << execGrade << std::endl;
  try {
    Bureaucrat bobSign("BobSign", signGrade);
    Bureaucrat bobExec("BobExec", execGrade);
    RobotomyRequestForm form("target");

    std::cout << "Signing the form with BobSign grade " << signGrade << "..."
              << std::endl;
    form.beSigned(bobSign);

    std::cout << "Executing the form with BobExec grade " << execGrade << "..."
              << std::endl;
    form.execute(bobExec);

    std::cout << "Robotomy request executed successfully!" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

void testPresidentialPardonForm(int signGrade, int execGrade) {
  std::cout << "Testing PresidentialPardonForm with Bureaucrat signing grade: "
            << signGrade << " and execution grade: " << execGrade << std::endl;
  try {
    Bureaucrat bobSign("BobSign", signGrade);
    Bureaucrat bobExec("BobExec", execGrade);
    PresidentialPardonForm form("target");

    std::cout << "Signing the form with BobSign grade " << signGrade << "..."
              << std::endl;
    form.beSigned(bobSign);

    std::cout << "Executing the form with BobExec grade " << execGrade << "..."
              << std::endl;
    form.execute(bobExec);

    std::cout << "Presidential pardon executed successfully!" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

// int main() {
//   std::cout << "----------------------------------" << std::endl;

//   std::cout << "Testing ShrubberyCreationForm..." << std::endl;
//   // Valid signing grade, valid execution grade
//   testShrubberyCreationForm(140, 130);
//   // Valid signing grade, insufficient execution grade
//   testShrubberyCreationForm(140, 140);
//   // Insufficient signing and execution grade
//   testShrubberyCreationForm(150, 150);
//   // Valid execution grade, insufficient signing grade
//   testShrubberyCreationForm(130, 150);

//   std::cout << "----------------------------------" << std::endl;

//   std::cout << "Testing RobotomyRequestForm..." << std::endl;
//   // Valid signing grade, valid execution grade
//   testRobotomyRequestForm(70, 40);
//   // Valid signing grade, insufficient execution grade
//   testRobotomyRequestForm(70, 50);
//   // Insufficient signing and execution grade
//   testRobotomyRequestForm(80, 50);
//   // Valid execution grade, insufficient signing grade
//   testRobotomyRequestForm(80, 40);

//   std::cout << "----------------------------------" << std::endl;

//   std::cout << "Testing PresidentialPardonForm..." << std::endl;
//   // Valid signing grade, valid execution grade
//   testPresidentialPardonForm(20, 10);
//   // Valid signing grade, insufficient execution grade
//   testPresidentialPardonForm(20, 20);
//   // Insufficient signing and execution grade
//   testPresidentialPardonForm(30, 30);
//   // Valid execution grade, insufficient signing grade
//   testPresidentialPardonForm(10, 30);

//   std::cout << "----------------------------------" << std::endl;

//   return 0;
// }

int main() {
  try {
    // Create forms with specific targets
    ShrubberyCreationForm shrubberyForm("home");
    RobotomyRequestForm robotomyForm("target");
    PresidentialPardonForm pardonForm("target");

    // Create a Bureaucrat with a high enough grade to sign and execute the forms
    Bureaucrat highRankBureaucrat("HighRank", 3);

    // Display the forms
    std::cout << shrubberyForm;
    std::cout << robotomyForm;
    std::cout << pardonForm;

    // Sign the forms
    highRankBureaucrat.signForm(shrubberyForm);
    highRankBureaucrat.signForm(robotomyForm);
    highRankBureaucrat.signForm(pardonForm);

    // Execute the forms
    highRankBureaucrat.executeForm(shrubberyForm);
    highRankBureaucrat.executeForm(robotomyForm);
    highRankBureaucrat.executeForm(pardonForm);
  } catch (const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }

  return 0;
}