#include "PhoneBook.hpp"

std::string check_options()
{
    std::string input="";
    int         success=0;

    while (!success)
    {
        std::cout << "Choose one of the options!!" << std::endl;
        std::cout << "WHAT DID YOU CHOOSE? --> " << std::flush;
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(0);
        if (std::cin.good() && !input.empty())
            success = 1;
        else
        {
            std::cin.clear();
            std::cout << "Your input is invalid, try again!!" << std::endl;
        }
    }
    return (input);
}

int main(void)
{
    std::string input;
    int         len;
    PhoneBook   book_of_contacts;

    std::cout << std::endl;
	std::cout << "~~~~~~~~~~~~~....WELCOME TO MY....~~~~~~~~~~~~" << std::endl;
    std::cout << "~~~~~~~~~~~~~MY AWESOME PHONEBOOK~~~~~~~~~~~~~\n" << std::endl;
	std::cout << "			|						  " << std::endl;
	std::cout << "			|						  " << std::endl;
	std::cout << "			V						  " << std::endl;
    std::cout << std::endl;
    std::cout << "You have the following options at your disposal:" << std::endl;
    std::cout << "ADD: add a new contact to your phone book." << std::endl;
	std::cout << "SEARCH: search for a specific contact inside of your phone book." << std::endl;
	std::cout << "EXIT: exit the program.\n" << std::endl; 

    while (1)
    {
        input = check_options();
        len = input.length();
        if (len == 3 && !input.compare("ADD"))
        {
            book_of_contacts.add_contact();
            std::cout << std::endl;
            continue;
        }
        else if (len == 6 && !input.compare("SEARCH"))
        {
            if (book_of_contacts.display_contacts())
                book_of_contacts.search_contact();

        }
        else if (len == 4 && !input.compare("EXIT"))
            break;
        else
        {
            std::cout << "There is no option like this, try again\n" << std::endl;
            continue;
        }
    }
    return (0);
}