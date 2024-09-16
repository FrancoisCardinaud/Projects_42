/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:47:38 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/16 20:56:45 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", target, 25, 5) 
{
    #ifdef LOGS
        std::cout << "[PresidentialPardonForm] Parameterized Constructor called" << std::endl;
    #endif
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
    : AForm(copy) 
{
    #ifdef LOGS
        std::cout << "[PresidentialPardonForm] Copy Constructor called" << std::endl;
    #endif
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    #ifdef LOGS
        std::cout << "[PresidentialPardonForm] Destructor called" << std::endl;
    #endif
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &assign) {
    if (this != &assign) {
        AForm::operator=(assign);  // Delegate to base class assignment operator
    }
    #ifdef LOGS
        std::cout << "[PresidentialPardonForm] Copy Assignment Operator called" << std::endl;
    #endif
    return *this;
}

void PresidentialPardonForm::executeSuperClassForm(Bureaucrat const& executor) const
{
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw Bureaucrat::GradeTooLowException();
    }
    std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
