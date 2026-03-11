/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:13:31 by lauragm           #+#    #+#             */
/*   Updated: 2026/03/11 18:17:27 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "iostream"
#include <exception>

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		bool isSigned;
		const int gradeSign; // Grado mínimo requerido para FIRMAR
		const int gradeExecute; // Grado mínimo requerido para EJECUTAR 
		
	public:
		AForm();
		AForm(const std::string &nick, const int sign, const int exe);
  		AForm(const AForm& other);
    	AForm& operator=(const AForm& other);
		virtual ~AForm();
		
		std::string getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExecute() const;
		void beSigned(const Bureaucrat &obj);
		
		void execute(Bureaucrat const &executor) const;
		
	protected:
		virtual void executeAction() const = 0;
		
	class GradeTooHighException : public std::exception{
		public:
			const char *what() const throw();
	}; // Clase anidada(inception de clases)
	class GradeTooLowException : public std::exception{
		public:
			const char *what() const throw();
	};
	class GradeIsAlreadySigned : public std::exception{
		public:
			const char *what() const throw();
	};
	class GradeNotSigned : public std::exception{
		public:
			const char *what() const throw();
	};
	class GradeNotExecute : public std::exception{
		public:
			const char *what() const throw();
	};
};
std::ostream &operator<<(std::ostream& out, AForm const& obj);
#endif