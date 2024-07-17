/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:10:03 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/17 10:29:09 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <cstdlib>
#include <iostream>
#include <string>

class Zombie {
private:
  std::string _name;

public:
  Zombie();
  ~Zombie();
  void announce() const;
  void setName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif