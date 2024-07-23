/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:47:19 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/23 08:45:47 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FileReplacer.hpp"

int main(int ac, char **av) {
  if (ac == 4 && std::string(av[1]).size() && std::string(av[2]).size() &&
      std::string(av[3]).size()) {

    std::string file = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    FileReplacer fr(file, s1, s2);
    fr.replace();

  } else
    std::cout << "🚨 Invalid number of arguments!!" << std::endl;

  return (0);
}
