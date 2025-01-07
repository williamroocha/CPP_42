#include "Bureaucrat.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "RobotomyRequestForm.hpp"
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

/* oid testRobotomyRequestForm(int signGrade, int execGrade) {
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

 void testPresidentialPardonForm(int signGrade, int execGrade) {
   std::cout << "Testing PresidentialPardonForm with Bureaucrat signing grade: "
             << signGrade << " and execution grade: " << execGrade << std::endl;

   try {
     Bureaucrat signer("Signer", signGrade);
     Bureaucrat executor("Executor", execGrade);
     PresidentialPardonForm form("TargetP");

     std::cout << "Signing the form with Signer grade " << signGrade << "..."
               << std::endl;
     form.beSigned(signer);

     std::cout << "Executing the form with Executor grade " << execGrade <<
 "..."
               << std::endl;
     form.execute(executor);

   } catch (const std::exception &e) {
     std::cerr << "Error: " << e.what() << std::endl;
   }
 } */

    int
    main() {
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

  return 0;
}