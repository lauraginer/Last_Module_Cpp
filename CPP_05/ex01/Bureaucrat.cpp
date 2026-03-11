/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:47:53 by lginer-m          #+#    #+#             */
/*   Updated: 2026/03/11 18:09:00 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(150){
	std::cout << "Default constructor of Bureaucrat called\n";
}
Bureaucrat::Bureaucrat(const std::string &nick, const int number): name(nick), grade(number){
	if(number < 1)
		throw GradeTooHighException();
	if(number > 150)
		throw GradeTooLowException();
	std::cout << "Parametrized constructor of Bureaucrat called\n";
}
Bureaucrat::Bureaucrat(const Bureaucrat& other): name(other.name), grade(other.grade){
	std::cout << "Copy constructor of Bureaucrat called\n";
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Copy assignment operator of Bureaucrat called\n";
	if(this != &other)
		grade = other.grade; // Recuerda que la variable name es const
	return(*this);
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor of Bureaucrat called\n";
}
std::string Bureaucrat::getName() const
{
	return(name);
}
int Bureaucrat::getGrade() const
{
	return(grade);
}

void Bureaucrat::setGrade(int number)
{
	grade = number;
}

void Bureaucrat::incrementGrade()
{
	if(grade >= 1 && grade <= 150)
		grade--;
	if(grade < 1)
		throw GradeTooHighException();
	return;
}
void Bureaucrat::decrementGrade()
{
	if(grade >= 1 && grade <= 150)
		grade++;
	if(grade > 150)
		throw GradeTooLowException();
	return;
}

std::ostream &operator<<(std::ostream& out, Bureaucrat const& obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return(out);
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		if(form.getSigned() == true)
			std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
    	std::cout << getName() << " couldn't sign " << form.getName() << " because..." << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return("Grade is too low!");
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return("Grade is too high!");
}
