/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:47:59 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/27 20:01:01 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	std::cout << std::endl;
	try
	{
		std::cout << "--TEST 1: TRYING WITH ALL CLASSES--\n";
		std::cout << std::endl;
		Bureaucrat supervisor("Admin", 101);
		ShrubberyCreationForm bobby("home");
		RobotomyRequestForm tom ("comercial");
		PresidentialPardonForm hurraca("aquavelis");
		std::cout << std::endl;
		std::cout << supervisor;
		supervisor.decrementGrade();
		std::cout << "Despues de decrementar: " << supervisor;
		bobby.beSigned(supervisor);
		bobby.execute(supervisor);
		tom.beSigned(supervisor);
		tom.execute(supervisor);
		hurraca.beSigned(supervisor);
		hurraca.execute(supervisor);
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
    	std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return(0);
}