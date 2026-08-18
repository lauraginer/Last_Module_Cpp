/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 20:03:31 by lauragm           #+#    #+#             */
/*   Updated: 2026/08/02 20:48:49 by lauragm          ###   ########.fr       */
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

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		iterator begin(); //Podemos acceder al elemento protegido de c del stack (funciona internamente como un deque)
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
};

#include "MutantStack.tpp" //Se pone aquí para leer justo la implementacion una vez leida la clase

#endif

/*push(): Agrega un elemento a la parte superior de la pila.
pop():Elimina el elemento de la parte superior.
top(): Devuelve una referencia al elemento que está en la parte superior (te permite verlo sin borrarlo).
empty(): Devuelve true si la pila no tiene elementos.
size(): Devuelve la cantidad de elementos que hay en la pila.*/