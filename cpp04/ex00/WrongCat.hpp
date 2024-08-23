/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 17:17:20 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/23 17:24:29 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
  WrongCat();
  WrongCat(std::string type);
  WrongCat(const WrongCat &other);
  WrongCat &operator=(const WrongCat &other);
  virtual ~WrongCat();

  void makeSound() const;
};

#endif