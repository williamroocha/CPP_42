/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 09:09:53 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/17 10:45:08 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av) {
  if (ac == 3) {

    int N = atoi(av[1]);
    Zombie *horde = zombieHorde(N, av[2]);

    if (!horde)
      return (0);

    for (int i = 0; i < N; i++) {
      horde[i].announce();
    }

    delete[] horde;
    return (0);
  }
}
