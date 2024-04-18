/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:25:40 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:25:41 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	AForm *a;
	AForm *b;
	AForm *c;

	cout << endl;

	Intern Arnaldo;

	a = Arnaldo.makeForm("robotomy request", "Ebil");
	cout << endl;
	b = Arnaldo.makeForm("presidential pardon", "Ebil");
	cout << endl;
	c = Arnaldo.makeForm("shrubbery creation", "Ebil");
	cout << endl;

	Arnaldo.makeForm("foo", "Ebil");
	cout << endl;

	delete a;
	delete b;
	delete c;
	return EXIT_SUCCESS;
}