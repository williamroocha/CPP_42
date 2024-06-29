/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:53:16 by wiferrei          #+#    #+#             */
/*   Updated: 2024/06/29 18:56:58 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	if (ac <= 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; ++i)
	{
		for (int j = 0; av[i][j]; ++j)
		{
			std::cout << (char)std::toupper(av[i][j]);
		}
	}
	std::cout << std::endl;
	return (0);
}
