/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:36:39 by lginer-m          #+#    #+#             */
/*   Updated: 2026/03/31 15:38:11 by lginer-m         ###   ########.fr       */
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
void controlLength(std::string &str, int &n, float &fnum, double &dnum);
// controla la longitud y con esto sabes hasta que punto transformarlo
// si es mas largo que int_max_length
bool controlType(char c, int n, float fnum, double dnum);

#endif