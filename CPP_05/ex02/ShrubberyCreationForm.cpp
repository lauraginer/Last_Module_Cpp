/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:12:09 by lginer-m          #+#    #+#             */
/*   Updated: 2026/03/09 16:17:10 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation", 145, 137), target("Default")
{
	std::cout << "Default constructor of ShrubberyCreationForm called\n";
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &subject) : AForm("Shrubbery Creation", 145, 137), target(subject)
{
	std::cout << "Parametrized constructor of ShrubberyCreationForm called\n";
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), target(other.target){
	std::cout << "Copy constructor of ShrubberyCreationForm called\n";
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "Copy assignment operator of ShrubberyCreationForm called\n";
	if(this != &other)
		AForm::operator=(other);
	return(*this);
}
ShrubberyCreationForm:: ~ShrubberyCreationForm()
{
	std::cout << "Destructor of ShrubberyCreationForm called\n";
}
void ShrubberyCreationForm::executeAction() const
{
	std::string filename = target + "_shrubbery";
	std::string content;
	
	std::ofstream outfile(filename.c_str()); //Crear archivo de salida
	if (!outfile.is_open())
	{
		std::cout << "Error: could not create output file" << std::endl;
		return ;
	}
	else
		std::cout << "*The file " << filename << " has been created*\n";
	outfile << "       /\\\n";
    outfile << "      /**\\\n";
    outfile << "     /****\\\n";
    outfile << "    /******\\\n";
    outfile << "   /********\\\n";
    outfile << "       ||\n";
    outfile << "       ||\n";
	outfile << " /-/_-/-/-/-/-/-/\n";
	outfile.close();
}
// hay que crear un puto archivo de mierda con el nombre de target + "-shrubbery", 
//para poner un puto arbol ascii de
// puta mierda como el puto CPP01, recuerda la libreria fstream