/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 21:36:25 by lauragm           #+#    #+#             */
/*   Updated: 2026/09/21 21:24:50 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <sys/time.h>

int main(int argc, char **argv)
{
	try{
		if(argc < 2)
			throw error();
		PmergeMe data;
		data.parsingInput(argv, argc);
		data.printResultLine(false);
		
		struct timeval startVec = {0, 0}, endVec = {0, 0};
		gettimeofday(&startVec, NULL);
		data.result = firstStep(data.base);
		gettimeofday(&endVec, NULL);
		double totalVec = (endVec.tv_sec - startVec.tv_sec) * 1000000.0 + (endVec.tv_usec - startVec.tv_usec); //formula para microsegundos

		struct timeval startDeq = {0, 0}, endDeq = {0, 0};
		gettimeofday(&startDeq, NULL);
		data.result2 = deqFirstStep(data.base2); //DEQUE
		gettimeofday(&endDeq, NULL);

		double totalDeq = (endDeq.tv_sec - startDeq.tv_sec) * 1000000.0 + (endDeq.tv_usec - startDeq.tv_usec);

		data.printResultLine(true);
		std::cout << "Time to process a range of " << data.base.size() << " elements with std::vector : " << totalVec << " us" << std::endl;
		std::cout << "Time to process a range of " << data.base2.size() << " elements with std::deque : " << totalDeq << " us" << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	
}
