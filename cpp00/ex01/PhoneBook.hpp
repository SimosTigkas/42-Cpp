/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:18:58 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/24 12:18:04 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include "Contact.hpp"
# include <cstdlib>
# include <limits>

class PhoneBook
{
	private:
		Contact	_contacts[8];
	public:
		PhoneBook();
		~PhoneBook();

		void	add_contact(void);
		void	search_contact(void) const;
		int		display_contacts(void) const;
};

#endif
