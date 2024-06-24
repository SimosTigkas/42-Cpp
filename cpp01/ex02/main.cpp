#include <iostream>

int main(void)
{
    std::string message="HI THIS IS BRAIN";
    std::string *stringPTR=&message;
    std::string &stringREF=message;

    std::cout << "The memory address of the string variable: " << &message << std::endl;
    std::cout << "The memory address held by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The memory address held by stringREF: " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "\nThe value of the string variable: " << message << std::endl;
    std::cout << "The value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF: " << stringREF << std::endl;
}
