/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:12:56 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/09 16:34:43 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _value(0) {
  std::cout << "Default constructor called" << std::endl;
}

// Constructor that takes an integer
Fixed::Fixed(int const intValue) {
  std::cout << "Int constructor called" << std::endl;
  this->_value = intValue << __fractionalBits; // Convert integer to fixed-point
}

// Constructor that takes a floating-point number
Fixed::Fixed(float const floatValue) {
  std::cout << "Float constructor called" << std::endl;
  this->_value = roundf(floatValue *
                        (1 << __fractionalBits)); // Convert float to fixed-point
}

// Copy constructor
Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other; // Use the copy assignment operator
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->_value = other.getRawBits();
  }
  return *this;
}

// Destructor
Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

// Get the raw value of the fixed-point number
int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->_value;
}

// Set the raw value of the fixed-point number
void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->_value = raw;
}

// Convert the fixed-point value to a floating-point number
float Fixed::toFloat(void) const {
  return static_cast<float>(this->_value) / (1 << __fractionalBits);
}

// Convert the fixed-point value to an integer
int Fixed::toInt(void) const {
  return this->_value >> __fractionalBits; // Convert fixed-point to integer
}

// Overload of the insertion (<<) operator for outputting the Fixed class
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat(); // Output the floating-point representation
  return out;
}
