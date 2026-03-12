/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:47:56 by lginer-m          #+#    #+#             */
/*   Updated: 2026/03/12 16:01:57 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "iostream"
#include <exception>

class AForm;

class Bureaucrat {
	private:
		const std::string name;
		int grade;
		
	public:
		Bureaucrat();
		Bureaucrat(const std::string &nick, const int number);
  		Bureaucrat(const Bureaucrat& other);
    	Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		
		std::string getName() const;
		int getGrade() const;
		void setGrade(int number);
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form);
		void executeForm(AForm const & form) const;
		class GradeTooHighException : public std::exception{
			public:
				const char *what() const throw();
		};
		
		class GradeTooLowException : public std::exception{
			public:
				const char *what() const throw();
		};
};
std::ostream &operator<<(std::ostream& out, Bureaucrat const& obj);
#endif