/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:49:56 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/05 18:40:36 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.Class.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void Contact::SetFirstName(const std::string &FirstName)
{
	this->_FirstName = FirstName;
}
void Contact::SetLastName(const std::string &LastName)
{
	this->_LastName = LastName;
}

void Contact::SetNickName(const std::string &NickName)
{
	this->_NickName = NickName;
}

void Contact::SetPhoneNumber(const std::string &PhoneNumber)
{
	this->_PhoneNumber = PhoneNumber;
}

void Contact::SetDarkestSecret(const std::string &DarkestSecret)
{
	this->_DarkestSecret = DarkestSecret;
}

std::string Contact::GetFirstName() const
{
	return (this->_FirstName);
}

std::string Contact::GetLastName() const
{
	return (this->_LastName);
}

std::string Contact::GetNickName() const
{
	return (this->_NickName);
}

std::string Contact::GetPhoneNumber() const
{
	return (this->_PhoneNumber);
}

std::string Contact::GetDarkestSecret() const
{
	return (this->_DarkestSecret);
}

std::string Contact::TruncFirstName() const
{
	std::string FirstName = this->_FirstName;

	if (FirstName.length() > 10)
	{
		FirstName.resize(9);
		FirstName += ".";
	}
	return (FirstName);
}

std::string Contact::TruncLastName() const
{
	std::string LastName = this->_LastName;

	if (LastName.length() > 10)
	{
		LastName.resize(9);
		LastName += ".";
	}
	return (LastName);
}

std::string Contact::TruncNickName() const
{
	std::string NickName = this->_NickName;

	if (NickName.length() > 10)
	{
		NickName.resize(9);
		NickName += ".";
	}
	return (NickName);
}
