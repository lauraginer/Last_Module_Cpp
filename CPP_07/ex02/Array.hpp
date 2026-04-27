/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:38:01 by lauragm           #+#    #+#             */
/*   Updated: 2026/04/27 14:27:01 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <ostream>
#include <exception>

template<typename T>
class Array{
	//pone que debe de contener elementos de tipo T, aunque no dice cuales
	private:
		T *array;
		size_t sizeArray;
	public:
		Array(); //debe crear un array vacio
		Array(unsigned int n); //debe crear un array de n elementos inicializados por defecto
		Array(const Array& other);
		Array& operator=(const Array& other);
		T& operator[](const unsigned int i);
		~Array(); //no lo pide, pero por si acaso

		size_t size() const; //debe de lanzar el numero de elementos
		
	class IndexException : public std::exception{
			public:
				const char *what() const throw();
		};
		/*segun el subject, tenemos que utilizar el operador new[] para alojar memoria (entiendo que tengo que hacer deep copy?????? no lo se dios), Los elementos deben poder accederse
		con [], y si el indice esta fuera de rango, debemos de lanzar una excepción.*/
};

#endif