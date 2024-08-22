/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:39:10 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/22 17:01:55 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
  std::cout << "Cat type constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat assignation operator called" << std::endl;
  if (this != &other)
    Animal::operator=(other);
  return *this;
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

void Cat::makeSound() const { std::cout << "Meow!" << std::endl; }
