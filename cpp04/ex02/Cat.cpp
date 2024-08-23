/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:39:10 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/23 19:09:59 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat"), brain(new Brain()) {
  std::cout << "😺 : Cat default constructor called" << std::endl;
}

Cat::Cat(std::string type) : AAnimal(type), brain(new Brain()) {
  std::cout << "😺 : Cat type constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other) {
  std::cout << "😺 : Cat copy constructor called" << std::endl;
  brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "😺 : Cat assignation operator called" << std::endl;
  if (this != &other) {
    AAnimal::operator=(other);
    delete brain;
    brain = new Brain(*other.brain);
  }
  return *this;
}

Cat::~Cat() {
  std::cout << "😺 : Cat destructor called" << std::endl;
  delete brain;
}

Brain *Cat::getBrain() const { return brain; }

void Cat::makeSound() const { std::cout << "🐈 Miau!" << std::endl; }