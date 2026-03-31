/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:36:36 by lginer-m          #+#    #+#             */
/*   Updated: 2026/03/31 17:10:31 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cmath>
#include <cstdlib>

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
	/*if (literal.size() > 1 && literal.size() < 4 && isprint())
		// hace un atoi o lo que sea
	else
		// not printable
	vale, en funcion de la longitud del string el parseo, antes que nada, y en ello hay que comprobar los limites
	y te quitas una parte importante
	*/
	char c = literal[0];
	int n = static_cast<int>(c);
	float fnum = static_cast<float>(c);
	double dnum = static_cast<double>(c);
	controlLength(literal, n, fnum, dnum);
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
	if(c == 0)
		return (false);
	if(std::isnan(dnum) || std::isinf(dnum)) // nan = not a number, inf = infinito
	{
		flag = false;
		std::cout << "char: Impossible" << std::endl;
		std::cout << "int: Impossible"  << std::endl;
	}	
	else if(!(isprint(c)) || c < 32 || c > 127)
	{
		flag = false;
		std::cout << "char: Non displayable" << std::endl;
	}
	(void)n;
	(void)fnum;
	(void)dnum;
	return(flag);
	//utiliza el bool para ver si es correcto o no???? necesito una organización del codigo
}

void controlLength(std::string &str, int &n, float &fnum, double &dnum)
{

	if (!(str.size() > 1 && str.size() < 4))
		return ;

	/*n = strtol(str.c_str()); //yo no se que coño es esto
	fnum = strtof(str.c_str());
	dnum = strtod(str.c_str());*/
	n = atoi(str.c_str());
	fnum = atof(str.c_str());
	dnum = strtod(str.c_str(), NULL);
	//solo convertir validar en funcion de la longitud
}