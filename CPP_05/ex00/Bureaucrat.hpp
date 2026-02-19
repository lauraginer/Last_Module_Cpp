/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:47:56 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/19 14:08:14 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "iostream"
#include <exception>

class Bureaucrat {
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
		
		class GradeTooHighException : public std::exception{
			public:
				const char *what() const throw(){
					return ("Grade is too hight!");
				}
		}; // Clase anidada(inception de clases)
		class GradeTooLowException : public std::exception{
			public:
				const char *what() const throw(){
					return("Grade is too low!");
				}
		};
	//no se si estan correctas las ultimas clases por estar implementadas en el hpp, investiga bien
};
std::ostream &operator<<(std::ostream& out, Bureaucrat const& obj);
#endif