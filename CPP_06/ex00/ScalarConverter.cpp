/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:36:36 by lginer-m          #+#    #+#             */
/*   Updated: 2026/03/19 16:00:50 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor of ScalarConverter called\n";
}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	std::cout << "Copy constructor of ScalarConverter called\n";
	(void)other;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	std::cout << "Copy assignment operator of ScalarConverter called\n";
	if(this != &other)
		(void)other;
	return(*this);
}
ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor of ScalarConverter called\n";
}
static void convert(std::string literal)
{
	char c = literal[0];
	int n = static_cast<int>(c);
	float fnum;
	double dnum;
	//Detectar tipo, convertir, imprimir resultados
 	if(literal.empty() || !(isprint(c)))
		throw ScalarConverter::GeneralError();//comprobar si es imprimible, utilizar la biblioteca cctype CORRIGELO
	
	//debería de aceptar espacios digo yo no?(son imprimibles)
	

}
const char* ScalarConverter::CanNotPrint::what() const throw()
{
	return("Error. This result is not a printable ASCII character.");
}
const char* ScalarConverter::GeneralError::what() const throw()
{
	return("Process of convert isn't valid. Wrong input.");
}