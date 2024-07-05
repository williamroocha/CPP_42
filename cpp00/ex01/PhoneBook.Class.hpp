/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.Class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:48:49 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/05 18:21:11 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.Class.hpp"
# include <iomanip>
# include <iostream>
# include <string.h>

class PhoneBook
{
  public:
	PhoneBook(void);
	~PhoneBook(void);

	void AddContact(void);
	void SearchContact() const;
	void DisplayHeader() const;
	void DisplayContact(int index) const;

private:
	Contact _Contacts[8];
	int _ContactsNbr;
};

#endif
