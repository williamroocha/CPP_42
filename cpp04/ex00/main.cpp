/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:40:22 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/23 17:37:58 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  std::cout << "=== Testing Animal, Cat, and Dog with Virtual Functions ==="
            << std::endl;

  Animal *animal = new Animal();
  Animal *cat = new Cat();
  Animal *dog = new Dog();

  std::cout << "Animal sound: ";
  animal->makeSound();

  std::cout << "Cat sound (via Animal pointer): ";
  cat->makeSound();

  std::cout << "Dog sound (via Animal pointer): ";
  dog->makeSound();

  delete animal;
  delete cat;
  delete dog;

  std::cout
      << "\n=== Testing WrongAnimal and WrongCat without Virtual Functions ==="
      << std::endl;

  WrongAnimal *wrongAnimal = new WrongAnimal();
  WrongAnimal *wrongCat = new WrongCat();

  std::cout << "wrongAnimal sound: ";
  wrongAnimal->makeSound();

  std::cout << "WrongCat sound (via WrongAnimal pointer): ";
  wrongCat->makeSound();

  delete wrongAnimal;
  delete wrongCat;

  std::cout << "\n=== Testing Direct Instances of Cat and Dog ===" << std::endl;

  Cat directCat;
  Dog directDog;

  std::cout << "Direct Cat sound: ";
  directCat.makeSound();

  std::cout << "Direct Dog sound: ";
  directDog.makeSound();

  std::cout << "\n=== Testing Polymorphism with WrongCat ===" << std::endl;

  WrongCat directWrongCat;

  std::cout << "Direct WrongCat sound: ";
  directWrongCat.makeSound();

  WrongAnimal wrongAnimalInstance = directWrongCat;
  std::cout << "WrongAnimal (from WrongCat) sound: ";
  wrongAnimalInstance.makeSound();

  return 0;
}
