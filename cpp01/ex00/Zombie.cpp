#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->_name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie named as " 
        << this->_name << "..DIED.." << std::endl;
}

void Zombie::announce(void)
{
	if (this->_name.empty())
		return ;
	std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
