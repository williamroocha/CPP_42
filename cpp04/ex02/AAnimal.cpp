/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:57:28 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/23 19:00:21 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal") {
  std::cout << "🅰️🐾 : AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type) {
  std::cout << "🅰️🐾 : AAnimal type constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : type(other.type) {
  std::cout << "🅰️🐾 : AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other) {
  std::cout << "🅰️🐾 : AAnimal assignation operator called" << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}

AAnimal::~AAnimal() {
  std::cout << "🅰️🐾 : AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const { return type; }
