/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 21:00:13 by lauragm           #+#    #+#             */
/*   Updated: 2026/06/09 21:10:07 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
typename T::iterator easyfind(T& container, int value) //recuerda que los templates siempre tienen que ir en el compilador para generar una version concreta para cada tipo
{
	//el subject dice que la función debe servir para CUALQUIER contenedor, el template se encarga de que funcione con todos.
}
//crear una funcion de tipo template que acepte un tipo T. Tiene que aceptar como parametros, 
//el 1º un contenedor de tipo T por ejemplo (std::vector<int> numbers), el 2º un entero
//hay que buscar la primera aparición del entero dentro del contenedor. Si este falla, hay que lanzar una excepción y si no,
//devolver algún valor de error

#endif


/*Buscar contenedores asociativos, buscar que cojones es stl, que se diferencia un vector de un contenedor (y que es este último) y afianzar conceptos basicos
que se me han olvidado por no programar en un mes y pico lista que de lista eres gilipollas*/

//añade toda la mierda explicativa a explication.txt