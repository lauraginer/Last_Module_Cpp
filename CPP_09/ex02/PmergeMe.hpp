/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:36:33 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/10 20:38:32 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <exception>


class PmergeMe{
	public:
		std::vector<int> base;
		std::list<int> base2;
		
		PmergeMe();
  		PmergeMe(const PmergeMe& other);
    	PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void parsingInput(char** argv, int argc);
		void printFirstLine();

};

	class error: public std::exception{
	public:
		const char *what() const throw();
};
#endif