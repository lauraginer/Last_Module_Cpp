/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:47:59 by lginer-m          #+#    #+#             */
/*   Updated: 2026/03/09 20:16:50 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	std::cout << std::endl;
	try
	{
		std::cout << "--TEST 1: TEST FROM SUBJECT--\n";
    	Intern someRandomIntern;
    	AForm* rrf;
    	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << std::endl;
		delete rrf;
	}
	catch (std::exception& e)
	{
		std::cout << "Intern catch an incident: " << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		std::cout << "--TEST 2: TESTING ALL FORMS--\n";
		Intern intern;
		AForm* form1 = intern.makeForm("shrubbery creation", "home");
    	AForm* form2 = intern.makeForm("robotomy request", "prision");
    	AForm* form3 = intern.makeForm("presidential pardon", "hospital");
		std::cout << std::endl;
 		std::cout << *form1 << std::endl;
    	std::cout << *form2 << std::endl;
    	std::cout << *form3 << std::endl;
    	delete form1;
    	delete form2;
    	delete form3;

	}
	catch(const std::exception& e)
	{
		std::cout << "Intern catch an incident: " << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		std::cout << "--TEST 3: TESTING WITH MORE INTERNS AND EXECUTING--\n";
		Intern intern;
		Intern paca;
		Bureaucrat boss("Boss", 1);
		AForm* form1 = intern.makeForm("shrubbery creation", "restaurant");
    	AForm* form2 = paca.makeForm("presidential pardon", "El Retiro");
		std::cout << std::endl;
 		std::cout << *form1 << std::endl;
    	std::cout << *form2 << std::endl;
		form2->beSigned(boss);
		boss.executeForm(*form2);
		std::cout << std::endl;
    	delete form1;
    	delete form2;
	}
	catch(const std::exception& e)
	{
		std::cout << "Intern catch an incident: " << e.what() << std::endl;	
	}
	try
	{
		std::cout << std::endl;
		std::cout << "--TEST 4: WRONG CLASSES--\n";
		Intern random;
		AForm* form1 = random.makeForm("shr ubbery creation      ", "restaurant");
    	AForm* form2 = random.makeForm("pResiDentiAL PARDON", "El Retiro");
		std::cout << std::endl;
    	delete form1;
    	delete form2;
	}
	catch(const std::exception& e)
	{
		std::cout << "Intern catch an incident: " << e.what() << std::endl;
	}
	
	
	
	return(0);
}