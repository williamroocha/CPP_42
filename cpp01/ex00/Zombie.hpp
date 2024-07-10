/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:44:43 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/10 12:19:37 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
private:
  std::string _name;

public:
  Zombie(std::string name);
  ~Zombie();
  void announce() const;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
