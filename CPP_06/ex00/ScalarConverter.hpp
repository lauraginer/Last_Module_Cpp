/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:36:39 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/02 19:52:42 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include "iostream"

class ScalarConverter{
	public:
		ScalarConverter();
  		ScalarConverter(const ScalarConverter& other);
    	ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
		
		static void convert(std::string literal);
		// static funciona para no hacer una instancia de una clase directamente (trabajamos con la clase directamente), 
		// tiene sentido porque no hay atributos en esta clase, no merece la pena
		class GeneralError : public std::exception{
			public:
				const char *what() const throw();
		};
};
//int controlLength(std::string &str, int &n, float &fnum, double &dnum);
// controla la longitud y con esto sabes hasta que punto transformarlo
// si es mas largo que int_max_length
//bool controlType(char c, int n, float fnum, double dnum);
bool controlChar(std::string &str, int &n, float &fnum, double &dnum);
bool controlInt(std::string &str, int &n, double &dnum);
#endif