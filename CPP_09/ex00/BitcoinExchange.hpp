/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 20:02:19 by lauragm           #+#    #+#             */
/*   Updated: 2026/08/18 21:04:05 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <iostream>

class BitcoinExchange{
	private:
	
	public:
		BitcoinExchange();
  		BitcoinExchange(const BitcoinExchange& other);
    	BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();
	
}

class errorArgument: public std::exception{
	public:
		const char *what() const throw();
}
class errorToDate: public std::exception{
	public:
		const char *what() const throw();
};

//necesitamos un segundo argumento que sea un archivo.txt
//Cada línea de este argumento debe de ser date|value
//Una fecha valida debe se ser Año-Mes-Día como losputos guiris
//Un valor valido deberia de ser un float o un valor positivo, entre 0 y 1000
//Tenemos que utilizar un contenedor, y un manejar mensajes de errores apropiados al contexto