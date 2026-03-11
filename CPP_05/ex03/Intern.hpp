/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:56:33 by lginer-m          #+#    #+#             */
/*   Updated: 2026/03/11 18:44:33 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "iostream"
#include "AForm.hpp"

class Intern{
	public:
		Intern();
  		Intern(const Intern& other);
    	Intern& operator=(const Intern& other);
		~Intern();
		AForm *makeForm(std::string form, std::string target);

		class FormDoesNotExist : public std::exception{
			public:
				const char *what() const throw();
		};
};

#endif