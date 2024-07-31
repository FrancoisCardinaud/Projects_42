/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:25:09 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 16:29:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PresidentialPardonForm.hpp"


using std::cerr;


PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", target, 25, 5) {
	#ifdef LOGS
		std::cout << "[PresidentialPardonForm] Parameterized Constructor called" << std::endl;
	#endif
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
: AForm(copy.getName(), copy.getTarget(), copy.getGradeToSign(), copy.getGradeToExecute()) {
	#ifdef LOGS
		std::cout << "[PresidentialPardonForm] Copy Constructor called" << std::endl;
	#endif
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	#ifdef LOGS
		std::cout << "[PresidentialPardonForm] Destructor called" << std::endl;
	#endif
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &assign) {
	#ifdef LOGS
		std::cout << "[PresidentialPardonForm] Copy Assignment Operator called" << std::endl;
	#endif
	if (this == &assign)
		return *this;
	return *this;
}

void PresidentialPardonForm::executeSuperClassForm(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	else if (this->getSignState() == false)
		cerr << "PresidentialPardonForm couldn't be executed by " << executor.getName() << " because it wasn't signed!" << std::endl;
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
