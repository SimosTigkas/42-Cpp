/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:23:55 by stigkas           #+#    #+#             */
/*   Updated: 2025/01/20 11:23:55 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
   // std::cout << "RPN Default Constructor has been called" << std::endl;
}

RPN::RPN(const std::string& input)
{
    this->expression = input;
}

RPN::RPN(const RPN &a_copy)
{
    // std::cout << "RPN Copy Constructor has been called" <<std::endl;
    *this = a_copy;
}

RPN &RPN::operator=(const RPN &og)
{
    // std::cout << "RPN assignment operator has been called." << std::endl;
    if (this != &og)
    {
        expression = og.expression;
        myStack = og.myStack;
    }
    return *this;
}

RPN::~RPN(void)
{
    // std::cout << "RPN Destructor has been called" << std::endl;
}

std::string RPN::getExpression(void)
{
    return this->expression;
}

bool RPN::checkExpression(const std::string &input)
{
    std::istringstream expr(input);
    std::string token;
    std::string ops="+-*/";

    while (std::getline(expr, token, ' '))
    {
        if ((token.length() == 1 && !std::isdigit(token[0]) && (ops.find(token) == std::string::npos)) || (token.length() == 2 && std::isdigit(token[1]) && token[0] != '-'))
            return false;
    }
    return (true);
}

int RPN::calculateExpression(const std::string &input)
{
    std::istringstream expr(input);
    std::string token;
    std::string ops="+-*/";

    while (std::getline(expr, token, ' '))
    {
        if ((token.length() == 1 && std::isdigit(token[0])) || (token.length() == 2 && std::isdigit(token[1]) && token[0] == '-'))
            myStack.push(std::stoi(token));
        else if (token.length() == 1 && ops.find(token) != std::string::npos && myStack.size() >= 2)
        {
            int first = myStack.top();
            myStack.pop();
            int second = myStack.top();
            myStack.pop();
            if (token == "+")
                myStack.push(first + second);
            if (token == "-")
                myStack.push(second - first);
            if (token == "*")
                myStack.push(first * second);
            if (token == "/" && first != 0)
                myStack.push(second / first);
        }
        else
            throw std::runtime_error("Error: Wrong token.");
    }
    if (!myStack.size())
        throw std::runtime_error("Error");
    return (myStack.top());
}