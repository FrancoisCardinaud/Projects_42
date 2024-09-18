/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:56 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/18 17:42:55 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <cstdlib>
#include <iostream>
#include <list>

int main() {
	// Create a MutantStack and push elements
	MutantStack<int> ms;
	ms.push(1);
	ms.push(2);
	ms.push(3);
	ms.push(4);
	ms.push(5);

	// Obtain iterators for the stack
	MutantStack<int>::iterator begin = ms.begin();
	MutantStack<int>::iterator end = ms.end();

	// Print stack contents using iterators
	std::cout << "Stack = ";
	while (begin != end) {
		std::cout << *begin << " ";
		++begin;  // Use pre-increment for performance optimization
	}

	std::cout << std::endl;
	return (EXIT_SUCCESS);
}

/*int	main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return (0);
}*/

/*int	main(void)
{
	std::list<int> mstack;
	// Push elements (equivalent to mstack.push())
	mstack.push_back(5);
	mstack.push_back(17);
	// Display the top element (last element in the list)
	std::cout << "Top element: " << mstack.back() << std::endl;
	// Pop the top element (equivalent to mstack.pop())
	mstack.pop_back();
	// Display the current size of the list (equivalent to mstack.size())
	std::cout << "Stack size: " << mstack.size() << std::endl;
	// Push more elements (equivalent to mstack.push())
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);
	// Using forward iterator (equivalent to MutantStack's begin() and end())
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	std::cout << "List contents (forward): ";
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	// Copy the list (equivalent to MutantStack copy)
	std::list<int> mstack_copy(mstack);
	std::cout << "Copied list contents: ";
	for (std::list<int>::iterator i = mstack_copy.begin(); i != mstack_copy.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	return (0);
}*/
