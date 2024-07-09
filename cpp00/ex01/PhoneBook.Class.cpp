/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.Class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:47:58 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/09 13:15:11 by wiferrei         ###   ########.fr       */
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

bool PhoneBook::AllFieldsComplete(const Contact &Contact) const
{
	if (Contact.GetFirstName().empty() || Contact.GetLastName().empty()
		|| Contact.GetNickName().empty() || Contact.GetPhoneNumber().empty()
		|| Contact.GetDarkestSecret().empty())
		return (false);
	else
		return (true);
}

bool PhoneBook::ValidPhoneNumber(const Contact &Contact) const
{
	std::string PhoneNumber = Contact.GetPhoneNumber();

	for (std::string::size_type i = 0; i < PhoneNumber.length(); i++)
	{
		if (!isdigit(PhoneNumber[i]))
			return (false);
	}
	return (true);
}

void PhoneBook::AddContact()
{
	Contact	Contact;

	if (_ContactsNbr == 8)
	{
		std::cout << "PhoneBook is Full. Replacing the oldest contact" << std::endl;
		for (int i = 0; i < 7; i++)
		{
			_Contacts[i] = _Contacts[i + 1];
		}
		_ContactsNbr = 7;
	}
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
	if (!AllFieldsComplete(Contact))
	{
		std::cout << "All fields must be filled!!" << std::endl;
		return ;
	}
	if (!ValidPhoneNumber(Contact))
	{
		std::cout << "Invalid phone number!!" << std::endl;
		return ;
	}
	_Contacts[_ContactsNbr++] = Contact;
}

void PhoneBook::DisplayHeader() const
{
	std::cout << std::setw(10) << std::right << "Index"
				<< " |";
	std::cout << std::setw(10) << std::right << "First Name"
				<< " |";
	std::cout << std::setw(10) << std::right << "Last Name"
				<< " |";
	std::cout << std::setw(10) << std::right << "Nick Name"
				<< " |" << std::endl;
}

void PhoneBook::DisplayContactTable() const
{
	DisplayHeader();
	for (int i = 0; i < _ContactsNbr; i++)
	{
		Contact Contact = _Contacts[i];
		std::cout << std::setw(10) << std::right << i << " |";
		std::cout << std::setw(10) << std::right << Contact.TruncFirstName() << " |";
		std::cout << std::setw(10) << std::right << Contact.TruncLastName() << " |";
		std::cout << std::setw(10) << std::right << Contact.TruncNickName() << " |" << std::endl;
	}
}

void PhoneBook::DisplayFullContact() const
{
	std::string Input;
	std::cout << "Enter the contact index: ";
	std::getline(std::cin, Input);

	int Id = -1;
	if (Input.length() == 1 && isdigit(Input[0]))
		Id = Input[0] - '0';
	if (Id < 0 || Id > 7)
	{
		std::cout << "Invalid index!!" << std::endl;
		return ;
	}
	if (Id >= _ContactsNbr)
	{
		std::cout << "Contact not filled yet!!" << std::endl;
		return ;
	}

	Contact Contact = _Contacts[Id];
	std::cout << "First name: " << Contact.GetFirstName() << std::endl;
	std::cout << "Last name: " << Contact.GetLastName() << std::endl;
	std::cout << "Nick name: " << Contact.GetNickName() << std::endl;
	std::cout << "Phone number: " << Contact.GetPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << Contact.GetDarkestSecret() << std::endl;
}

void PhoneBook::SearchContact() const
{
	if (_ContactsNbr == 0)
	{
		std::cout << "The PhoneBook is empty!!!!" << std::endl;
		return ;
	}
	DisplayContactTable();
	DisplayFullContact();
}
