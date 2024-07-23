/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:33:55 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/23 10:21:58 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << YELLOW << "Usage: ./harl [DEBUG/INFO/WARNING/ERROR]" << RST
              << std::endl;
    return 1;
  }
  Harl harl;
  harl.complain(av[1]);
  return 0;
}
