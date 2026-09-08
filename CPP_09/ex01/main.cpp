/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 14:04:37 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/08 21:25:05 by lauragm          ###   ########.fr       */
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
	if(rpn.getSize() != 1)
	{
		std::cerr << "Error" << std::endl;
		return(1);
	}
	std::cout << rpn.getResult() << std::endl; //getter que devuelve el data.top()
	return(0);
}
