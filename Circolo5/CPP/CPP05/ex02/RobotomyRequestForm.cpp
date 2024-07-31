/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:25:14 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 17:57:58 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "RobotomyRequestForm.hpp"


using std::cerr;


RobotomyRequestForm::RobotomyRequestForm(std::string target) 
: AForm("RobotomyRequestForm", target, 72, 45) {
	#ifdef LOGS
		std::cout << "[RobotomyRequestForm] Parameterized Constructor" << std::endl;
	#endif
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
: AForm(other.getName(), other.getTarget(), other.getGradeToSign(), other.getGradeToExecute()) {
	#ifdef LOGS
		std::cout << "[RobotomyRequestForm] Copy Constructor" << std::endl;
	#endif
}

RobotomyRequestForm::~RobotomyRequestForm() {
	#ifdef LOGS
		std::cout << "[RobotomyRequestForm] Destructor called" << std::endl;
	#endif
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &assign) {
	#ifdef LOGS
		std::cout << "[RobotomyRequestForm] copy assignment operator called"<< std::endl;
	#endif
	if (this == &assign)
		return *this;
	return *this;
}

void RobotomyRequestForm::executeSuperClassForm(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	else if (this->getSignState() == false)
		cerr << "RobotomyRequestForm couldn't be executed by " << executor.getName() << " because it wasn't signed!" << std::endl;
	else
	{
		std::srand(std::time(NULL));

		std::cout << "(Loud drill noises) " << std::endl;

		if (random() % 2 == 0)
			std::cout << this->getTarget() << " successfully robotomized." << std::endl;
		else
			std::cout << this->getTarget() << " failed when trying to robotimize." << std::endl;
	}
}
