/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:20:16 by stigkas           #+#    #+#             */
/*   Updated: 2024/10/28 15:20:16 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class AForm;

class PresidentialPardonForm: public AForm
{
    private:
        std::string target;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &a_copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &og);
        virtual void	execute(Bureaucrat const& executor) const override;
};

#endif