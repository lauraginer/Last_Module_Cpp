/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:12:09 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/26 13:50:45 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): target("Default"), grade_sign(145), grade_execute(137){
	std::cout << "Default constructor of ShrubberyCreationForm called\n";
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string &subject) : target(subject), grade_sign(145), grade_execute(137)
{
	std::cout << "Parametrized constructor of ShrubberyCreationForm called\n";
	if (grade_sign < 1 || grade_execute < 1)
	{
		std::cout << "Invalid grade. Can't be too hight";
		return ;
	}
    	return ;
	if (grade_sign > 150 || grade_execute > 150)
	{
		std::cout << "Invalid grade. Can't be too low";
		return ;
	}
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): target(other.target), grade_sign(other.grade_sign), grade_execute(other.grade_execute) {
	std::cout << "Copy constructor of ShrubberyCreationForm called\n";
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "Copy assignment operator of ShrubberyCreationForm called\n";
	if(this != &other)
		target = other.target;
	return(*this);
}
ShrubberyCreationForm:: ~ShrubberyCreationForm()
{
	std::cout << "Destructor of ShrubberyCreationForm called\n";
}

// hay que crear un puto archivo de mierda con el nombre de target + "-shrubbery", para poner un puto arbol ascii de
// puta mierda como el puto CPP01, recuerda la libreria fstream