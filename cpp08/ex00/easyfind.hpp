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
