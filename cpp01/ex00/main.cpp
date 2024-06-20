#include "Zombie.hpp"

int main(void)
{
    std::string input = "";
    Zombie      *new_zombie;

    std::cout << "Let's create a zombie on the heap: " << std::endl;
    std::cout << "Give a name to the zombie: ";
    std::getline(std::cin, input);
    if (std::cin.eof())
    {
        std::cin.clear();
        clearerr(stdin);
    }
    new_zombie = newZombie(input);
    new_zombie->announce();
    delete new_zombie;

    std::cout << "\nLet's create a zombie on the stack:" << std::endl;
    std::cout << "Give a name to the zombie: ";
    std::getline(std::cin, input);
    if (std::cin.eof())
    {
        std::cin.clear();
        clearerr(stdin);
    }
    randomChump(input);
    return (0);
}