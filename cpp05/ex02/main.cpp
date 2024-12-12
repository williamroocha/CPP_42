#include "Bureaucrat.hpp"
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
    Bureaucrat aliceSign("AliceSign", signGrade);
    Bureaucrat aliceExec("AliceExec", execGrade);
    RobotomyRequestForm form("TargetX");

    std::cout << "Signing the form with AliceSign grade " << signGrade << "..."
              << std::endl;
    form.beSigned(aliceSign);

    std::cout << "Executing the form with AliceExec grade " << execGrade
              << "..." << std::endl;
    form.execute(aliceExec);

    std::cout << "Robotomy executed successfully!" << std::endl;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

int main() {
  std::cout << "----------------------------------" << std::endl;
  std::cout << "Testing ShrubberyCreationForm..." << std::endl;
  // Valid signing grade, valid execution grade
  testShrubberyCreationForm(140, 130);
  // Valid signing grade, insufficient execution grade
  testShrubberyCreationForm(140, 140);
  // Insufficient signing and execution grade
  testShrubberyCreationForm(150, 150);
  // Valid execution grade, insufficient signing grade
  testShrubberyCreationForm(130, 150);

  std::cout << "----------------------------------" << std::endl;
  std::cout << "Testing RobotomyRequestForm..." << std::endl;
  // Valid signing grade, valid execution grade
  testRobotomyRequestForm(70, 40);
  // Valid signing grade, insufficient execution grade
  testRobotomyRequestForm(70, 50);
  // Insufficient signing and execution grade
  testRobotomyRequestForm(150, 150);
  // Valid execution grade, insufficient signing grade
  testRobotomyRequestForm(40, 150);

  std::cout << "----------------------------------" << std::endl;
  return 0;
}
