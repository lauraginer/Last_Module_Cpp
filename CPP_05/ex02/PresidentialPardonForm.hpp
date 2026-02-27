/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:42:20 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/27 19:23:47 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "iostream"
#include "AForm.hpp"
#include <exception>

class Bureaucrat;

class PresidentialPardonForm : public AForm{
	private:
		std::string target;
		
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &subject);
  		PresidentialPardonForm(const PresidentialPardonForm& other);
    	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();
		virtual void executeAction()  const;
};

#endif