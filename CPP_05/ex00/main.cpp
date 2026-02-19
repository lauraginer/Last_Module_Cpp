/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:47:59 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/19 20:42:08 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	Bureaucrat juan;
	Bureaucrat supervisor;
	Bureaucrat wrong;
	
	std::cout << juan;
	std::cout << supervisor;
	std::cout << wrong; //esta mal, no hace las excepciones
	juan.setGrade(30);
	supervisor.setGrade(101);
	juan.incrementGrade();
	supervisor.decrementGrade();
	wrong.incrementGrade();
	std::cout << "despues de incrementar: " << juan;
	std::cout << "despues de decrementar: " << supervisor;
	std::cout << "wrong: " << wrong;

//excepciones
	try
	{
 	   if(juan.grade <= 0)
			throw Bureaucrat::GradeTooHighException();
	   if(juan.grade > 150)
		throw Bureaucrat::GradeTooLowException();
	}
	catch (std::exception& e)
	{
    	std::cout << "Error: Invalid grade.\n";
	}
	return(0);
}