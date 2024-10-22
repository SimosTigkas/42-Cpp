#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {
    private:
        const std::string   name;
        int                 grade;
    public:
        Bureaucrat(void);
        ~Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &a_copy);
		Bureaucrat& operator<<(const Bureaucrat& og);

};

#endif
