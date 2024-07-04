/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.Class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiferrei <wiferrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 08:48:49 by wiferrei          #+#    #+#             */
/*   Updated: 2024/07/04 17:05:04 by wiferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

# include "Contact.Class.hpp"

class PhoneBook
{
  public:
	PhoneBook(void);
	~PhoneBook(void);

	void AddContact(void);
	void SearcContact(void);

  private:
	Contact Contacts[8];
	int index;
};

#endif
