/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.Class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:49:56 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/04 16:56:19 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.Class.hpp"

Contact::Contact(void)
{
	std::cout << "Contact constructor called!!!" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called!!!" << std::endl;
	return ;
}

void Contact::SetFirstName(const std::string &FirstName)
{
	this->FirstName = FirstName;
}
void Contact::SetLastName(const std::string &LastName)
{
	this->LastName = LastName;
}

void Contact::SetNickName(const std::string &NickName)
{
	this->NickName = NickName;
}

void Contact::SetPhoneNumber(const std::string &PhoneNumber)
{
	this->PhoneNumber = PhoneNumber;
}

void Contact::SetDarkestSecret(const std::string &DarkestSecret)
{
	this->DarkestSecret = DarkestSecret;
}

std::string Contact::GetFirstName() const
{
	return (this->FirstName);
}

std::string Contact::GetLastName() const
{
	return (this->LastName);
}

std::string Contact::GetNickName() const
{
	return (this->NickName);
}

std::string Contact::GetPhoneNumber() const
{
	return (this->PhoneNumber);
}

std::string Contact::GetDarkestSecret() const
{
	return(this->DarkestSecret);
}