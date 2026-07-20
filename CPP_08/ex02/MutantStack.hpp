/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 20:03:31 by lauragm           #+#    #+#             */
/*   Updated: 2026/07/20 22:11:17 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <exception>
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>{
	public:
		MutantStack();
  		MutantStack(const MutantStack& other);
    	MutantStack& operator=(const MutantStack& other);
		~MutantStack();

		using iterator = typename std::stack<T>::container_type::iterator;
		using const_iterator = typename std::stack<T>::container_type::const_iterator;
		iterator begin(); //podemos acceder al elemento protegido de c del stack (funciona internamente como un deque)
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		
	/*la idea es crear una version de stack donde se pueda iterar, entonces entiendo que se puede heredar de ese contenedor ya que
	el enunciado te dice que tiene que tener todas las funciones miembros disponibles y se va a poner mi abuela a copiarlas todas. En algún
	punto hay que utilizar templates, imagino que en el anterior para iteradores seguro*/
};
class MutantError : public std::exception{
		public:
			const char *what() const throw();
};

#endif

/*push(): Agrega un elemento a la parte superior de la pila.
pop():Elimina el elemento de la parte superior.
top(): Devuelve una referencia al elemento que está en la parte superior (te permite verlo sin borrarlo).
empty(): Devuelve true si la pila no tiene elementos.
size(): Devuelve la cantidad de elementos que hay en la pila.*/