/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:38:38 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/23 18:13:48 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
  Brain *brain;

public:
  Cat();
  Cat(std::string type);
  Cat(const Cat &other);
  Cat &operator=(const Cat &other);
  virtual ~Cat();

  virtual void makeSound() const;
  Brain *getBrain() const;
};

#endif