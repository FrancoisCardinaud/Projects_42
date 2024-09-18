/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:47:47 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/18 15:43:37 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

using std::cout;
using std::cerr;
using std::endl;

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", target, 145, 137) {
	#ifdef LOGS
		cout << "[ShrubberyCreationForm] Parameterized constructor called" << endl;
	#endif 
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& to_copy)
: AForm(to_copy.getName(), to_copy.getTarget(), to_copy.getGradeToSign(), to_copy.getGradeToExecute()) {
	#ifdef LOGS
		cout << "[ShrubberyCreationForm] copy constructor called" << endl;
	#endif
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	#ifdef LOGS
		cout << "[ShrubberyCreationForm] destructor called"<< endl;
	#endif
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	#ifdef LOGS
		cout << "[ShrubberyCreationForm] copy assignment operator called"<< endl;
	#endif
	if (this == &assign)
		return *this;
	return *this;
}

void ShrubberyCreationForm::executeSuperClassForm(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw Bureaucrat::GradeTooLowException();
	else if (!this->getSignState())
		cerr << "ShrubberyCreationForm couldn't be executed by " << executor.getName() << " because it wasn't signed!" << endl;
	else
	{
		// Create the shrubbery file with ASCII trees
		std::ofstream file;
		file.open((this->getTarget() + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::trunc);
		if (file.is_open())
		{
			file << "\n"
				 << "       ###\n"
				 << "      #o###\n"
				 << "    #####o###\n"
				 << "   #o#\\#|#/###\n"
				 << "    ###\\|/#o#\n"
				 << "     # }|{  #\n"
				 << "       }|{\n"
				 << std::endl;
			file.close();
			cout << "Shrubbery created." << endl;
		}
		else
		{
			cerr << "Could not create shrubbery file." << endl;
		}
	}
}
