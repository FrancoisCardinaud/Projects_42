/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:24:40 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 17:57:58 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Form.hpp"




Form::Form(const Form& other)
: name(other.name), is_signed(other.is_signed),
grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute) {
	std::cout << "[Form] <" << this->getName() << "> copy constructor called" << std::endl;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute) 
: name(name), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	if (grade_to_sign > LOWEST_GRADE
	|| grade_to_execute > LOWEST_GRADE)
		throw (Form::GradeTooLowException());
	else if (grade_to_sign < HIGHEST_GRADE
	|| grade_to_execute < HIGHEST_GRADE)
		throw (Form::GradeTooHighException());
	this->is_signed = false;
	std::cout << "[Form] <" << this->getName() << "> constructor has been called" << std::endl;
}

Form::~Form(void) {
	std::cout << "[Form] <" << this->getName() << "> default destructor has been called" << std::endl;
}

const std::string& Form::getName(void) const {
	return this->name;
}

bool Form::getSignState(void) const {
	return this->is_signed;
}

int Form::getGradeToSign(void) const {
	return this->grade_to_sign;
}

int Form::getGradeToExecute(void) const {
	return this->grade_to_execute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeToSign())
	{
		this->is_signed = true;
		bureaucrat.signForm(this->getName(), this->is_signed);
	}
	else
	{
		bureaucrat.signForm(this->getName(), this->is_signed);
		throw (Form::GradeTooLowException());
	}

}

const char* Form::GradeTooHighException::what(void) const throw() {
	return "Form exception: exception: grade too high!";
}

const char* Form::GradeTooLowException::what(void) const throw() {
	return "Form exception: exception: grade too low!";
}

std::ostream &operator<<(std::ostream &stream, Form &form)
{
	stream << "Name: " << form.getName() << "\n"
		   << "Signed: " << (form.getSignState() == true ? "yes" : "no") << "\n"
		   << "Grade to sign: " << form.getGradeToSign() << "\n"
		   << "Grade to execute: " << form.getGradeToExecute() << "\n" 
		   << std::endl;
	return stream;
}
