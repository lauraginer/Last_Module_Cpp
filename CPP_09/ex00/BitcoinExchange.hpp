/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 20:02:19 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/03 13:04:22 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <iostream>
#include <cstdlib>
#include <fstream> //leer archivos
#include <map>

class BitcoinExchange{
	private:
	std::map<std::string, float>data;
	
	public:
		BitcoinExchange();
  		BitcoinExchange(const BitcoinExchange& other);
    	BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		
		int fillMap(std::ifstream &fileData);
		int getUpdate(std::string &date, double value);

};

void eraseSpaces(std::string &str);
int parserFormatD(std::string &date);
int atoiDate(std::string &date);
int parserDate(std::string &date);
int parserFormatV(std::string &value, std::string &line);
int parserValue(std::string &value, double &num, std::string &line);

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