/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:59:23 by stigkas           #+#    #+#             */
/*   Updated: 2024/10/28 13:34:13 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

# include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        const std::string   name;
        int                 grade;
    public:
        Bureaucrat(void);
        ~Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &a_copy);
        Bureaucrat& operator=(const Bureaucrat& og);
        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };
        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };
        unsigned int        getGrade() const;
        const std::string   getName() const;
        void                incrementGrade();
        void                decrementGrade();
        bool			    signForm(Form &form) const;

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &og);

#endif
