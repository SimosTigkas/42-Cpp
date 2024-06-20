#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    if (name.empty())
    {
        std::cout << "You did not give a name to the Zombie..please do" << std::endl;
        return (NULL);
    }
    return (new Zombie(name));
}
