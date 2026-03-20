/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:36:36 by lginer-m          #+#    #+#             */
/*   Updated: 2026/03/20 20:08:48 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>

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
void ScalarConverter::convert(std::string literal)
{
	if(literal.empty())
		throw ScalarConverter::GeneralError();
	if (literal.size() == 1)
		char c = literal[0];
	/*if (literal.size() > 1 && literal.size() < 4 && isprint())
		// hace un atoi o lo que sea
	else
		// not printable
	vale, en funcion de la longitud del string el parseo, antes que nada, y en ello hay que comprobar los limites
	y te quitas una parte importante
	*/
	int n = static_cast<int>(c);
	float fnum = static_cast<float>(c);
	double dnum = static_cast<double>(c);
	//Detectar tipo, convertir, imprimir resultados
	if(controlType(c, n, fnum, dnum))
	{
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << n << std::endl;
		std::cout << "float: " << fnum << std::endl;
		std::cout << "double: " << dnum << std::endl;
	}
}
const char* ScalarConverter::GeneralError::what() const throw()
{
	return("Process of convert isn't valid. Wrong input.");
}
bool controlType(char c, int n, float fnum, double dnum)
{
	bool flag;
		
	flag = true;
	if(std::isnan(dnum) || std::isinf(dnum)) // nan = not a number, inf = infinito
	{
		flag = false;
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << n << std::endl;
	}	
	else if(!(isprint(c)) || c < 32 || c > 127)
	{
		flag = false;
		std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << n << std::endl;
	}
	(void)fnum;
	(void)dnum;
	return(flag);
	//tengo una idea, utilizar el switch y segun que casos comprobar char, int, float y tal
	//sino, es una puta locura

	//NO SWITCH NO, ES MUCHISIMO PEOR
}