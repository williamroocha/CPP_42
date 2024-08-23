/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:47:48 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/23 17:44:54 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
  std::cout << "🏗️🐾 : Animal default constructor called." << std::endl;
}

Animal::Animal(std::string type) : type(type) {
  std::cout << "🏗️🐾 : Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
  std::cout << "🏗️🐾 : Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
  std::cout << "🏗️🐾 : Animal assignation operator called" << std::endl;
  if (this != &other) {
    type = other.type;
  }
  return *this;
}

Animal::~Animal() { std::cout << "🏗️🐾 : Animal destructor called" << std::endl; }

void Animal::makeSound() const {
  std::cout << "🐾 : Some animal sound" << std::endl;
}

std::string Animal::getType() const { return type; }
