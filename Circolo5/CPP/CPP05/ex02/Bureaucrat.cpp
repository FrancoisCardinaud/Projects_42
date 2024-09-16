/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:47:23 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/16 20:50:53 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Unnamed"), grade(LOWEST_GRADE) {
    #ifdef LOGS
        std::cout << "[Bureaucrat] Default constructor called" << std::endl;
    #endif
}

Bureaucrat::Bureaucrat(const Bureaucrat& to_copy) 
    : name(to_copy.name), grade(to_copy.grade) 
{
    #ifdef LOGS
        std::cout << "[Bureaucrat] Copy constructor called for " << this->name << std::endl;
    #endif
}

Bureaucrat::Bureaucrat(std::string name, int grade) 
    : name(name), grade(grade) 
{
    if (grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    if (grade > LOWEST_GRADE)
        throw GradeTooLowException();
    
    #ifdef LOGS
        std::cout << "[Bureaucrat] Constructor called for " << this->name << " with grade " << this->grade << std::endl;
    #endif
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        const_cast<std::string&>(this->name) = other.name;  // Name is const, so we cast it here
        this->grade = other.grade;
    }
    #ifdef LOGS
        std::cout << "[Bureaucrat] Copy assignment operator called for " << this->name << std::endl;
    #endif
    return *this;
}

Bureaucrat::~Bureaucrat() {
    #ifdef LOGS
        std::cout << "[Bureaucrat] Destructor called for " << this->name << std::endl;
    #endif
}

const std::string& Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::getGrade() const {
    return this->grade;
}

void Bureaucrat::setGrade(int new_grade) {
    if (new_grade < HIGHEST_GRADE)
        throw GradeTooHighException();
    if (new_grade > LOWEST_GRADE)
        throw GradeTooLowException();
    this->grade = new_grade;
}

void Bureaucrat::incrementGrade() {
    setGrade(this->grade - 1);  // Decrement the grade safely
}

void Bureaucrat::decrementGrade() {
    setGrade(this->grade + 1);  // Increment the grade safely
}

void Bureaucrat::signForm(const std::string& form_name, bool is_signed) const {
    if (is_signed)
        std::cout << this->name << " signed " << form_name << std::endl;
    else
        std::cout << this->name << " couldn't sign " << form_name 
                  << " because the grade was too low." << std::endl;
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << this->name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& bureaucrat) {
    stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return stream;
}
