/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:36:40 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/18 17:35:58 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(void) {};

template <typename T>
MutantStack<T>::~MutantStack(void) {};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &a_copy): std::stack<T>(a_copy)
{
    *this = a_copy;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &og) {
    if (this != &og)
    {
        std::stack<T>::operator=(og);
        return (*this);
    }
    return (*this);
}

int main()
{
    std::cout << "~~MutantStack~~" <<std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "\n~~List~~" <<std::endl;
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back()<< std::endl;
    mlist.pop_back();
    std::cout << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    std::list<int>::iterator newit = mlist.begin();
    std::list<int>::iterator newite = mlist.end();
    ++newit;
    --newit;
    while (newit != newite)
    {
        std::cout << *newit << std::endl;
        ++newit;
    }
    std::list<int> l(mlist);
}