#include "Zombie.hpp"

void randomChump(std::string name)
{

    if (name.empty())
    {
        std::cout << "You did not give a name to the Zombie..please do" << std::endl;
        return;
    }
    Zombie random_chump(name);
    random_chump.announce();
}
