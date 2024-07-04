/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:49:49 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/04 16:45:54 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
  public:
	Contact(void);
	~Contact(void);
	void SetFirstName(const std::string &FirstName);
	void SetLastName(const std::string &LastName);
	void SetNickName(const std::string &NickName);
	void SetPhoneNumber(const std::string &PhoneNumber);
	void SetDarkestSecret(const std::string &DarkestSecret);

	std::string GetFirstName() const;
	std::string GetLastName() const;
	std::string GetNickName() const;
	std::string GetPhoneNumber() const;
	std::string GetDarkestSecret() const;

  private:
	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string PhoneNumber;
	std::string DarkestSecret;
};

#endif