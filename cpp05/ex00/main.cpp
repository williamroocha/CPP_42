/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:23:44 by wiferrei          #+#    #+#             */
/*   Updated: 2024/10/21 15:24:41 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
  try {
    Bureaucrat failA("Test A", -1);
    std::cout << failA << std::endl;
  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cout << "Exception : " << e.what();
  }
  try {
    Bureaucrat failB("Fail B", 151);
    std::cout << failB << std::endl;
  } catch (Bureaucrat::GradeTooLowException &e) {
    std::cout << "Exception : " << e.what();
  }
  Bureaucrat a("Test A", 6);
  Bureaucrat b("Test B", 145);
  std::cout << "---------------Test A-------------" << std::endl;
  std::cout << a << std::endl;
  a.decrementGrade(5);
  std::cout << a << std::endl;
  a.decrementGrade(1);
  std::cout << a << std::endl;
  a.incrementGrade(10);
  std::cout << a << std::endl;
  a.incrementGrade(2);
  std::cout << a << std::endl;
  std::cout << "----------------------------------" << std::endl;
  std::cout << "---------------Test B-------------" << std::endl;
  std::cout << b << std::endl;
  b.incrementGrade(9);
  std::cout << b << std::endl;
  b.incrementGrade(1);
  b.decrementGrade(332);
  std::cout << b << std::endl;
  std::cout << "----------------------------------" << std::endl;
}
