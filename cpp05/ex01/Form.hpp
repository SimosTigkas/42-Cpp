/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:57:10 by stigkas           #+#    #+#             */
/*   Updated: 2024/10/23 17:57:10 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Form: public Bureaucrat
{
    private:
        const std::string   name;
        bool                isSigned;
        const int           sGrade;
        const int           eGrade;
    public:
        Form(void);
        ~Form(void);
        Form(std::string name, unsigned int sGrade, unsigned int eGrade);
        Form& operator=(const Form& og);
        Form(const Form &og);
        const std::string	&getName() const;
		const int			&getSGrade() const;
		const int			&getEGrade() const;
		bool				getIsSigned() const;
        class GradeTooLowException : public std::exception {
            public:
                const char *what() const throw();
        };
        class GradeTooHighException : public std::exception {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const Form &og);

#endif