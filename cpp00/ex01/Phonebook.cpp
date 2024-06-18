#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	int	i = 0;
	while (i < 8)
	{
		this->_contacts[i].set_index(-1);
		i++;
	}
}

PhoneBook::~PhoneBook()
{
    // std::cout << "There is no contact in this Phonebook!" << std::endl;
}

void PhoneBook::add_contact(void)
{
    static int i;
    int         index;

    index = i % 8;
    this->_contacts[index].set_index(index);
    this->_contacts[index].init(index);
    i++;
}

void	PhoneBook::search_contact(void) const
{
	int		index = -1;
	bool	valid = false;
	std::cin.clear();
	
    while (valid)
	{
		std::cout << "Please enter the contact index: " << std::flush;
		std::cin >> index;
		if (std::cin.eof())
			exit(0);
		if (std::cin.good() && (index >= 0 && index <= 7))
        {
            valid = true;
        }
         else {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Available contacts are only between 0 and 7, please try again..." << std::endl;
		}
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << std::endl;
	this->_contacts[index].view();
}

int	PhoneBook::display_contacts(void) const
{
	int	i = 0;
	while (i < 8)
	{
		if (this->_contacts[i].get_index() == -1)
		{
			if (i == 0)
			{
				std::cout << "No contacts to display, please add contacts...\n" << std::endl;
				return (0);
			}
			else
			{
				i++;
				continue ;
			}
		}
		this->_contacts[i++].display();
	}
	std::cout << std::endl;
	return (1);
}

