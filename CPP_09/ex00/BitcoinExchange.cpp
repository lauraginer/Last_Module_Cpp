/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 20:02:19 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/02 20:51:46 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::cout << "Default constructor of BitcoinExchange called\n";
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): data(other.data)
{
	std::cout << "Copy constructor of BitcoinExchange called\n";
}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	std::cout << "Copy assignment operator of BitcoinExchange called\n";
	if(this != &other)
	{
		data = other.data;
	}
	return(*this);
}
BitcoinExchange::~BitcoinExchange()
{
	std::cout << "Destructor of BitcoinExchange called\n";
}
int BitcoinExchange::fillMap(std::ifstream &fileData)
{
	std::string str;
	std::getline(fileData, str);
	while(std::getline(fileData, str))
	{
		size_t pos = str.find(',');
		if(pos == std::string::npos)
		{
			std::cout << "Error: Something's wrong on data" << str << std::endl;
			continue; //para evitar overflow
		}
		std::string realDate = str.substr(0, pos);
		std::string realValue = str.substr(pos + 1);
		eraseSpaces(realDate);
		eraseSpaces(realValue);
		double price = atof(realValue.c_str());
	
		data[realDate] = price; //crea automaticamente la clave[] si no existe, y añade el valor price
	}
	return(0);
}
int BitcoinExchange::getUpdate(std::string &date, double value)
{
	//first apunta a la clave, second al valor
	std::map<std::string, float>::iterator it = data.lower_bound(date); //da el primer elemento con clave igual o mayor que date
	if(it == data.end() || it->first != date)
	{
		if(it == data.begin()) //esta dentro porque si no peta, al final siempre va a pasar por la primera linea
		{
			std::cout << "Error: no rate available for date " << date << std::endl;
			return(-1);
		}
		--it;
	}
	std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
	return(0);
}
const char* errorArgument::what() const throw()
{
	return("Error: could not open file");
}
void eraseSpaces(std::string &str)
{
	size_t i;
	
	i = 0;
	while(i < str.length())
	{
		if(str[i] == 32 || (str[i] >= 9 && str[i] <= 12))
			str.erase(i, 1);
		else
			i++;
	}
	return ;
}
int parserFormatD(std::string &date)
{
	size_t i;
	
	i = 0;
	if(date.size() != 10 || date[4] != '-' || date[7] != '-')
		return(1);
	while(i < date.length())
	{
		if(i == 4 || i == 7)
			i++;
		if(!isdigit(date[i]))
			return(1);
		i++;
	}
	return(0);
}
int atoiDate(std::string &date)
{
	std::string y = date.substr(0,4);
	std::string m = date.substr(5,2);
	std::string d = date.substr(8,2);

	int year = atoi(y.c_str());
	int month = atoi(m.c_str());
	int day = atoi(d.c_str());
	
	if(month < 1 || month > 12)
		return(1);
	
	int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) //caso aislado: año bisiesto NO ESTA BIEN
		daysInMonth[1] = 29;
	if(day < 1 || day > daysInMonth[month - 1])
		return(1);	
	return(0);
}
int parserDate(std::string &date)
{
	eraseSpaces(date);
	if(parserFormatD(date))
		return(1);
	if(atoiDate(date))
		return(1);
	return(0);
}
int parserValue(std::string &value, double &num)
{
	eraseSpaces(value);
	num = atof(value.c_str()); //atof para tener en cuenta decimales
	if(num < 0)
	{
		std::cout << "Error: not a positive number " << std::endl;
		return(-1);
	}
	if(num > 1000)
	{
		std::cout << "Error: too large a number " << std::endl;
		return(-1);
	}
	return(0);
}
