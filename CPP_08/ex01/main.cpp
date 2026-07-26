/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/05 20:02:33 by lauragm           #+#    #+#             */
/*   Updated: 2026/07/26 22:51:26 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>
#include <deque>

int main()
{
	try{
		std::cout << "--TEST 1: TEST FROM MAIN--\n";
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "shortest: " << sp.shortestSpan() << std::endl;
    	std::cout << "longest: " << sp.longestSpan() << std::endl;
		std::cout << std::endl;
		
		std::cout << "--TEST 2: TESTING WITH DUPLICATES AND TWO NUMBERS--\n";
		Span spp(10);
    	spp.addNumber(7);
   		spp.addNumber(7);
    	spp.addNumber(7);
		std::cout << "DUPLICATES" << std::endl;
    	std::cout << "shortest: " << spp.shortestSpan() << std::endl;
    	std::cout << "longest: " << spp.longestSpan() << std::endl;
		std::cout << std::endl;
		Span spy(2);
		spy.addNumber(1000);
		spy.addNumber(2);
		std::cout << "TWO NUMBERS" << std::endl;
		std::cout << "shortest: " << spy.shortestSpan() << std::endl;
    	std::cout << "longest: " << spy.longestSpan() << std::endl;
		std::cout << std::endl;
		
		std::cout << "--TEST 3: TESTING WITH LIST AND DEQUE--\n";
		std::list<int> lst;
		lst.push_back(10);
		lst.push_back(-2);
    	lst.push_back(5);
    	lst.push_back(20);
		Span spList(10);
    	spList.allNumbers(lst.begin(), lst.end());
		std::cout << "LISTS" << std::endl;
    	std::cout << "list shortest: " << spList.shortestSpan() << std::endl;
    	std::cout << "list longest: " << spList.longestSpan() << std::endl;
		std::cout << std::endl;
    	std::deque<int> dq;
    	dq.push_back(100);
    	dq.push_back(40);
    	dq.push_back(90);
    	dq.push_back(41);
    	Span spDeque(10);
    	spDeque.allNumbers(dq.begin(), dq.end());
		std::cout << "DEQUES" << std::endl;
    	std::cout << "deque shortest: " << spDeque.shortestSpan() << std::endl;
    	std::cout << "deque longest: " << spDeque.longestSpan() << std::endl;
    	std::cout << std::endl;
		
		std::cout << "-- TEST 4: TESTING WITH 10000 NUMBERS --\n";
	    Span se(10000);
        std::vector<int> v;
		int i = 0;
        while(i < 10000)
		{
			v.push_back(i);
			i++;
		}
        se.allNumbers(v.begin(), v.end());
        std::cout << "shortest: " << se.shortestSpan() << '\n';
        std::cout << "longest: " << se.longestSpan() << '\n';
		
		std::cout << "\n--TEST 5: WORNG TESTS--\n";
		Span sw(3);
        sw.addNumber(1);
        sw.addNumber(2);
        sw.addNumber(3);
        sw.addNumber(4);

		Span w(2);
		w.addNumber(4);
		std::cout << "shortest: " << w.shortestSpan() << std::endl;
    	std::cout << "longest: " << w.longestSpan() << std::endl;
		return 0;
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
}