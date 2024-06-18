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
