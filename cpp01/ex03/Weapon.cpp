/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:26:17 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/17 14:50:44 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : _type(type) {}

const std::string &Weapon::getType() const { return (this->_type); }

void Weapon::setType(const std::string &type) { this->_type = type; }