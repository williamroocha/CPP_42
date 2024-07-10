/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:44:37 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/10 12:39:37 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) { this->_name = name; }

Zombie::~Zombie() { std::cout << this->_name << " is destroyed!" << std::endl; }

void Zombie::announce() const {
  std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
