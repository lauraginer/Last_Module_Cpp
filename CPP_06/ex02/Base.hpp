/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:26:13 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/08 19:30:42 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include "iostream"

class Base{
	public:
		virtual ~Base();
		
		virtual Base *generate(void); 
		//entiendo que esta funcion va aqui si hay que instanciar mas de una
		//clase, ademas de tener que ser virtual
		void identify(Base *p);
		void identify(Base &p);
};

#endif