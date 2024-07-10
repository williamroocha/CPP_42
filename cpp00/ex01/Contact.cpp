/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:49:56 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/10 14:38:37 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookIncludes.hpp"

// Constructor and Destructor:

Contact::Contact(void) {}

Contact::~Contact(void) {}

// Setters and Getters:

void Contact::SetFirstName(const std::string &FirstName) {
  this->_firstName = FirstName;
}
void Contact::SetLastName(const std::string &LastName) {
  this->_lastName = LastName;
}

void Contact::SetNickName(const std::string &NickName) {
  this->_nickName = NickName;
}

void Contact::SetPhoneNumber(const std::string &PhoneNumber) {
  this->_phoneNumber = PhoneNumber;
}

void Contact::SetDarkestSecret(const std::string &DarkestSecret) {
  this->_darkestSecret = DarkestSecret;
}

std::string Contact::GetFirstName() const { return (this->_firstName); }

std::string Contact::GetLastName() const { return (this->_lastName); }

std::string Contact::GetNickName() const { return (this->_nickName); }

std::string Contact::GetPhoneNumber() const { return (this->_phoneNumber); }

std::string Contact::GetDarkestSecret() const { return (this->_darkestSecret); }

// Truncate Functions:

std::string Contact::truncFirstName() const {
  return (_truncateString(this->_firstName));
}
std::string Contact::truncLastName() const {
  return (_truncateString(this->_lastName));
}
std::string Contact::truncNickName() const {
  return (_truncateString(this->_nickName));
}

std::string Contact::_truncateString(const std::string &str) const {
  if (str.length() > 10) {
    return (str.substr(0, 9) + ".");
  }
  return (str);
}
