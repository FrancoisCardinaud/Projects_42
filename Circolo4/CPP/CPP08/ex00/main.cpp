/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:41 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:29:42 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

using std::cout;
using std::cerr;
using std::endl;

int main(void)
{
	// VECTOR //
	std::vector<int> v1;
	for (size_t i = 0; i <= 10; i += 1) {
		v1.push_back(i);
	}

	cout << "v1 = ";
	for (std::vector<int>::iterator i = v1.begin(), e = v1.end(); i != e; i += 1) {
		cout << *i << " ";
	}
	cout << endl;

	// will find
	try {
		easyfind(v1, 0);
	}
	catch (const std::exception& e) {
		cerr << e.what() << '\n';
	}
	
	// will raise EasyFindException
	try {
		easyfind(v1, 20);
	}
	catch (const std::exception& e) {
		cerr << e.what() << '\n';
	}
	return EXIT_SUCCESS;
}
