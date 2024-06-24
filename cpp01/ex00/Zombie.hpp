#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <cstdio>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie(std::string name);
        ~Zombie();

    void announce(void);
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif 