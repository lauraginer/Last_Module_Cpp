/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:06:02 by lginer-m          #+#    #+#             */
/*   Updated: 2026/03/02 16:10:36 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRUBBERYCREATIONFORM_HPP
#define SRUBBERYCREATIONFORM_HPP

#include "iostream"
#include "AForm.hpp"
#include <exception>

class Bureaucrat;

class ShrubberyCreationForm : public AForm{
	private:
		const std::string target;
		
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &subject);
  		ShrubberyCreationForm(const ShrubberyCreationForm& other);
    	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();
		virtual void executeAction() const;

};

#endif