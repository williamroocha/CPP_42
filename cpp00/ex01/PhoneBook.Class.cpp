/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.Class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:47:58 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/05 18:41:45 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.Class.hpp"
#include <iomanip>

PhoneBook::PhoneBook() : _ContactsNbr(0)
{
	std::cout << "PhoneBook constructor called!!!" << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructor called!!!" << std::endl;
	return ;
}

void PhoneBook::AddContact()
{
	if (_ContactsNbr == 8)
	{
		std::cout << "PhoneBook is Full. Replacing the oldest contact" << std::endl;
		std::cout << "I NEED IMPLEMNET THIS PART OF THE CODE" << std::endl;
	}
	Contact &Contact = _Contacts[_ContactsNbr];
	std::string input;
	std::cout << "Enter the first name: ";
	std::getline(std::cin, input);
	Contact.SetFirstName(input);
	std::cout << "Enter the last name: ";
	std::getline(std::cin, input);
	Contact.SetLastName(input);
	std::cout << "Enter the nickname: ";
	std::getline(std::cin, input);
	Contact.SetNickName(input);
	std::cout << "Enter the phone number: ";
	std::getline(std::cin, input);
	Contact.SetPhoneNumber(input);
	std::cout << "Enter the darkest secret: ";
	std::getline(std::cin, input);
	Contact.SetDarkestSecret(input);
	_ContactsNbr++;
}

void PhoneBook::DisplayHeader() const
{
	std::cout << std::setw(10) << std::right << "Index" << " |";
	std::cout << std::setw(10) << std::right << "First Name" << " |";
	std::cout << std::setw(10) << std::right << "Last Name" << " |";
	std::cout << std::setw(10) << std::right << "Nick Name" << " |" << std::endl;
}

void PhoneBook::DisplayContact(int index) const
{
    Contact Contact = _Contacts[index];
    std::cout << std::setw(10) << std::right << index << " |";
    std::cout << std::setw(10) << std::right << Contact.TruncFirstName() << " |";
    std::cout << std::setw(10) << std::right << Contact.TruncLastName() << " |";
    std::cout << std::setw(10) << std::right << Contact.TruncNickName() << " |" << std::endl;
}

void PhoneBook::SearchContact() const
{
	if (_ContactsNbr == 0)
	{
		std::cout << "The PhoneBook is empty!!!!" << std::endl;
		return ;
	}
	DisplayHeader();
	for (int i = 0; i < _ContactsNbr; i++)
		DisplayContact(i);

}