/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:24:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 18:16:37 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor has been called " << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
    std::cout << "Bureaucrat copy constructor has been called " << _name << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) 
{
    validateGrade(grade);
    std::cout << "Bureaucrat " << _name << " was created with grade " << _grade << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        this->_grade = other._grade;
    std::cout << "Copy assignment operator called for Bureaucrat " << _name << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat default destructor has been called " << std::endl;
}

const std::string &Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::incrementGrade(void)
{
    validateGrade(_grade - 1);
    _grade--;
}

void Bureaucrat::decrementGrade(void)
{
    validateGrade(_grade + 1);
    _grade++;
}

void Bureaucrat::validateGrade(int grade) 
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat exception: Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat exception: Grade too low!");
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &Bureaucrat)
{
	os << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
		return (os);
}
