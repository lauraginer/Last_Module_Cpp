/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:36:36 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/02 19:57:20 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cerrno>
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
	if(controlInt(literal, n, dnum))
		std::cout << "int: " << n << std::endl;

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
	std::cout << "float: " << fnum << std::endl;
	std::cout << "double: " << dnum << std::endl;
}
const char* ScalarConverter::GeneralError::what() const throw()
{
	return("Process of convert isn't valid. Wrong input.");
}

bool controlChar(std::string &str, int &n, float &fnum, double &dnum)
{	
	if (str.size() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
	{
		n = static_cast<unsigned char>(str[0]);
		fnum = static_cast<float>(n);
		dnum = static_cast<double>(n); //por si acaso
		if(!std::isprint(static_cast<unsigned char>(n))) //lo convertimos porque sino no devuelve en ascii
		{
			std::cout << "char: Non displayable" << std::endl;
			return (false);
		}
		return(true);
	}
	errno = 0; //para controlar la flag de ERANGE
	char *endptr = NULL;
	long value = strtol(str.c_str(), &endptr, 10); //para convertir luego a int, porque strtol devuelve long
	dnum = strtod(str.c_str(), NULL);
	fnum = static_cast<float>(dnum);
	if(endptr == str.c_str() || *endptr != '\0' || errno == ERANGE
		|| std::isnan(dnum) || std::isinf(dnum) || value < 0 || value > 127)
	{
		std::cout << "char: Impossible" << std::endl;
		return(false);
	}
	n = static_cast<int>(value);
	if(!std::isprint(static_cast<unsigned char>(n)))
	{
		std::cout << "char: Non displayable" << std::endl;
		return(false);
	}
	return(true);
	//ES mejor separar el casteo del cast por si es numerico o no lo es, y asi paso de validar dos veces con atoi y strtol
	//ademas, no tiene sentido validar el tamaño de size si luego controlamos sus limites
}
bool controlInt(std::string &str, int &n, double &dnum)
{
	if(str.size() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
		return (true);
	errno = 0;
	char *endptr = NULL;
	long value = strtol(str.c_str(), &endptr, 10);
	if(endptr == str.c_str() || *endptr != '\0' || errno == ERANGE || value < std::numeric_limits<int>::min()
		|| value > std::numeric_limits<int>::max() || std::isnan(dnum) || std::isinf(dnum))
	{
		std::cout << "int: Impossible" << std::endl;
		return(false);
	} 
	n = static_cast<int>(value); //un poco innecesario pero bueno
	return(true);
	//es mejor que el codigo sea repetitivo que modificarlo absolutamente todo para que quede mas limpio, el horno no esta pa bollos
}

//yo no se si esto tiene mucho sentido me agobia mucho tener que convertir otros tipos de datos antes que el que corresponde pero bueno