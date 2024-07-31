/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:25:40 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 16:29:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"




int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	AForm *a;
	AForm *b;
	AForm *c;

	std::cout << std::endl;

	Intern Arnaldo;

	a = Arnaldo.makeForm("robotomy request", "Ebil");
	std::cout << std::endl;
	b = Arnaldo.makeForm("presidential pardon", "Ebil");
	std::cout << std::endl;
	c = Arnaldo.makeForm("shrubbery creation", "Ebil");
	std::cout << std::endl;

	Arnaldo.makeForm("foo", "Ebil");
	std::cout << std::endl;

	delete a;
	delete b;
	delete c;
	return EXIT_SUCCESS;
}