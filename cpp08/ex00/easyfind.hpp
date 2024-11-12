/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:55:18 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/12 16:55:24 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <list>
# include <forward_list>
# include <algorithm>

class NotFoundException : public std::exception {
    public:
        const char *what(void) const throw()
		{
			const char *error = "Element not found..";
    		return error;
		}
};

template <typename T>
typename T::iterator easyfind(T &a, int b)
{
	typename T::iterator i = std::find(a.begin(), a.end(), b);
	if (i == a.end())
		throw NotFoundException();
	return i;
}

#endif
