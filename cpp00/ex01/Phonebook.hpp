/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 12:18:58 by stigkas           #+#    #+#             */
/*   Updated: 2024/06/19 12:18:59 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include "Contact.hpp"


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
