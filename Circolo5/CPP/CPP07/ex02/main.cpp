/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:12 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/18 17:08:41 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

void displayArray(const Array<int>& array, const std::string& name) {
    for (uint32_t i = 0; i < array.size(); i++) {
        std::cout << name << "[" << i << "] = " << array[i] << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    Array<int> a(3);
    Array<int> b(3);

    std::cout << "Initial values of array A and B:" << std::endl;
    displayArray(a, "a");
    displayArray(b, "b");

    // Fill array a with 1's
    for (uint32_t i = 0; i < a.size(); i++) {
        a[i] = 1;
    }

    std::cout << "After filling array A with 1's:" << std::endl;
    displayArray(a, "a");

    // Assign array a to array b
    b = a;

    std::cout << "After assigning array A to B:" << std::endl;
    displayArray(a, "a");
    displayArray(b, "b");

    // Test out-of-bounds access
    try {
        std::cout << "Accessing out-of-bounds element in array A:" << std::endl;
        std::cout << a[a.size()] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test empty array
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;

    return 0;
}
