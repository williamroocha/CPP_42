/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:49:49 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/10 14:38:37 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "PhoneBookIncludes.hpp"

class Contact {
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

  std::string truncFirstName() const;
  std::string truncLastName() const;
  std::string truncNickName() const;

private:
  std::string _firstName;
  std::string _lastName;
  std::string _nickName;
  std::string _phoneNumber;
  std::string _darkestSecret;

  std::string _truncateString(const std::string &str) const;
};

#endif
