/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:04:37 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/03 21:15:53 by lauragm          ###   ########.fr       */
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
	while(input >> token)
	{
		size_t i = 0; //pa reiniciar
		if(isdigit(token[i]))
		{
			if(token.size() > 1)
			{
				std::cerr << "Error" << std::endl;
				return (1);
			}
			i++;
			std::cout << token << std::endl;
		}
		/*if(str[i] == '-' || str[i] == '+' || str[i] == '/' || str[i] == '*')
			i++;
		else if(str[i] == ' ')
			i++;
		else if(isdigit(str[i]))
			i++;
		else
		{
			std::cerr << "Error" << std::endl;
			return(1);
		}*/
	}
	return(0);
}

//el programa debe procesar la expresión y mostrar el resultado correcto por la salida estándar (stdout)
//si ocurre error, debe mpstarse un mensaje por stderr