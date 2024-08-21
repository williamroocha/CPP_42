/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:30:49 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/18 17:12:14 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap()
    : _name("Unnamed"), _hitpoints(10), _energy_points(10), _attack_damage(0) {
  std::cout << "ClapTrap default constructor called" << std::endl;
}

// Parameterized constructor
ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitpoints(10), _energy_points(10), _attack_damage(0) {
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
    _hitpoints = other._hitpoints;
    _energy_points = other._energy_points;
    _attack_damage = other._attack_damage;
  }
  return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap destructor called" << std::endl;
}

// Member functions
void ClapTrap::attack(std::string const &target) {
  if (_hitpoints > 0 && _energy_points > 0) {
    _energy_points--;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
              << _attack_damage << " points of damage!" << std::endl;
  } else {
    std::cout << "ClapTrap " << _name
              << " cannot attack due to insufficient energy or hitpoints!"
              << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  _hitpoints -= amount;
  if (_hitpoints < 0)
    _hitpoints = 0;
  std::cout << "ClapTrap " << _name << " takes " << amount
            << " points of damage, now has " << _hitpoints << " hitpoints!"
            << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_hitpoints > 0 && _energy_points > 0) {
    _energy_points--;
    _hitpoints += amount;
    std::cout << "ClapTrap " << _name << " is repaired for " << amount
              << " hitpoints, now has " << _hitpoints << " hitpoints!"
              << std::endl;
  } else {
    std::cout << "ClapTrap " << _name
              << " cannot be repaired due to insufficient energy or hitpoints!"
              << std::endl;
  }
}
