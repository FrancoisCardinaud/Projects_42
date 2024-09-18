/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:41 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/18 17:22:55 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main(void)
{
	// VECTOR //
	std::vector<int> v1;
	for (int i = 0; i <= 10; i++) {
		v1.push_back(i);
	}

	std::cout << "v1 = ";
	for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// Finding an existing element
	try {
		std::vector<int>::iterator it = easyfind(v1, 0);
		std::cout << "Found element: " << *it << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	
	// Attempting to find a non-existent element
	try {
		easyfind(v1, 20);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return EXIT_SUCCESS;
}
