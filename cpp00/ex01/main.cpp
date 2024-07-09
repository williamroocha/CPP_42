/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:50:54 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/09 15:24:34 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBookIncludes.hpp"

int	main(void)
{
	PhoneBook	PhoneBook;

	std::string Command;
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, Command);
		if (std::cin.eof())
		{
			std::cin.clear();
			std::cout << "Invalid Command! Exiting..." << std::endl;
			break ;
		}
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
