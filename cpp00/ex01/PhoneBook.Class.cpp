/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.Class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:47:58 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/04 19:36:20 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.Class.hpp"

PhoneBook::PhoneBook() : index(0)
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
	if (index == 8)
	{
		std::cout << "PhoneBook is Full. Replacing the oldest contact" << std::endl;
		std::cout << "I NEED IMPLEMNET THIS PART OF THE CODE" << std::endl;
	}

	Contact &Contact = Contacts[index];

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

	index++;
}