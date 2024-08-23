/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:27:08 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/23 17:02:49 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
  Dog();
  Dog(std::string type);
  Dog(const Dog &other);
  Dog &operator=(const Dog &other);
  virtual ~Dog();

  virtual void makeSound() const;
};

#endif