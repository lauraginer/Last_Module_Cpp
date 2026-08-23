/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 20:02:19 by lauragm           #+#    #+#             */
/*   Updated: 2026/08/23 20:55:30 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream> //leer archivos

int parserValues(std::string line, size_t pos)
{
	std::string date;
	std::string value;
	date = line.substr(0, pos);
	value = line.substr(pos + 1);
	std::cout << date << std::endl;
	std::cout << value << std::endl;
	return(0);
	//hay que separar espacios
};

int main(int argc, char **argv)
{
	try{
		if(argc != 2)
			throw errorArgument();
		std::ifstream file(argv[1]); //aqui se abre el archivo
		if(!file.is_open())
			throw errorArgument();
		
		std::string line; 
		std::getline(file, line);//1 llamada para saltarnos el enunciado
		while(std::getline(file, line)) 
		{
			size_t posLine = line.find('|');
			if(posLine == std::string::npos) //npos es lo que devuelve find cuando no encuentra el pos
				std::cout << "Error: bad input => " << line << std::endl;
			if(parserValues(line, posLine))
				std::cout << "Error: Fail to get values" << std::endl; //solo para comprobar
			//aqui hacemos todo el parser
			//parseamos la línea (separar fecha y valor, convertirla en float y blabla)
			//paseamos la fecha, formato valido
			//parseamos el valor, si es un valor negativo y despues si es demasiado grande
		}
		
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

