/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:23:49 by lauragm           #+#    #+#             */
/*   Updated: 2026/03/11 18:07:25 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("Default"), isSigned(false), gradeSign(140), gradeExecute(140){
	std::cout << "Default constructor of Form called\n";
}
Form::Form(const std::string &nick, const int sign, const int exe) : name(nick), isSigned(false), gradeSign(sign), gradeExecute(exe){
	if (gradeSign < 1 || gradeExecute < 1)
    	throw Form::GradeTooHighException();
	if (gradeSign > 150 || gradeExecute > 150)
    	throw Form::GradeTooLowException();
	std::cout << "Parametrized constructor of Form called\n";
}
Form::Form(const Form& other): name(other.name), isSigned(other.isSigned), gradeSign(other.gradeSign), gradeExecute(other.gradeExecute) {
	std::cout << "Copy constructor of Form called\n";
}
Form& Form::operator=(const Form& other)
{
	std::cout << "Copy assignment operator of Form called\n";
	if(this != &other)
		isSigned = other.isSigned;
	return(*this);
}
Form:: ~Form()
{
	std::cout << "Destructor of Form called\n";
}
std::string Form::getName() const
{
	return(name);
}
bool Form::getSigned() const
{
	return(isSigned);
}
int Form::getGradeSign() const
{
	return(gradeSign);
}
int Form::getGradeExecute() const
{
	return(gradeExecute);
}
void Form::beSigned(const Bureaucrat &obj)
{
	if(isSigned == true)
		throw std::runtime_error("has already signed!");
	if(obj.getGrade() <= gradeSign)
		isSigned = true;
	else
		throw GradeTooLowException();
}
std::ostream &operator<<(std::ostream& out, Form const& obj)
{
	out << obj.getName();
	if(obj.getSigned() == true)
		out << " signed!" << std::endl;
	else
		out << " not signed!" << std::endl;
	
	out << "Sign Grade " << obj.getGradeSign() << std::endl;
	out << "Execute Grade " << obj.getGradeExecute() << std::endl;
    return(out);
}
const char* Form::GradeTooHighException::what() const throw()
{
	return("Oops. Grade is too high!");
}
const char* Form::GradeTooLowException::what() const throw()
{
	return("Oops. Grade isn't enought!");
}
