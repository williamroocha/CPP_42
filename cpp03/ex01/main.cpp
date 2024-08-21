/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:08:22 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/21 12:06:27 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <sstream>

int main() {
  // Testing default constructor of ClapTrap
  std::cout << "=== Testing ClapTrap Default Constructor ===" << std::endl;
  ClapTrap defaultRobot;
  defaultRobot.attack("target");

  // Testing parameterized constructor of ClapTrap
  std::cout << "\n=== Testing ClapTrap Parameterized Constructor ==="
            << std::endl;
  ClapTrap robot1("Clappy");
  robot1.attack("target");
  robot1.takeDamage(3);
  robot1.beRepaired(5);

  // Testing copy constructor of ClapTrap
  std::cout << "\n=== Testing ClapTrap Copy Constructor ===" << std::endl;
  ClapTrap robot2(robot1);
  robot2.attack("target2");
  robot2.takeDamage(2);
  robot2.beRepaired(3);

  // Testing copy assignment operator of ClapTrap
  std::cout << "\n=== Testing ClapTrap Copy Assignment Operator ==="
            << std::endl;
  ClapTrap robot3("Clappy2");
  robot3 = robot1;
  robot3.attack("target3");

  // Testing ScavTrap default constructor
  std::cout << "\n=== Testing ScavTrap Default Constructor ===" << std::endl;
  ScavTrap scavDefault;
  scavDefault.attack("target");

  // Testing ScavTrap parameterized constructor
  std::cout << "\n=== Testing ScavTrap Parameterized Constructor ==="
            << std::endl;
  ScavTrap scav1("Scavy");
  scav1.attack("target");
  scav1.takeDamage(20);
  scav1.beRepaired(10);
  scav1.guardGate(); // ScavTrap's special function

  // Testing ScavTrap copy constructor
  std::cout << "\n=== Testing ScavTrap Copy Constructor ===" << std::endl;
  ScavTrap scav2(scav1);
  scav2.attack("target2");
  scav2.guardGate();

  // Testing ScavTrap copy assignment operator
  std::cout << "\n=== Testing ScavTrap Copy Assignment Operator ==="
            << std::endl;
  ScavTrap scav3("Scavy2");
  scav3 = scav1;
  scav3.attack("target3");

  // Test sequence of attack, takeDamage, beRepaired with ScavTrap
  std::cout << "\n=== Testing ScavTrap Attack, Take Damage, Repair Sequence ==="
            << std::endl;
  scav1.attack("target4");
  scav1.takeDamage(50);
  scav1.beRepaired(20);
  scav1.guardGate(); // Ensure it can still enter guard mode

  // Testing edge cases with ScavTrap
  std::cout << "\n=== Testing ScavTrap Edge Cases ===" << std::endl;
  scav1.takeDamage(100);   // Excessive damage
  scav1.attack("target5"); // Should not be able to attack
  scav1.beRepaired(50);    // Should not be able to repair

  // Testing energy depletion with ScavTrap
  std::cout << "\n=== Testing ScavTrap Energy Depletion ===" << std::endl;
  ScavTrap scav4("Scavy4");
  for (int i = 0; i < 50; i++) {
    std::stringstream ss;
    ss << i;
    scav4.attack("target" + ss.str());
  }
  scav4.attack("last target"); // Should not be able to attack due to no energy
  scav4.beRepaired(10);        // Should not be able to repair due to no energy

  // Testing destructor order by creating a new ScavTrap
  std::cout << "\n=== Testing Destructor Order with ScavTrap ===" << std::endl;
  ScavTrap scav5("Destructor Test");
  scav5.attack("target");

  return 0;
}
