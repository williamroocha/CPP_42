/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:32:48 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/09 16:36:35 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
private:
  int _value;
  static const int _fractionalBits = 8;

public:
  // Constructors and Destructor
  Fixed();
  Fixed(int const intValue);
  Fixed(float const floatValue);
  Fixed(const Fixed &other);
  ~Fixed();

  // Assignment operator
  Fixed &operator=(const Fixed &other);

  // Comparison operators
  bool operator>(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;

  // Arithmetic operators
  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;

  // Increment/Decrement operators
  Fixed &operator++();   // Pre-increment
  Fixed operator++(int); // Post-increment
  Fixed &operator--();   // Pre-decrement
  Fixed operator--(int); // Post-decrement

  // Conversion functions
  int toInt(void) const;
  float toFloat(void) const;

  // Raw value access
  int getRawBits(void) const;
  void setRawBits(int const raw);

  // Static member functions for min and max
  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);
};

// Overload of the insertion (<<) operator for outputting the Fixed class
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
