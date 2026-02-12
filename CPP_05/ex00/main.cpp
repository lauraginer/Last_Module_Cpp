/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:47:59 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/12 14:06:16 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat juan;
	std::cout << juan;

	juan.setGrade(30);
	juan.incrementGrade();
	std::cout << juan.getGrade();
	
//excepciones
	try
	{
 	   if(juan.grade <= 0)
			throw std::logic_error()
	   if(juan.grade > 150)
	}
	catch (std::exception & e)
	{
    	std::cout << "Error: Grade is too hight. Invalid grade.\n";
		std::cout << "Error: Grade is too hight. Invalid grade.\n";
	}

}