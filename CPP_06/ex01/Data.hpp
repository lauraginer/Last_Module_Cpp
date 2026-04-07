/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:57:11 by lginer-m          #+#    #+#             */
/*   Updated: 2026/04/07 16:05:55 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <cstdint>
#include "iostream"

class Data{
	std::string name;
	public:
	 	Data(const Data& other);
    	Data& operator=(const Data& other);
		~Data();
};

#endif