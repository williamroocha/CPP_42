/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:22:03 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/21 13:41:03 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
  std::cout << "FragTrap " << this->_name << " is created" << std::endl;
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  std::cout << "FragTrap " << this->_name << " is created" << std::endl;
  this->_hitPoints = 100;
  this->_energyPoints = 100;
  this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  *this = other;
  std::cout << "FragTrap " << this->_name << " is created" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  if (this != &other) {
    ClapTrap::operator=(other);
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
  }
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << this->_name << " is destroyed" << std::endl;
}

void FragTrap::highFivesGuys() {
  std::cout << "FragTrap " << this->_name << " requests a high five!"
            << std::endl;
}
