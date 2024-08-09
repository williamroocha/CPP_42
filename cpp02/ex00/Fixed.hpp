/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:47:43 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/09 15:50:43 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
  int _value;
  static const int _fractionalBits = 8;

public:
  Fixed();
  Fixed(const Fixed &src);
  ~Fixed();

  Fixed &operator=(const Fixed &src);

  int getRawBits(void) const;
  void setRawBits(int const raw);
};

#endif