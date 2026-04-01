/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:36:36 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/01 18:14:22 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <limits>

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
	
	int n = 0;
	float fnum = 0;
	double dnum = 0;
	if(controlChar(literal, n, fnum, dnum))
		std::cout << "char: " << static_cast<char>(n) << std::endl;

	/*if(controlLength(literal, n, fnum, dnum) != 0)
	{
		std::cout << "char: Non displayable " << std::endl;
	}*/
	//Detectar tipo, convertir, imprimir resultados
	/*if(!(controlType(c, n, fnum, dnum) && !controlLength(literal, n, fnum, dnum)))
	{
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible" << std::endl;
	}
	else
	{
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << n << std::endl;
	}*/
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << fnum << std::endl;
	std::cout << "double: " << dnum << std::endl;
}
const char* ScalarConverter::GeneralError::what() const throw()
{
	return("Process of convert isn't valid. Wrong input.");
}

bool controlChar(std::string &str, int &n, float &fnum, double &dnum)
{	
	n = atoi(str.c_str());
	fnum = atof(str.c_str());
	dnum = strtod(str.c_str(), NULL); //mejor convertirlo aqui ya que lo hacemos desde la str
	if(!(str.size() > 0 && str.size() < 4))
	{
		std::cout << "char: Non displayable" << std::endl;
		return(false);
	}
	char converted = static_cast<char>(n); //si no lo convertimos, lo toma desde ascii
	if (!std::isprint(static_cast<unsigned char>(converted)))
	{
		std::cout << "char: Non displayable\n";
		return(false);
	}
	if(std::isnan(dnum) || std::isinf(dnum) || n < 0 || n > 127)
	{
		std::cout << "char: Impossible" << std::endl;
		return(false);
	}
	return(true);
}
bool controlInt(int &n, float &fnum, double &dnum)
{
	if(n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
	{
		std::cout << "int: Impossible" << std::endl;
		return(false);
	}
	return(true);
}