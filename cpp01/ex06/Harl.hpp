/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 09:34:45 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/23 11:06:48 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

#define RST "\033[0m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define RED "\033[31m"

class Harl {
private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
  void other(void);

public:
  Harl(void);
  ~Harl(void);
  void complain(std::string level);
};

#endif