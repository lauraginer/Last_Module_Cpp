/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:26:13 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/12 21:09:19 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include "iostream"

class A;
class B;
class C;

class Base{
	public:
		virtual ~Base();
	};
Base *generate(void); 
void identify(Base *p);
void identify(Base &p);

#endif