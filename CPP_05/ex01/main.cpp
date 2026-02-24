/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:47:59 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/24 16:38:50 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << std::endl;
	try
	{
		std::cout << "--TEST 1: PABLO AND SUPERVISOR WITH RIGHT GRADE--\n";
		std::cout << std::endl;
		Bureaucrat supervisor("Admin", 101);
		Form pablo("Pablo", 130, 50);
		std::cout << std::endl;
		std::cout << supervisor;
		std::cout << pablo;
		supervisor.decrementGrade();
		std::cout << "Despues de decrementar: " << supervisor;
		supervisor.signForm(pablo);
		std::cout << pablo;
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
    	std::cout << "Exception caught: " << e.what() << std::endl;
	}
	/*try
	{
		std::cout << std::endl;
		std::cout << "--TEST 2: HIGH AND HIGH2--\n";
		Bureaucrat hight2("random", 160);
		Bureaucrat hight;
		std::cout << std::endl;
		std::cout << hight;
		hight.decrementGrade();
		std::cout << "hight: " << hight;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		std::cout << "--TEST 3: LOW AND LOW2--\n";
		Bureaucrat low2("modnar", -5);
		Bureaucrat low;
		std::cout << std::endl;
		std::cout << low;
		low.setGrade(1);
		low.incrementGrade();
		std::cout << "low: " << low;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}*/
	
	return(0);
}