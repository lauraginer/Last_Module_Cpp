/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 20:03:31 by lauragm           #+#    #+#             */
/*   Updated: 2026/07/14 00:27:50 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iostream>
#include <vector>

class Span{
	private:
		unsigned int maxSize;
		std::vector<int> numbers; //vector se crea inicialmente vacío, no hace falta incializarlo en los constructores
	
	public:
		Span();
		Span(unsigned int max);
  		Span(const Span& other);
    	Span& operator=(const Span& other);
		~Span();

		void addNumber(int number); //Su función es añadir un único número al span, si intentas añadir otro número cuando ya hay N elementos, deberás lanzar una excepción.
		//es como un push_back
		unsigned int shortestSpan(); //Debe de encontrar la distancia más pequeña entre los números almacenados y retornarlo
		unsigned int longestSpan(); //Debe encontrar la distancia más grande entre los números almacenados y retornarlo.
		//si en las dos funciones, no hay números almacenados, o solo hay uno, no se puede encontrar ningún intervalo. Por lo tanto, se lanza una excepción.
		template <typename it>
		void allNumbers(it begin, it end); //permite añadir muchos números de golpe utilizando un rango de iteradores.
};
template <typename it> //en teoria deberia de ir aqui la definición
void Span::allNumbers(it begin, it end)
{
	while(begin != end)
	{
		addNumber(*begin);
		++begin;
	}
}
class SpanError : public std::exception{
		public:
			const char *what() const throw();
};		
#endif

