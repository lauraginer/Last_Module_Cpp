/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 20:02:19 by lauragm           #+#    #+#             */
/*   Updated: 2026/08/24 00:21:31 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream> //leer archivos

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
int parserDate(std::string &date)
{
	eraseSpaces(date);
	//eraseSpaces(value); acuerdate de que esto va en la funcion que modifica el valor
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
				std::cout << "Error: Invalid date" << std::endl;
			
			//paseamos la fecha, formato valido
			//parseamos el valor, si es un valor negativo y despues si es demasiado grande
		}
		
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

