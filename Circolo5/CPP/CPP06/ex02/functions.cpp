/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:27:03 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 16:29:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>


using std::cerr;


Base *generate(void)
{
	srand(time(NULL));
	char c = "ABC"[rand() % 3];

	std::cout << "Type " << c << " created!" << std::endl;
	switch (c)
	{
		case 'A':
			return new A;
		case 'B':
			return new B;
		case 'C':
			return new C;
	}
	return NULL;
}

void identify(Base *p)
{
	// just to shut "unused-value" compiler warning
	bool sucessfully_casted;

	std::cout << "Identify with Base *: ";

	sucessfully_casted = dynamic_cast<A *>(p);
	if (sucessfully_casted)
	{
		std::cout << "A" << std::endl;
		return ;
	}
	sucessfully_casted = dynamic_cast<B *>(p);
	if (sucessfully_casted)
	{
		std::cout << "B" << std::endl;
		return ;
	}
	sucessfully_casted = dynamic_cast<C *>(p);
	if (sucessfully_casted)
	{
		std::cout << "C" << std::endl;
		return ;
	}
	if (!sucessfully_casted)
		std::cout << "Invalid type" << std::endl;
}

void identify(Base &p)
{
	std::cout << "Identify with Base &: ";
	try {
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (const std::exception& e) {
		try {
			B &b = dynamic_cast<B &>(p);
			(void)b;
			std::cout << "B" << std::endl;
		}
		catch (const std::exception& e) {
			try {
				C &c = dynamic_cast<C &>(p);
				(void)c;
				std::cout << "C" << std::endl;
			}
			catch (const std::exception& e) {
				std::cout << "Invalid type" << std::endl;
			}
		}
	}
}
