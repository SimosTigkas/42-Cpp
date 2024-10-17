#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
    private:
        const std::string   name;
        int                 grade;
    public:
        ~Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& rhs);

		Bureaucrat& operator=(const Bureaucrat& rhs);

};

#endif
