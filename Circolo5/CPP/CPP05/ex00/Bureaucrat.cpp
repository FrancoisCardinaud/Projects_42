/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:24:22 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/25 17:31:44 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called " << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
    std::cout << "Bureaucrat copy constructor called for " << _name << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    validateGrade(grade);
    _grade = grade;
    std::cout << "Bureaucrat " << _name << " created with grade " << _grade << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        // _name is constant, so no reassignment
        this->_grade = other._grade;
        std::cout << "Copy assignment operator called for Bureaucrat " << other._name << std::endl;
    }
    return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called " << std::endl;
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

void Bureaucrat::validateGrade(int grade) const
{
    if (grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    if (grade > LOWEST_GRADE)
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

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat)
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (stream);
}
