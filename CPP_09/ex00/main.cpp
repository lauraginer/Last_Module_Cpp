/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 20:02:19 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/02 20:55:13 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try{
		if(argc != 2)
			throw errorArgument();
		std::ifstream fileData("data.csv"); //aqui se abre el archivo
		std::ifstream file(argv[1]); 
		if(!file.is_open() || !fileData.is_open())
			throw errorArgument();
		
		BitcoinExchange btc;
		btc.fillMap(fileData);
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
			if(parserDate(date))
			{
				std::cout << "Error: invalid date => " << line << std::endl;
				continue;
			}
			double num; //para guardarnos el valor de parserValue
			if(parserValue(value, num))
				continue;
			btc.getUpdate(date, num); //comprobación + calculo
		}
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}

