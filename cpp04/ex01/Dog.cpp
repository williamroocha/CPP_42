/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:26:47 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/23 18:12:23 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain()) {
  std::cout << "🐶 : Dog default constructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type), brain(new Brain()) {
  std::cout << "🐶 : Dog type constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "🐶 : Dog copy constructor called" << std::endl;
  brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "🐶 : Dog assignation operator called" << std::endl;
  if (this != &other) {
    Animal::operator=(other);
    delete brain;
    brain = new Brain(*other.brain);
  }
  return *this;
}

Dog::~Dog() {
  std::cout << "🐶 : Dog destructor called" << std::endl;
  delete brain;
}

void Dog::makeSound() const { std::cout << "🐶 : Au Au!" << std::endl; }

Brain *Dog::getBrain() const { return brain; }
