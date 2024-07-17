/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:47:19 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/17 16:29:13 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av) {
  (void)av; // remove this line
  if (ac == 4) {
    // do something
  } else
    std::cout << "🚨 Invalid number of arguments!!" << std::endl;
}