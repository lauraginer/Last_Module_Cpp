/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:36:39 by lginer-m          #+#    #+#             */
/*   Updated: 2026/07/05 20:12:25 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERT_HPP
#define SCALARCONVERT_HPP

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