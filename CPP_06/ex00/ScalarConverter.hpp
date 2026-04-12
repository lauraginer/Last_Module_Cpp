/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:36:39 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/12 21:45:48 by lginer-m         ###   ########.fr       */
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
		//Static funciona para no hacer una instancia de una clase directamente (trabajamos con la clase directamente).
};
bool controlChar(std::string &str, int &n, float &fnum, double &dnum);
bool controlInt(std::string &str, int &n, float &fnum, double &dnum);
bool controlFloat(std::string &str, float &fnum, double &dnum);
bool controlDouble(std::string &str, float &fnum, double &dnum);

#endif