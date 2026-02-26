/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:13:31 by lauragm           #+#    #+#             */
/*   Updated: 2026/02/26 12:56:43 by lginer-m         ###   ########.fr       */
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
		bool is_signed;
		const int grade_sign; // Grado mínimo requerido para FIRMAR
		const int grade_execute; // Grado mínimo requerido para EJECUTAR 
		
	public:
		AForm();
		AForm(const std::string &nick, const int sign, const int exe);
  		AForm(const AForm& other);
    	AForm& operator=(const AForm& other);
		virtual ~AForm() = 0;
		
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
std::ostream &operator<<(std::ostream& out, AForm const& obj);
#endif