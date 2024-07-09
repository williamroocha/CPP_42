/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.Class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:49:49 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/09 14:21:24 by wiferrei         ###   ########.fr       */
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

	std::string TruncFirstName() const;
	std::string TruncLastName() const;
	std::string TruncNickName() const;

  private:
	std::string _FirstName;
	std::string _LastName;
	std::string _NickName;
	std::string _PhoneNumber;
	std::string _DarkestSecret;

	std::string _TruncateString(const std::string &str) const;
};

#endif