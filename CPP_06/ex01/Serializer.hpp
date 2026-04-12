/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:58:21 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/12 21:21:58 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer{
	private:
		Serializer();
  		Serializer(const Serializer& other);
    	Serializer& operator=(const Serializer& other);
		~Serializer();
		
	public:
	static Data* deserialize(uintptr_t raw);
	static uintptr_t serialize(Data *ptr);

};
#endif
