/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:34:40 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/23 11:47:41 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::debug(void) {
  std::cout << BLUE << "[ DEBUG ]" << RST << std::endl;
  std::cout
      << "I love having extra bacon for my "
         "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
      << std::endl;
}

void Harl::info(void) {
  std::cout << GREEN << "[ INFO ]" << RST << std::endl;
  std::cout
      << "I cannot believe adding extra bacon costs more money. You didn’t put "
         "enough bacon in my burger! If you did, I wouldn’t be asking for more!"
      << std::endl;
}

void Harl::warning(void) {
  std::cout << YELLOW << "[ WARNING ]" << RST << std::endl;
  std::cout
      << "I think I deserve to have some extra bacon for free. I’ve been "
         "coming for years whereas you started working here since last month."
      << std::endl;
}

void Harl::error(void) {
  std::cout << RED << "[ ERROR ]" << RST << std::endl;
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}

void Harl::other(void) {
  std::cout << "[ Probably complaining about insignificant problems ]."
            << std::endl;
}

void Harl::complain(std::string level) {

  std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  int i;

  for (i = 0; i < 4; i++)
    if (level == levels[i])
      break;

  switch (i) {
  case 0:
    debug();
    // fall through
  case 1:
    info();
    // fall through
  case 2:
    warning();
    // fall through
  case 3:
    error();
    break;
  default:
    other();
  }
}
