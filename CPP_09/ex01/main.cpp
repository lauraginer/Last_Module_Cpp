/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:04:37 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/04 13:56:40 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <string>
#include <sstream>

int main(int argc, char **argv)
{
	if(argc != 2)
	{	
		std::cerr << "Error: bad input" << std::endl;
		return (1);
	}
	std::istringstream input(argv[1]);
	std::string token;
	RPN rpn;
	while(input >> token)
	{
		if(rpn.parserTokens(token))
		{
			std::cerr << "Error" << std::endl;
			return(1);
		}
	}
	return(0);
}

//el programa debe procesar la expresión y mostrar el resultado correcto por la salida estándar (stdout)
//si ocurre error, debe mpstarse un mensaje por stderr