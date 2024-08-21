/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 11:06:52 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/21 13:24:40 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
  std::cout << "ScavTrap " << this->_name << " is created" << std::endl;
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  std::cout << "ScavTrap " << this->_name << " is created" << std::endl;
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 20;
} 

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
  std::cout << "ScavTrap " << this->_name << " is created" << std::endl;
  *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
  std::cout << "ScavTrap " << this->_name << " is created" << std::endl;
  if (this != &other) {
    ClapTrap::operator=(other);
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
  }
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap " << this->_name << " is destroyed" << std::endl;
}

void ScavTrap::attack(std::string const &target) {
  if (this->_hitPoints > 0 && this->_energyPoints > 0) {
    this->_energyPoints--;
    std::cout << "ScavTrap " << this->_name << " attacks " << target
              << ", causing " << this->_attackDamage << " points of damage!"
              << std::endl;
  } else
    std::cout << "ScavTrap " << this->_name
              << " cannot attack due to insufficient energy or hitpoints!"
              << std::endl;
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode"
            << std::endl;
}