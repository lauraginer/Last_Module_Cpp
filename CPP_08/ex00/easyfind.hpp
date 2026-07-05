/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 21:00:13 by lauragm           #+#    #+#             */
/*   Updated: 2026/07/05 20:13:34 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <iostream>

class errorToFind: public std::exception{
	public:
		const char *what() const throw()
		{
			return("Error. Doesn't find the value or is empty!");
		}
};

template <typename T>
typename T::iterator easyfind(T& container, int value) //recuerda que los templates siempre tienen que ir en el compilador para generar una version concreta para cada tipo
{
	typename T::iterator it = container.begin();
	while(it != container.end())
	{
		if(*it == value)
			return(it);
		++it; //fumadon historico: es lo mismo que it++, solo que el que utilizamos siempre crea una copia temporal al parecer y devuelve el valor antes de incrementarlo
	}
	throw errorToFind();
};
//el subject dice que la función debe servir para CUALQUIER contenedor, el template se encarga de que funcione con todos.
#endif

//NO SE SI DEBERIA DE ACEPTAR CONST T&, SI ES QUE TIENE MUCHO SENTIDO EN ESTE EJERCICIO