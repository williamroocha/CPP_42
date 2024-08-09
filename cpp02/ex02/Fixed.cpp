/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:31:44 by wiferrei          #+#    #+#             */
/*   Updated: 2024/08/09 16:36:52 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _value(0) {}

// Constructor that takes an integer
Fixed::Fixed(int const intValue) { this->_value = intValue << _fractionalBits; }

// Constructor that takes a floating-point number
Fixed::Fixed(float const floatValue) {
  this->_value = roundf(floatValue * (1 << _fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed &other) { *this = other; }

// Destructor
Fixed::~Fixed() {}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
  if (this != &other) {
    this->_value = other.getRawBits();
  }
  return *this;
}

// Comparison operators
bool Fixed::operator>(const Fixed &other) const {
  return this->_value > other._value;
}

bool Fixed::operator<(const Fixed &other) const {
  return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const {
  return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const {
  return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const {
  return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const {
  return this->_value != other._value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
  return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
  return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
  return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
  return Fixed(this->toFloat() / other.toFloat());
}

// Increment/Decrement operators
Fixed &Fixed::operator++() {
  this->_value++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp = *this;
  this->_value++;
  return temp;
}

Fixed &Fixed::operator--() {
  this->_value--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp = *this;
  this->_value--;
  return temp;
}

// Conversion functions
int Fixed::toInt(void) const { return this->_value >> _fractionalBits; }

float Fixed::toFloat(void) const {
  return static_cast<float>(this->_value) / (1 << _fractionalBits);
}

// Raw value access
int Fixed::getRawBits(void) const { return this->_value; }

void Fixed::setRawBits(int const raw) { this->_value = raw; }

// Static member functions for min and max
Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return (a > b) ? a : b;
}

// Overload of the insertion (<<) operator for outputting the Fixed class
std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}
