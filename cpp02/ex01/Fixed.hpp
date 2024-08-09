/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:11:40 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/09 16:25:44 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
private:
  int _value;                           // Stores the fixed-point number value
  static const int _fractionalBits = 8; // Number of fractional bits

public:
  // Default constructor
  Fixed();

  // Constructor that takes an integer
  Fixed(int const intValue);

  // Constructor that takes a floating-point number
  Fixed(float const floatValue);

  // Copy constructor
  Fixed(const Fixed &other);

  // Copy assignment operator
  Fixed &operator=(const Fixed &other);

  // Destructor
  ~Fixed();

  // Get the raw value of the fixed-point number
  int getRawBits(void) const;

  // Set the raw value of the fixed-point number
  void setRawBits(int const raw);

  // Convert the fixed-point value to a floating-point number
  float toFloat(void) const;

  // Convert the fixed-point value to an integer
  int toInt(void) const;
};

// Overload of the insertion (<<) operator for outputting the Fixed class
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
