/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:47:59 by lginer-m          #+#    #+#             */
/*   Updated: 2026/03/02 16:11:16 by lginer-m         ###   ########.fr       */
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
		std::cout << "--TEST 1: TRYING WITH BOBBY AND ADMIN--\n";
		std::cout << std::endl;
		Bureaucrat supervisor("Admin", 101);
		ShrubberyCreationForm bobby("Home");
		std::cout << std::endl;
		std::cout << supervisor;
		supervisor.decrementGrade();
		std::cout << "Despues de decrementar: " << supervisor;
		bobby.beSigned(supervisor);
		supervisor.executeForm(bobby);
		std::cout << std::endl;
		std::cout << bobby;
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
    	std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		std::cout << "--TEST 2: TRYING WITH TOM AND HURRACA--\n";
		std::cout << std::endl;
		RobotomyRequestForm tom ("Comercial");
		PresidentialPardonForm hurraca("Aquavelis");
		Bureaucrat supervisor("Boss", 4);
		tom.beSigned(supervisor);
		supervisor.executeForm(tom);
		std::cout << std::endl;
		std::cout << tom;
		std::cout << std::endl;
		
		hurraca.beSigned(supervisor);
		supervisor.executeForm(hurraca);
		std::cout << std::endl;
		std::cout << hurraca;
		std::cout << std::endl;
	
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		std::cout << "--TEST 3: TRYING WITH WRONG GRADES--\n";
		std::cout << std::endl;
		RobotomyRequestForm jose ("Lidl");
		PresidentialPardonForm maria("Mercadona");
		Bureaucrat random("random member", 71);
		Bureaucrat supervisor("member of staff", 7);
		jose.beSigned(random);
		random.executeForm(jose);
		std::cout << std::endl;
		std::cout << jose;
		std::cout << std::endl;
		
		maria.beSigned(supervisor);
		supervisor.executeForm(maria);
		std::cout << std::endl;
		std::cout << maria;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		std::cout << "--TEST 4: TESTING MEMORY--\n";
		std::cout << std::endl;
    	ShrubberyCreationForm* form = new ShrubberyCreationForm("test");
    	Bureaucrat admin("Admin", 1);
    	form->beSigned(admin);
		std::cout << std::endl;
		std::cout << admin;
		std::cout << std::endl;
   		delete form;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return(0);
}