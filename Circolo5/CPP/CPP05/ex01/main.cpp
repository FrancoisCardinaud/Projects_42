/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:24:46 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 16:29:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "Form.hpp"


using std::cerr;


int main(void)
{
	std::cout << "GENERAL" << std::endl;
	{
		// Constructor
		Form	a("Contract", 42, 42);
		// Copy Constructor
		Form	b(a);
		// Copy assignment
		Form	c = b;

		// ostream overload
		std::cout << "a:\n" << a << std::endl;
		std::cout << "b:\n" << b << std::endl;
		std::cout << "c:\n" << c << std::endl;
	}

	std::cout << std::endl;

	{
		std::cout << "TEST 1" << std::endl;
		try
		{
			// Grade too low
			Form	a("A", LOWEST_GRADE + 1, LOWEST_GRADE - 1);
			std::cout << a << std::endl;
		}
		catch (std::exception& e) {
			cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "TEST 2" << std::endl;
		try
		{
			// Grade too high
			Form	b("B", HIGHEST_GRADE - 1, 42);
			std::cout << b << std::endl;
		}
		catch (std::exception& e) {
			cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "TEST 3" << std::endl;
		try
		{
			// Able to sign all forms
			Bureaucrat	s1("Student1", HIGHEST_GRADE);
			std::cout << s1 << std::endl;

			Form	c1("C1", HIGHEST_GRADE, 2);
			Form	c2("C2", 90, LOWEST_GRADE);
			std::cout << c1 << std::endl;
			std::cout << c2 << std::endl;

			c1.beSigned(s1);
			c2.beSigned(s1);
			c1.beSigned(s1);

			std::cout << c1 << std::endl;
			std::cout << c2 << std::endl;
		}
		catch (std::exception& e) {
			cerr << e.what() << std::endl;
		}

		std::cout << std::endl;

		std::cout << "TEST 4" << std::endl;
		try
		{
			// Unable to sign any form
			Bureaucrat	s2("Student2", LOWEST_GRADE);
			std::cout << s2 << std::endl;

			Form	c3("C3", HIGHEST_GRADE, 2);
			std::cout << c3 << std::endl;

			// Exception will be thrown
			c3.beSigned(s2);
			std::cout << c3 << std::endl;
		}
		catch (std::exception& e) {
			cerr << e.what() << std::endl;
		}
	}
	return EXIT_SUCCESS;
}
