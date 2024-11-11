/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:16:38 by stigkas           #+#    #+#             */
/*   Updated: 2024/11/07 14:16:38 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{
    std::string fname = "Simos";
    std::string lname = "Tigkas";

    std::cout << "First name: " << fname << " , Last name: " << lname << std::endl;
    std::cout << "min(fname, lname) = " << ::min(fname, lname) << std::endl;
	std::cout << "max(fname, lname) = " << ::max(fname, lname) << std::endl;
    swap(fname, lname);
    std::cout << "First name: " << fname << " , Last name: " << lname << std::endl;

    int fps = 24;
    int cinematic_fps = 50;

    std::cout << std::endl;
    std::cout << "Fps: " << fps << ", Cinematic fps: " << cinematic_fps <<std::endl;
    std::cout << "min(fps, cinematic_fps) = " << ::min(fps, cinematic_fps) << std::endl;
	std::cout << "max(fps, cinematic_fps) = " << ::max(fps, cinematic_fps) << std::endl;
    swap(fps, cinematic_fps);
    std::cout << "Fps: " << fps << ", Cinematic fps: " << cinematic_fps <<std::endl;
    return (0);
}