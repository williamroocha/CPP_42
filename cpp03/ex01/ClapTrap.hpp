/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:30:55 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/18 17:20:41 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <sstream>

class ClapTrap {
private:
  std::string _name;
  int _hitpoints;
  int _energy_points;
  int _attack_damage;

public:
  ClapTrap();
  ClapTrap(std::string name);
  ClapTrap(const ClapTrap &other);
  ClapTrap &operator=(const ClapTrap &other);
  ~ClapTrap();

  void attack(std::string const &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};

#endif