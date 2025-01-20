/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:24:29 by stigkas           #+#    #+#             */
/*   Updated: 2025/01/20 11:24:29 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <cctype>
# include <sstream>
# include <string>


class RPN
{
    private:
        std::stack<int> myStack;
        std::string expression;
    public:
        RPN(void);
        RPN(const std::string& input);
        ~RPN(void);
        RPN(const RPN &a_copy);
        RPN &operator=(const RPN &og);

        bool checkExpression(const std::string& input);
        int calculateExpression(const std::string& input);
        std::string getExpression(void);
};


#endif