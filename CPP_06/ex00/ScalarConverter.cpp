/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:36:36 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/21 17:43:15 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cerrno>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <limits>
#include <iomanip>

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

static bool limits(const std::string &literal)
{
	return(literal == "nan" || literal == "+inf" || literal == "-inf"
		|| literal == "nanf" || literal == "+inff" || literal == "-inff");
}

static bool isValidEnd(char *endptr)
{
	return (*endptr == '\0') || (*endptr == 'f' && *(endptr + 1) == '\0');
}

static void printLimits(const std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if(literal == "nan" || literal == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if(literal == "+inf" || literal == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

void ScalarConverter::convert(std::string literal)
{
	if(literal.empty())
		throw ScalarConverter::GeneralError();
	if(limits(literal))
	{
		printLimits(literal);
		return;
	}
	int n = 0;
	float fnum = 0;
	double dnum = std::numeric_limits<double>::quiet_NaN();
	if(controlChar(literal, n, fnum, dnum))
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	if(controlInt(literal, n, fnum, dnum))
		std::cout << "int: " << n << std::endl;
	if(controlFloat(literal, fnum, dnum))
		std::cout << "float: " << std::fixed << std::setprecision(1) << fnum << "f" << std::endl; //para forzar decimales
	if(controlDouble(literal, fnum, dnum))
		std::cout << "double: " << std::fixed << std::setprecision(1) << dnum << std::endl;
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
	errno = 0;
	char *endptr = NULL;
	double d = strtod(str.c_str(), &endptr);
	if(endptr == str.c_str() || !isValidEnd(endptr) || errno == ERANGE || d < 0 || d > 127)
	{
		std::cout << "char: impossible" << std::endl;
		return(false);
	}
	n = static_cast<int>(d);
	fnum = static_cast<float>(d);
	dnum = d;
	if(!std::isprint(static_cast<unsigned char>(n)))
	{
		std::cout << "char: Non displayable" << std::endl;
		return(false);
	}
	return(true);
	//ES mejor separar el casteo del cast por si es numerico o no lo es, y asi paso de validar dos veces con atoi y strtol
	//ademas, no tiene sentido validar el tamaño de size si luego controlamos sus limites
}
bool controlInt(std::string &str, int &n, float &fnum, double &dnum)
{
	if(str.size() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
		return (true);
	errno = 0;
	char *endptr = NULL;
	double dn = strtod(str.c_str(), &endptr);
	if(endptr == str.c_str() || !isValidEnd(endptr) || errno == ERANGE
		|| dn < std::numeric_limits<int>::min() || dn > std::numeric_limits<int>::max())
	{
		std::cout << "int: impossible" << std::endl;
		return(false);
	}
	n = static_cast<int>(dn);
	fnum = static_cast<float>(dn);
	dnum = dn;
	return(true);
	//es mejor que el codigo sea repetitivo que modificarlo absolutamente todo para que quede mas limpio, el horno no esta pa bollos
}
bool controlFloat(std::string &str, float &fnum, double &dnum)
{
	if(str.size() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
		return(true);
	errno = 0;
	char *endptr = NULL;
	double dd = strtod(str.c_str(), &endptr);
	if(endptr == str.c_str() || errno == ERANGE || !isValidEnd(endptr))
	{
		std::cout << "float: impossible" << std::endl;
		return(false);
	}
	fnum = static_cast<float>(dd);
	if(std::isinf(fnum) || std::isnan(fnum))
	{
		std::cout << "float: impossible" << std::endl;
		return(false);
	}
	dnum = dd;
	return(true);

	//LOS LITERALES FLOAT Y DNUM se controlan en los dos primeros datos, al parecer
}
bool controlDouble(std::string &str, float &fnum, double &dnum)
{
	(void)fnum;
	if(str.size() == 1 && !std::isdigit(static_cast<unsigned char>(str[0])))
		return(true);
	errno = 0;
	char *endptr = NULL;
	dnum = strtod(str.c_str(), &endptr);
	if(endptr == str.c_str() || !isValidEnd(endptr) || errno == ERANGE)
	{
		std::cout << "double: impossible" << std::endl;
		return(false);
	}
	return(true);
	
}
//yo no se si esto tiene mucho sentido me agobia mucho tener que convertir otros tipos de datos antes que el que corresponde pero bueno