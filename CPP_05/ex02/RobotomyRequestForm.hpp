/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:00:34 by lginer-m          #+#    #+#             */
/*   Updated: 2026/02/27 19:19:42 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "iostream"
#include "AForm.hpp"
#include <exception>

class Bureaucrat;

class RobotomyRequestForm : public AForm{
	private:
		std::string target;
		
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &subject);
  		RobotomyRequestForm(const RobotomyRequestForm& other);
    	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();
		virtual void executeAction() const;

};

#endif