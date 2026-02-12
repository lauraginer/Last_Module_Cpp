/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:47:56 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/12 13:52:11 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "iostream"

class Bureaucrat{
	public:
		const std::string name;
		int grade;
		Bureaucrat();
  		Bureaucrat(const Bureaucrat& other);
    	Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		
		std::string getName() const;
		int getGrade() const;
		void setGrade(int number);
		void incrementGrade();
		void decrementGrade();
};

std::ostream &operator<<(std::ostream& out, Bureaucrat const& obj);
#endif