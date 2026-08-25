/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 20:02:19 by lauragm           #+#    #+#             */
/*   Updated: 2026/08/25 21:48:07 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream> //leer archivos
#include <cstdlib>

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
	if(day < 1 || day > daysInMonth[month - 1])
		return(1);
	if(month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) //caso aislado: año bisiesto NO ESTA BIEN
		daysInMonth[1] = 29;
		
	/*std::cout << "year: " << year << std::endl;
	std::cout << "month: " << month << std::endl;
	std::cout << "day: " << day << std::endl;*/
	return(0);
}

int parserDate(std::string &date)
{
	eraseSpaces(date);
	//eraseSpaces(value); acuerdate de que esto va en la funcion que modifica el valor
	if(parserFormatD(date))
		return(1);
	if(atoiDate(date))
		return(1);
	std::cout << date << std::endl;
	return(0);
}

int main(int argc, char **argv)
{
	try{
		if(argc != 2)
			throw errorArgument();
		std::ifstream file(argv[1]); //aqui se abre el archivo
		if(!file.is_open())
			throw errorArgument();
		
		std::string line; 
		std::getline(file, line); //saltamos el enunciado
		while(std::getline(file, line)) 
		{
			size_t posLine = line.find('|');
			if(posLine == std::string::npos) //npos es lo que devuelve find cuando no encuentra el pos
			{
				std::cout << "Error: bad input => " << line << std::endl;
				continue; //para evitar overflow
			}	
			std::string date = line.substr(0, posLine);
			std::string value = line.substr(posLine + 1);
			//std::cout << value << std::endl;
			if(parserDate(date))
				std::cout << "Error: Invalid date => " << line << std::endl;
			
			
			//paseamos la fecha, formato valido
			//parseamos el valor, si es un valor negativo y despues si es demasiado grande
			//no nos podemos olvidar de la comparacion de si no existe coincidencia exacta, coger la fecha anterior
		}
		
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

