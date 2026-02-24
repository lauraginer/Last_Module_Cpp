/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:13:31 by lauragm           #+#    #+#             */
/*   Updated: 2026/02/24 13:58:05 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "iostream"
#include <exception>

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool is_signed;
		const int grade_sign; // Grado mínimo requerido para FIRMAR
		const int grade_execute; // Grado mínimo requerido para EJECUTAR 
		
	public:
		Form();
		Form(const std::string &nick, const int sign, const int exe);
  		Form(const Form& other);
    	Form& operator=(const Form& other);
		~Form();
		
		std::string getName() const;
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExecute() const;

		void beSigned(const Bureaucrat &obj);
		class GradeTooHighException : public std::exception{
			public:
				const char *what() const throw(){
					return ("Oops. Grade is too high!");
				}
		}; // Clase anidada(inception de clases)
		class GradeTooLowException : public std::exception{
			public:
				const char *what() const throw(){
					return("Oops. Grade isn't enought!");
				}
		};
};
std::ostream &operator<<(std::ostream& out, Form const& obj);
#endif