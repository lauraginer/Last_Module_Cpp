/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 20:02:19 by lauragm           #+#    #+#             */
/*   Updated: 2026/08/20 22:06:31 by lauragm          ###   ########.fr       */
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

const char* errorArgument::what() const throw()
{
	return("Error: could not open file");
};

/*flujo: main()
 ├── cargar data.csv en el map        
 ├── abrir input.txt
 └── while(getline del input.txt)       
       ├── parsear línea
       ├── validar fecha/valor
       └── buscar en el map ya cargado, calcular, imprimir*/