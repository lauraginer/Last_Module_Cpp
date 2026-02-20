/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:47:59 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/20 20:02:25 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << std::endl;
	try
	{
		std::cout << "--TEST 1: JUAN AND SUPERVISOR WITH RIGHT GRADE--\n";
 	   	Bureaucrat juan;
		Bureaucrat supervisor("Admin", 101);
		Bureaucrat pablo("Pablo", 130); // Constructor con parametros
		Bureaucrat salva("Salvador", 7); // Constructor con parametros
		std::cout << std::endl;
		std::cout << juan;
		std::cout << supervisor;
		std::cout << pablo;
		std::cout << salva;
		juan.setGrade(30);
		juan.incrementGrade();
		supervisor.decrementGrade();
		pablo.incrementGrade();
		std::cout << "Despues de incrementar: " << juan;
		std::cout << "Despues de decrementar: " << supervisor;
		std::cout << "Despues de incrementar: " << pablo;
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
    	std::cout << "Exception caught: " << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		std::cout << "--TEST 2: HIGH AND HIGH2--\n";
		Bureaucrat hight2("random", 160);
		/*Bureaucrat hight;
		std::cout << std::endl;
		std::cout << hight;
		hight.decrementGrade();
		std::cout << "hight: " << hight;
		std::cout << std::endl;*/
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
		/*Bureaucrat low;
		std::cout << std::endl;
		std::cout << low;
		low.setGrade(1);
		low.incrementGrade();
		std::cout << "low: " << low;
		std::cout << std::endl;*/
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	return(0);
}