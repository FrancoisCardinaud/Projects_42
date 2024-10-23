/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:56 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/23 20:50:57 by fcardina         ###   ########.fr       */
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

    // Print the top element
    std::cout << "Top element: " << ms.top() << std::endl;

    // Print size of stack
    std::cout << "Stack size: " << ms.size() << std::endl;

    // Obtain iterators for the stack
    MutantStack<int>::iterator begin = ms.begin();
    MutantStack<int>::iterator end = ms.end();

    // Print stack contents using iterators
    std::cout << "Stack (forward): ";
    while (begin != end) {
        std::cout << *begin << " ";
        ++begin;
    }
    std::cout << std::endl;

    // Reverse iterate through the stack
    std::cout << "Stack (reverse): ";
    MutantStack<int>::iterator rbegin = ms.end();
    while (rbegin != ms.begin()) {
        --rbegin;
        std::cout << *rbegin << " ";
    }
    std::cout << std::endl;

    // Test copying the MutantStack
    MutantStack<int> ms_copy(ms);
    ms_copy.push(42);  // Modify the copy

    std::cout << "Original stack after copy: ";
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "Copied stack with modification: ";
    for (MutantStack<int>::iterator it = ms_copy.begin(); it != ms_copy.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    return (EXIT_SUCCESS);
}
