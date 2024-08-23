/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:15:33 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/23 17:49:50 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
  std::cout << "❌🐾 : WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
  std::cout << "❌🐾 : WrongAnimal type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {
  std::cout << "❌🐾 : WrongAnimal copy constructor called" << std::endl ;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  std::cout << "❌🐾 : WrongAnimal assignation operator called" << std::endl;
  if (this != &other)
    type = other.type;
  return *this;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "❌🐾 : WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
  std::cout << "❌🐾 : Some wrong animal sound" << std::endl;
}
