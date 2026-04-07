/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:58:21 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/07 18:24:07 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include "Data.hpp"

class Serializer{
	private:
		Serializer();
  		Serializer(const Serializer& other);
    	Serializer& operator=(const Serializer& other);
		~Serializer();
		
	public:
	Data* deserialize(uintptr_t raw);
	//toma un puntero y lo convierte al tipo entero sin signo uintptr_t
	static uintptr_t serialize(Data *ptr);
	//toma un parametro entero sin signo, y lo convierte en un puntero a Data
};

//tenemos que utilizar serialize() en la direccion dek objeto Data y pasa su valor de retorno a deserialize()
// el valor de retorno de deserialize, debe de ser igual al puntero original
#endif
