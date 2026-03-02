/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:42:20 by lginer-m          #+#    #+#             */
/*   Updated: 2026/03/02 16:10:48 by lginer-m         ###   ########.fr       */
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
		const std::string target;
		
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &subject);
  		PresidentialPardonForm(const PresidentialPardonForm& other);
    	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		virtual ~PresidentialPardonForm();
		virtual void executeAction()  const;
};

#endif