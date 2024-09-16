/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:47:43 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/16 20:57:00 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
    : AForm("RobotomyRequestForm", target, 72, 45) 
{
    #ifdef LOGS
        std::cout << "[RobotomyRequestForm] Parameterized Constructor called" << std::endl;
    #endif
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    : AForm(copy) 
{
    #ifdef LOGS
        std::cout << "[RobotomyRequestForm] Copy Constructor called" << std::endl;
    #endif
}

RobotomyRequestForm::~RobotomyRequestForm() {
    #ifdef LOGS
        std::cout << "[RobotomyRequestForm] Destructor called" << std::endl;
    #endif
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &assign) {
    if (this != &assign) {
        AForm::operator=(assign);
    }
    #ifdef LOGS
        std::cout << "[RobotomyRequestForm] Copy Assignment Operator called" << std::endl;
    #endif
    return *this;
}

void RobotomyRequestForm::executeSuperClassForm(Bureaucrat const& executor) const
{
    if (executor.getGrade() > this->getGradeToExecute()) {
        throw Bureaucrat::GradeTooLowException();
    }
    
    std::cout << "(Loud drill noises...) " << std::endl;
    
    srand(time(NULL));
    if (rand() % 2 == 0) {
        std::cout << this->getTarget() << " has been successfully robotomized!" << std::endl;
    } else {
        std::cout << this->getTarget() << " failed to be robotomized!" << std::endl;
    }
}
