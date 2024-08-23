/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 18:03:43 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/23 18:08:28 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
  std::cout << "🧠 : Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
  std::cout << "🧠 : Brain copy constructor called" << std::endl;
  *this = other;
}

Brain &Brain::operator=(const Brain &other) {
  std::cout << "🧠 : Brain assignation operator called" << std::endl;
  if (this != &other) {
    for (int i = 0; i < 100; i++)
      ideas[i] = other.ideas[i];
  }
  return *this;
}

Brain::~Brain() { std::cout << "🧠 : Brain destructor called" << std::endl; }

void Brain::setIdea(int index, std::string idea) {
  if (index >= 0 && index < 100) {
    ideas[index] = idea;
  }
}

std::string Brain::getIdea(int index) const {
  if (index >= 0 && index < 100) {
    return ideas[index];
  }
  return "🚫💭 : No idea";
}
