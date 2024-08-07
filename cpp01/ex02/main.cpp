/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:44:15 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/17 12:12:04 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << "Address of the string: " << &str << std::endl;
  std::cout << "Address of the stringPTR: " << stringPTR << std::endl;
  std::cout << "Address of the stringREF: " << &stringREF << std::endl;

  std::cout << "String: " << str << std::endl;
  std::cout << "StringPTR: " << *stringPTR << std::endl;
  std::cout << "StringREF: " << stringREF << std::endl;

  return (0);
}
