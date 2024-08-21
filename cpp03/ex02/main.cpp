/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:08:22 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/21 13:43:39 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
  // Testing ClapTrap
  std::cout << "=== Testing ClapTrap ===" << std::endl;
  ClapTrap clappy("Clappy");
  clappy.attack("target");
  clappy.takeDamage(5);
  clappy.beRepaired(3);

  // Testing ScavTrap
  std::cout << "\n=== Testing ScavTrap ===" << std::endl;
  ScavTrap scavvy("Scavvy");
  scavvy.attack("target");
  scavvy.takeDamage(15);
  scavvy.beRepaired(10);
  scavvy.guardGate();

  // Testing FragTrap default constructor
  std::cout << "\n=== Testing FragTrap Default Constructor ===" << std::endl;
  FragTrap fragDefault;
  fragDefault.attack("target");

  // Testing FragTrap parameterized constructor
  std::cout << "\n=== Testing FragTrap Parameterized Constructor ==="
            << std::endl;
  FragTrap fraggy("Fraggy");
  fraggy.attack("target");
  fraggy.takeDamage(20);
  fraggy.beRepaired(15);
  fraggy.highFivesGuys();

  // Testing FragTrap copy constructor
  std::cout << "\n=== Testing FragTrap Copy Constructor ===" << std::endl;
  FragTrap fraggyCopy(fraggy);
  fraggyCopy.attack("target2");
  fraggyCopy.highFivesGuys();

  // Testing FragTrap copy assignment operator
  std::cout << "\n=== Testing FragTrap Copy Assignment Operator ==="
            << std::endl;
  FragTrap anotherFrag("AnotherFraggy");
  anotherFrag = fraggy;
  anotherFrag.attack("target3");

  // Destructor order testing
  std::cout << "\n=== Destructor Order Test ===" << std::endl;
  FragTrap fraggyDestructor("DestructorTest");

  return 0;
}
