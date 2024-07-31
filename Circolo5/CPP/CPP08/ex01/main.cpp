/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:47 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 16:29:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Span.hpp"


using std::cerr;


int main(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.printStorage();
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	// Pushing beyond N elements
	try {
		sp.addNumber(42);
	}
	catch(const std::exception& e) {
		cerr << e.what() << '\n';
	}

	// Trying to get a span with less than 2 elements on the vector
	Span sp1 = Span(1);
	sp1.addNumber(1);
	try {
		std::cout << sp1.shortestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		cerr << e.what() << '\n';
	}

	Span sp2 = Span(5);

	sp2.addRandomNumbers(5);
	std::cout << "sp2 ";
	sp2.printStorage();
	std::cout << "sp2.shortestSpan() = " << sp2.shortestSpan() << std::endl;
	std::cout << "sp2.longestSpan() = " << sp2.longestSpan() << std::endl;
	return EXIT_SUCCESS;
}
