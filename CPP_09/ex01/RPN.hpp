/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 18:35:40 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/04 14:57:23 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <cstdlib>


class RPN{
	private:
		std::stack<int> data;
	public:
		RPN();
  		RPN(const RPN& other);
    	RPN& operator=(const RPN& other);
		~RPN();

		int parserTokens(std::string token);
		int calculate(int b, int a, char op);
};
#endif