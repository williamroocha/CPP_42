/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:30:49 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/22 15:39:54 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap()
    : _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap default constructor called" << std::endl;
}

// Parameterized constructor
ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap name constructor called" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other) {
  std::cout << "ClapTrap copy constructor called" << std::endl;
  *this = other;
}

// Copy assignment operator
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
  std::cout << "ClapTrap assignation operator called" << std::endl;
  if (this != &other) {
    _name = other._name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
  }
  return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap destructor called" << std::endl;
}

// Member functions
void ClapTrap::attack(std::string const &target) {
  if (_hitPoints > 0 && _energyPoints > 0) {
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
              << _attackDamage << " points of damage!" << std::endl;
  } else {
    std::cout << "ClapTrap " << _name
              << " cannot attack due to insufficient energy or hitpoints!"
              << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  _hitPoints -= amount;
  if (_hitPoints < 0)
    _hitPoints = 0;
  std::cout << "ClapTrap " << _name << " takes " << amount
            << " points of damage, now has " << _hitPoints << " hitpoints!"
            << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_hitPoints > 0 && _energyPoints > 0) {
    _energyPoints--;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _name << " is repaired for " << amount
              << " hitpoints, now has " << _hitPoints << " hitpoints!"
              << std::endl;
  } else {
    std::cout << "ClapTrap " << _name
              << " cannot be repaired due to insufficient energy or hitpoints!"
              << std::endl;
  }
}
