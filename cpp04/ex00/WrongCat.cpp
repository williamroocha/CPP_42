/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:18:06 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/23 17:52:26 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  std::cout << "❌😺 : WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
  std::cout << "❌😺 : WrongCat type constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
  std::cout << "❌😺 : WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  std::cout << "❌😺 : WrongCat assignation operator called" << std::endl;
  if (this != &other)
    WrongAnimal::operator=(other);
  return *this;
}

WrongCat::~WrongCat() {
  std::cout << "❌😺 : WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const { std::cout << "🐈 Wrong Miau!" << std::endl; }