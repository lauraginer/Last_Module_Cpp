/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:47:59 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/26 13:03:09 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main()
{
	std::cout << std::endl;
	try
	{
		std::cout << "--TEST 1: PABLO AND SUPERVISOR WITH RIGHT GRADE--\n";
		std::cout << std::endl;
		Bureaucrat supervisor("Admin", 101);
		//AForm pablo("Pablo", 130, 50);
		std::cout << std::endl;
		std::cout << supervisor;
		//std::cout << pablo;
		supervisor.decrementGrade();
		std::cout << "Despues de decrementar: " << supervisor;
		//supervisor.signForm(pablo);
		//std::cout << pablo;
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
    	std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		std::cout << "--TEST 2: CRISTINA HASN'T ENOUGH GRADE--\n";
		//AForm cristina("Cristina", 149, 100);
		Bureaucrat worker("worker", 150);
		std::cout << std::endl;
		std::cout << worker;
		//worker.signForm(cristina);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		std::cout << "--TEST 3: SIGNED TWICE--\n";
		Bureaucrat b1("B1", 20);
		Bureaucrat b2("B2", 30);
		//AForm f("AForm", 50, 25);
		std::cout << std::endl;
		//b1.signForm(f);
		//b2.signForm(f);
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return(0);
}