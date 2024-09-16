/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:47:30 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/16 20:57:40 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <iostream>

AForm::AForm(std::string name, std::string target, int grade_to_sign, int grade_to_execute)
    : name(name), target(target), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute) 
{
    if (grade_to_sign > LOWEST_GRADE || grade_to_execute > LOWEST_GRADE) {
        throw GradeTooLowException();
    }
    if (grade_to_sign < HIGHEST_GRADE || grade_to_execute < HIGHEST_GRADE) {
        throw GradeTooHighException();
    }
    #ifdef LOGS
        std::cout << "[AForm] Parameterized constructor called for " << this->name << std::endl;
    #endif
}

AForm::~AForm() {
    #ifdef LOGS
        std::cout << "[AForm] Destructor called for " << this->name << std::endl;
    #endif
}

AForm::AForm(const AForm& to_copy) 
    : name(to_copy.getName()), target(to_copy.getTarget()), 
      is_signed(to_copy.getSignState()), grade_to_sign(to_copy.getGradeToSign()), 
      grade_to_execute(to_copy.getGradeToExecute()) 
{
    #ifdef LOGS
        std::cout << "[AForm] Copy Constructor called for " << this->name << std::endl;
    #endif
}

AForm& AForm::operator=(const AForm& original) {
    if (this != &original) {
        this->is_signed = original.getSignState();
        // Note: name and target are const and cannot be modified after initialization
    }
    #ifdef LOGS
        std::cout << "[AForm] Copy Assignment Operator called for " << this->name << std::endl;
    #endif
    return *this;
}

const std::string& AForm::getName() const {
    return this->name;
}

const std::string& AForm::getTarget() const {
    return this->target;
}

int AForm::getGradeToSign() const {
    return this->grade_to_sign;
}

int AForm::getGradeToExecute() const {
    return this->grade_to_execute;
}

bool AForm::getSignState() const {
    return this->is_signed;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > this->getGradeToSign()) {
        bureaucrat.signForm(this->getName(), false);
        throw GradeTooLowException();
    }
    this->is_signed = true;
    bureaucrat.signForm(this->getName(), true);
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!this->is_signed) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw GradeTooLowException();
    }
    this->executeSuperClassForm(executor);  // Call the specific form's execution logic
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm exception: grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm exception: grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm exception: form not signed!";
}

std::ostream& operator<<(std::ostream& stream, const AForm& form) {
    stream << "AForm: " << form.getName() 
           << " | Target: " << form.getTarget() 
           << " | Grade to sign: " << form.getGradeToSign()
           << " | Grade to execute: " << form.getGradeToExecute()
           << " | Signed state: " << (form.getSignState() ? "Yes" : "No");
    return stream;
}
