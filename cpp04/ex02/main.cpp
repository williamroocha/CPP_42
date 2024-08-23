/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 15:40:22 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/23 19:10:57 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {

  const int arraySize = 4;
  AAnimal *animals[arraySize];

  // Create an array of animals with half Dog objects and half Cat objects
  for (int i = 0; i < arraySize / 2; ++i) {
    animals[i] = new Dog();
  }
  for (int i = arraySize / 2; i < arraySize; ++i) {
    animals[i] = new Cat();
  }

  std::cout << "\n=== Demonstrating Polymorphism ===" << std::endl;
  for (int i = 0; i < arraySize; ++i) {
    std::cout << "Animal " << i + 1 << " (" << animals[i]->getType() << "): ";
    animals[i]->makeSound();
  }

  std::cout << "\n=== Demonstrating Deep Copy for Dog ===" << std::endl;
  Dog dog1;
  dog1.getBrain()->setIdea(0, "Chase the ball");
  Dog dog2 = dog1;
  dog2.getBrain()->setIdea(0, "Chase the cat");
  std::cout << "🐶💭 : Dog1 Brain Idea: " << dog1.getBrain()->getIdea(0)
            << std::endl;
  std::cout << "🐶💭 : Dog2 Brain Idea: " << dog2.getBrain()->getIdea(0)
            << std::endl;

  std::cout << "\n=== Demonstrating Deep Copy for Cat ===" << std::endl;
  Cat cat1;
  cat1.getBrain()->setIdea(0, "Climb the tree");
  Cat cat2 = cat1;
  cat2.getBrain()->setIdea(0, "Catch the mouse");
  std::cout << "🐱💭 : Cat1 Brain Idea: " << cat1.getBrain()->getIdea(0)
            << std::endl;
  std::cout << "🐱💭 : Cat2 Brain Idea: " << cat2.getBrain()->getIdea(0)
            << std::endl;

  std::cout << "\n=== Deleting Animals ===" << std::endl;
  for (int i = 0; i < arraySize; ++i) {
    delete animals[i];
  }

  return 0;
}
