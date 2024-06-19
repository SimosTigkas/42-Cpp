#include "PhoneBook.hpp"

Contact::Contact()
{
    this->_index = -1;
}

Contact::~Contact()
{

}

void	Contact::set_index(int index)
{
	this->_index = index;
}

int	Contact::get_index(void) const
{
	return this->_index;
}

std::string	Contact::get_firstname(void) const
{
	return this->_firstName;
}

std::string	Contact::get_lastname(void) const
{
	return this->_lastName;
}

std::string	Contact::get_nickname(void) const
{
	return this->_nickname;
}

std::string	Contact::get_phonenumber(void) const
{
	return this->_phoneNumber;
}

std::string	Contact::get_darkestsecret(void) const
{
	return this->_darkestSecret;
}

static std::string  read_value(std::string output)
{
    int			success = 0;
    std::string	input="";

    while (!success)
    {
        std::cout << output << std::flush;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::cout << "End of file has been reached!" << std::endl;
			exit(0);
		}
        if (std::cin.good() && !input.empty())
        {
            success = 1;
        }
        else if (input.empty())
        {
            std::cin.clear();
			std::cout << std::endl;
			std::cout << "You entered an empty string! Please try again!" << std::endl;
        }
        else
        {
            std::cin.clear();
			std::cout << std::endl;
			std::cout << "Invalid input! Please try again!" << std::endl;
        }
    }
    return input;
}

void Contact::init(int index)
{
    std::cout << "Adding new contact for the index " << index << std::endl;
	std::cout << "Please follow these instructions:" << std::endl;
	this->_firstName = read_value("Type in your first name: ");
	this->_lastName = read_value("Type in your last name: ");
	this->_nickname = read_value("Type in your nickname: ");
	this->_phoneNumber = read_value("Type in your phone number: ");
	this->_darkestSecret = read_value("Reveal your darkest secret: ");
	std::cout << "Well done!! You have added successfully a contact!" << std::endl;
}

static std::string	check_max(std::string output)
{
	if (output.length() > 10)
		return output.substr(0, 9) + '.';
	return output;
}

void	Contact::display(void) const
{
	if (this->_index == -1)
		return ;
	std::cout << "|" << std::setw(10) << this->_index << std::flush;
	std::cout << "|" << std::setw(10) << check_max(this->_firstName) << std::flush;
	std::cout << "|" << std::setw(10) << check_max(this->_lastName) << std::flush;
	std::cout << "|" << std::setw(10) << check_max(this->_nickname) << std::flush;
	std::cout << "|" << std::flush;
	std::cout << std::endl;
}

void	Contact::view(void) const
{
	if (this->_index == -1)
	{
		std::cout << "Index not available! Add new contacts!" << std::endl;
		return;
	}
	std::cout << "CONTACT #" << this->_index << std::endl;
	std::cout << "First name: " << this->_firstName << std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << "\n" << std::endl;
}
