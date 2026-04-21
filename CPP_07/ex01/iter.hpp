/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 18:45:34 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/21 21:16:31 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <ostream>

template <typename T, typename Function>
void iter(T *array, const size_t length, Function f)
{
	size_t len = 0;
	
	while(len < length)
	{
		f(array[len]);
		len++;
	}
	std::cout << "The lenght of array by iter is: " << len << std::endl;
}
#endif

/*¿Cómo lo valida entonces?
Cuando instancias iter(...), el compilador deduce Function a partir del tercer argumento y 
luego intenta compilar esta línea dentro de iter.

En definitiva, basicamente segun como trates el tipo de dato, el compilador lo toma de
una forma o otra*/