/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:38:20 by stigkas           #+#    #+#             */
/*   Updated: 2024/10/31 11:38:20 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits.h>

 class ScalarConverter;

 class ScalarConverter
 {
     private:
         ScalarConverter(void);
         ~ScalarConverter(void);
         ScalarConverter(const ScalarConverter &a_copy);
         ScalarConverter& operator=(const ScalarConverter& og);
     public:
         static void convert(std::string type);
 };

#endif
