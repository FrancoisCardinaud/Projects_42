/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:56 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 16:29:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "MutantStack.hpp"


using std::cerr;


int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	MutantStack<int> ms;
	ms.push(1);
	ms.push(2);
	ms.push(3);
	ms.push(4);
	ms.push(5);

	MutantStack<int>::iterator begin = ms.begin();
	MutantStack<int>::iterator end = ms.end();

	std::cout << "stack = ";
	while (begin != end)
	{
		std::cout << *begin << " ";
		begin += 1;
	}

	std::cout << std::endl;
	return EXIT_SUCCESS;
}
