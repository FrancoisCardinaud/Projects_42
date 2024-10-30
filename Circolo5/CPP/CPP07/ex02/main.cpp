/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:12 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/29 18:19:03 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
void displayArray(const Array<T>& array, const std::string& name) {
    for (std::size_t i = 0; i < array.size(); i++) {
        std::cout << name << "[" << i << "] = " << array[i] << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Test 1: Default array with integers" << std::endl;
    Array<int> a(3);
    Array<int> b(3);

    std::cout << "Initial values of array A and B:" << std::endl;
    displayArray(a, "a");
    displayArray(b, "b");

    // Fill array a with 1's
    for (std::size_t i = 0; i < a.size(); i++) {
        a[i] = 1;
    }

    std::cout << "After filling array A with 1's:" << std::endl;
    displayArray(a, "a");

    // Assign array a to array b
    b = a;

    std::cout << "After assigning array A to B:" << std::endl;
    displayArray(a, "a");
    displayArray(b, "b");
    std::cout << "--------------------------" << std::endl;
    
    std::cout << "Test 2: Out-of-bounds access" << std::endl;
    try {
        std::cout << "Accessing out-of-bounds element in array A:" << std::endl;
        std::cout << a[a.size() + 1] << std::endl;  // This should throw an exception
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
    
    std::cout << "Test 3: Empty array" << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    std::cout << "--------------------------" << std::endl;
    
    std::cout << "Test 4: Array of strings" << std::endl;
    Array<std::string> strArray(2);
    strArray[0] = "Hello";
    strArray[1] = "World";
    std::cout << "String array:" << std::endl;
    displayArray(strArray, "strArray");
    std::cout << "--------------------------" << std::endl;
    
    std::cout << "Test 5: Assigning string array" << std::endl;
    Array<std::string> anotherStrArray(2);
    anotherStrArray = strArray;
    std::cout << "After assigning string array:" << std::endl;
    displayArray(anotherStrArray, "anotherStrArray");
    std::cout << "--------------------------" << std::endl;
    
    std::cout << "Test 6: Access out-of-bounds in string array" << std::endl;
    try {
        std::cout << "Accessing out-of-bounds element in string array:" << std::endl;
        std::cout << strArray[5] << std::endl;  // This should throw an exception
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
    
    std::cout << "Test 7: Array of doubles" << std::endl;
    Array<double> doubleArray(3);
    doubleArray[0] = 3.14;
    doubleArray[1] = 2.71;
    doubleArray[2] = 1.41;
    std::cout << "Double array:" << std::endl;
    displayArray(doubleArray, "doubleArray");
    std::cout << "--------------------------" << std::endl;

    std::cout << "Test 8: Assigning array of doubles" << std::endl;
    Array<double> anotherDoubleArray(2);
    anotherDoubleArray = doubleArray;
    std::cout << "After assigning doubles array:" << std::endl;
    displayArray(anotherDoubleArray, "anotherDoubleArray");

    return 0;
}