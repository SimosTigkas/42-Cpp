/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:14:40 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/07 14:14:40 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// int main(void)
// {
//     double      aperture[] = {1.4 , 2.0, 2.8, 4.0, 5.6, 8.0, 11.0, 16.0};
//     std::string camera[] = {"Sony", "Canon", "Fujifilm", "Nikon"};

//     iter(aperture, 8, &ft_print);
//     std::cout << std::endl;
//     iter(camera, 4, &ft_print); 
// }

class Awesome
{
  public:
    Awesome( void ) : _n( 42 ) { return; }
    int get( void ) const { return this->_n; }
  private:
    int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
{
  o << rhs.get();
  return o;
}

template< typename T >
void print( T& x )
{
  std::cout << x << std::endl;
  return;
}

int main() {
  int tab[] = { 0, 1, 2, 3, 4 };
  Awesome tab2[5];

  iter( tab, 5, print<int> );
  iter( tab2, 5, print<Awesome> );

  return 0;
}