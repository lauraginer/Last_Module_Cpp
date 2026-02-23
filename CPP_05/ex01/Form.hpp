/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauragm <lauragm@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:13:31 by lauragm           #+#    #+#             */
/*   Updated: 2026/02/23 21:15:34 by lauragm          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "iostream"
#include <exception>

class Form {
	private:
		const std::string name;
		bool signed;
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
		int getgradeExecute() const;

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