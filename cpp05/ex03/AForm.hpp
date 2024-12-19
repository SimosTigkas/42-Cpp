/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:11:59 by stigkas           #+#    #+#             */
/*   Updated: 2024/10/28 15:11:59 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   name;
        bool                isSigned;
        const unsigned int           sGrade;
        const unsigned int           eGrade;
    public:
        AForm(void);
        virtual ~AForm(void);
        AForm(std::string name, unsigned int sGrade, unsigned int eGrade);
        AForm& operator=(const AForm& og);
        AForm(const AForm &og);
        std::string	getName() const;
		unsigned int			getSGrade() const;
		unsigned int			getEGrade() const;
		bool        getIsSigned() const;
        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };
        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };
        class FormIsNotSignedException : public std::exception {
            public:
                const char *what() const throw();
        };
        class FormDoesNotExist: public std::exception {
            public:
                const char *what() const throw();
        };
        bool         beSigned(const Bureaucrat &bur);
        virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &out, const AForm &og);

#endif