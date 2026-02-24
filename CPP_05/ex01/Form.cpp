/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lginer-m <lginer-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:23:49 by lauragm           #+#    #+#             */
/*   Updated: 2026/02/24 16:42:11 by lginer-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): name("Default"), is_signed(false), grade_sign(150), grade_execute(150){
	std::cout << "Default constructor of Form called\n";
}
Form::Form(const std::string &nick, const int sign, const int exe) : name(nick), is_signed(false), grade_sign(sign), grade_execute(exe){
	if (grade_sign < 1 || grade_execute < 1)
    	throw Form::GradeTooHighException();
	if (grade_sign > 150 || grade_execute > 150)
    	throw Form::GradeTooLowException();
	std::cout << "Parametrized constructor of Form called\n";
}
Form::Form(const Form& other): name(other.name), is_signed(other.is_signed), grade_sign(other.grade_sign), grade_execute(other.grade_execute) {
	std::cout << "Copy constructor of Form called\n";
}
Form& Form::operator=(const Form& other)
{
	std::cout << "Copy assignment operator of Form called\n";
	if(this != &other)
		is_signed = other.is_signed;
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
	return(is_signed);
}
int Form::getGradeSign() const
{
	return(grade_sign);
}
int Form::getGradeExecute() const
{
	return(grade_execute);
}
void Form::beSigned(const Bureaucrat &obj)
{
	if(obj.getGrade() <= grade_sign)
		is_signed = true;
	else
		throw GradeTooLowException();
}
std::ostream &operator<<(std::ostream& out, Form const& obj)
{
	out << "Form " << obj.getName();
	if(obj.getSigned() == true)
		out << " signed!" << std::endl;
	else
		out << " not signed!" << std::endl;
	
	out << "Sign Grade " << obj.getGradeSign() << std::endl;
	out << "Execute Grade " << obj.getGradeExecute() << std::endl;
    return(out);
}
