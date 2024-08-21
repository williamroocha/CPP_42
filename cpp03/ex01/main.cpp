/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 17:08:22 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/18 17:22:45 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {

  // Testing default constructor
  std::cout << "=== Testing Default Constructor ===" << std::endl;
  ClapTrap defaultRobot;
  defaultRobot.attack("target");

  // Testing parameterized constructor
  std::cout << "\n=== Testing Parameterized Constructor ===" << std::endl;
  ClapTrap robot1("Robot1");
  robot1.attack("target");
  robot1.takeDamage(3);
  robot1.beRepaired(5);

  // Testing copy constructor
  std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
  ClapTrap robot2(robot1);
  robot2.attack("target2");
  robot2.takeDamage(2);
  robot2.beRepaired(3);

  // Testing copy assignment operator
  std::cout << "\n=== Testing Copy Assignment Operator ===" << std::endl;
  ClapTrap robot3("Robot3");
  robot3 = robot1;
  robot3.attack("target3");

  // Test sequence of attack, takeDamage and beRepaired
  std::cout << "\n=== Testing Attack, Take Damage and Repair Sequence ==="
            << std::endl;
  robot1.attack("target4");
  robot1.takeDamage(9);
  robot1.beRepaired(5);

  // Testing edge cases
  std::cout << "\n=== Testing Edge Cases ===" << std::endl;
  robot1.takeDamage(100);   // Damage exceeds hitpoints
  robot1.attack("target5"); // Robot should not be able to attack
  robot1.beRepaired(10);    // Robot should not be able to repair

  // Testing energy depletion
  std::cout << "\n=== Testing Energy Depletion ===" << std::endl;
  ClapTrap robot4("Robot4");
  for (int i = 0; i < 10; i++) {
    std::stringstream ss;
    ss << i;
    robot4.attack("target" + ss.str());
  }
  robot4.attack(
      "last target");   // Should not be able to attack due to lack of energy
  robot4.beRepaired(5); // Should not be able to repair due to lack of energy

  // Testing with another new ClapTrap
  std::cout << "\n=== Testing Another New ClapTrap ===" << std::endl;
  ClapTrap robot5("Robot5");
  robot5.takeDamage(
      15); // Takes more damage than available hitpoints, should not go negative

  return 0;
}
