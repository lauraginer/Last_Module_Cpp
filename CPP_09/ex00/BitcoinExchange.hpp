/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 20:02:19 by lauragm           #+#    #+#             */
/*   Updated: 2026/08/30 00:08:09 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <iostream>
#include <cstdlib>
#include <map>

class BitcoinExchange{
	private:
	std::map<std::string, float>data;
	
	public:
		BitcoinExchange();
  		BitcoinExchange(const BitcoinExchange& other);
    	BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
};

void eraseSpaces(std::string &str);
int parserFormatD(std::string &date);
int atoiDate(std::string &date);
int parserDate(std::string &date);
int parserValue(std::string &value, double &num);

class errorArgument: public std::exception{
	public:
		const char *what() const throw();
};

//necesitamos un segundo argumento que sea un archivo.txt
//Cada línea de este argumento debe de ser date|value
//Una fecha valida debe se ser Año-Mes-Día como losputos guiris
//Un valor valido deberia de ser un float o un valor positivo, entre 0 y 1000
//Tenemos que utilizar un contenedor, y manejar mensajes de errores apropiados al contexto
#endif