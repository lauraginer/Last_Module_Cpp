/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:36:36 by lginer-m          #+#    #+#             */
/*   Updated: 2026/03/12 18:51:30 by lginer-m         ###   ########.fr       */
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
	//Detectar tipo, convertir, imprimir resultados
 	if(literal.empty() || !(isprint(c)))
		std::cout << "Process of convert char is not valid\n";
	//comprobar si es imprimible, utilizar la biblioteca cctype
	

}