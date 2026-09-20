/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:36:33 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/20 21:59:54 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <exception>

class PmergeMe{
	public:
		std::vector<int> base;
		std::vector<int> result;
		std::deque<int> base2;
		std::deque<int> result2;
		
		PmergeMe();
  		PmergeMe(const PmergeMe& other);
    	PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void parsingInput(char** argv, int argc);
		void printResultLine(bool flag);		
};

std::vector<size_t> generateJacobstall(size_t index);
std::vector<size_t> buildOrder(size_t n);
void calculeBinary(std::vector<int> &largest, int value);
void secondStep(std::vector<int> &minors, std::vector<int> &largestOrdered);

std::vector<int> firstStep(std::vector<int> vec);

	class error: public std::exception{
	public:
		const char *what() const throw();
};
#endif