/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:38:38 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/22 16:45:11 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
  Cat();
  Cat(std::string type);
  Cat(const Cat &other);
  Cat &operator=(const Cat &other);
  virtual ~Cat();

  virtual void makeSound() const override;
};

#endif