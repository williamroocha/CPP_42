/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:50:54 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/05 18:40:44 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.Class.hpp"
#include "PhoneBook.Class.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;

	std::string Command;
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, Command);
		if (Command == "ADD")
			PhoneBook.AddContact();
		else if (Command == "SEARCH")
			PhoneBook.SearchContact();
		else if (Command == "EXIT")
			break ;
		else
			std::cout << "Invalid Command!!" << std::endl;
	}
	return (0);
}
