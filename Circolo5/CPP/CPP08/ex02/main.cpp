/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:56 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/30 18:20:34 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MutantStack.hpp"
#include <iostream>

int main() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl; // Should output 17
    mstack.pop();
    std::cout << mstack.size() << std::endl; // Should output 1

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;

    while (it != ite) {
        std::cout << *it << std::endl; // Should output all elements in order
        ++it;
    }

    std::stack<int> s(mstack); // Copy into std::stack to test compatibility
    return 0;
}

/*
#include <list>
#include <iostream>

int main() {
    std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << mstack.back() << std::endl; // `back` to mimic `top`
    mstack.pop_back();
    std::cout << mstack.size() << std::endl;

    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);

    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    return 0;
}
*/

/*
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

    return 0;
}
*/