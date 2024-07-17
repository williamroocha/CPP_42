/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:10:08 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/17 10:12:46 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
  if (N <= 0)
    return (NULL);

  Zombie *zombieHorde = new Zombie[N];
  for (int i = 0; i < N; i++)
    zombieHorde[i].setName(name);

  return (zombieHorde);
}