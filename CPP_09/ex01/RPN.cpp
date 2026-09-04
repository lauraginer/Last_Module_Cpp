/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 18:35:37 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/04 14:57:44 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
	std::cout << "Default constructor of RPN called\n";
}
RPN::RPN(const RPN& other): data(other.data)
{
	std::cout << "Copy constructor of RPN called\n";
}
RPN& RPN::operator=(const RPN& other)
{
	std::cout << "Copy assignment operator of RPN called\n";
	if(this != &other)
	{
		data = other.data;
	}
	return(*this);
}
RPN::~RPN()
{
	std::cout << "Destructor of RPN called\n";
}
int RPN::parserTokens(std::string token)
{
	size_t i = 0; //pa reiniciar
	if(token[i] == '-' ||token[i] == '+' ||token[i] == '/' ||token[i] == '*')
	{
		if(token.size() > 1)
			return (1);
		if(data.size() < 2) //para hacer el calculo con un minimo
			return(1);
		int b = data.top(); data.pop();
		int a = data.top(); data.pop();
		if(calculate(b, a, token[i]))
			return(1);
		i++;
	}
	else if(isdigit(token[i]))
	{
		if(token.size() > 1)
			return (1);
		i++;
		int number = atoi(token.c_str());
		data.push(number);
	}
	else
		return (1);
	
	return(0);
}
int RPN::calculate(int b, int a, char op)
{
	switch(op){
		case '-':
			data.push(a - b);
			break;
		case '+':
			data.push(a + b);
			break;
		case '*':
			data.push(a * b);
			break;
		case '/':
			if(b == 0)
				return (1);
			data.push(a / b);
			break;
		default:
			return (1);
	}
	return(0);
};