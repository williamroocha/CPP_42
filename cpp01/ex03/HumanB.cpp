/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:11:01 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/17 15:21:49 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _name(name), _weapon(NULL) {}

void HumanB::setWeapon(Weapon &weapon) { this->_weapon = &weapon; }

void HumanB::attack() const {
  if (this->_weapon)
    std::cout << this->_name << " attacks with their "
              << this->_weapon->getType() << std::endl;
  else
    std::cout << this->_name << " has no weapon to attack with" << std::endl;
}
