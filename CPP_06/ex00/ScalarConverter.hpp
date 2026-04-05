/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:36:39 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/06 01:13:25 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

#include "iostream"

class ScalarConverter{
	private:
		ScalarConverter();
  		ScalarConverter(const ScalarConverter& other);
    	ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	public:
		
		static void convert(std::string literal);
		// static funciona para no hacer una instancia de una clase directamente (trabajamos con la clase directamente), 
		// tiene sentido porque no hay atributos en esta clase, no merece la pena
		class GeneralError : public std::exception{
			public:
				const char *what() const throw();
		};
};
bool controlChar(std::string &str, int &n, float &fnum, double &dnum);
bool controlInt(std::string &str, int &n, float &fnum, double &dnum);
bool controlFloat(std::string &str, float &fnum, double &dnum);
bool controlDouble(std::string &str, float &fnum, double &dnum);

#endif