#ifndef CONTACT_H
# define CONTACT_H

# include <string>
# include <iostream>
# include <iomanip>

class Contact
{
	private:
        int			_index;
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
    public:
        Contact();
        ~Contact();

        void		set_index(int index);
		int			get_index(void) const;
		std::string	get_firstname(void) const;
		std::string	get_lastname(void) const;
		std::string	get_nickname(void) const;
		std::string	get_phonenumber(void) const;
		std::string	get_darkestsecret(void) const;
		void		init(int index);
		void		display(void) const;
		void		view(void) const;
};

#endif