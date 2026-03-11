/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:00:34 by lginer-m          #+#    #+#             */
/*   Updated: 2026/03/10 12:50:26 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "iostream"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>

class RobotomyRequestForm : public AForm{
	private:
		const std::string target;
		
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &subject);
  		RobotomyRequestForm(const RobotomyRequestForm& other);
    	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm();
		virtual void executeAction() const;

};

#endif