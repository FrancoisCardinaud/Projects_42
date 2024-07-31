/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:25:01 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 16:29:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


using std::cerr;


int main (int argc, char **argv)
{
	(void)argc;
	(void)argv;

	Bureaucrat hermano("Hermano", LOWEST_GRADE);

	Bureaucrat ebil("Ebil", HIGHEST_GRADE);
	std::cout << std::endl;

	std::cout << std::endl;
	ShrubberyCreationForm scf("Ebil");
	PresidentialPardonForm ppf("Ebil");
	RobotomyRequestForm rrf("Ebil");
	std::cout << std::endl;

	ebil.executeForm(scf);
	scf.beSigned(ebil);
	ebil.executeForm(scf);

	std::cout << std::endl;

	ebil.executeForm(ppf);
	ppf.beSigned(ebil);
	ebil.executeForm(ppf);

	std::cout << std::endl;

	ebil.executeForm(rrf);
	rrf.beSigned(ebil);
	ebil.executeForm(rrf);

	std::cout << std::endl;

	try {
		hermano.executeForm(scf);
	}
	catch (std::exception& e) {
		cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	return EXIT_SUCCESS;
}