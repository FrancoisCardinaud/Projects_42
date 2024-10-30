#include <iostream>
#include <vector>
#include <list>
#include <deque>
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
        std::vector<int>::iterator it = easyfind(v1, 7);
        std::cout << "Found element in vector: " << *it << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    // Attempting to find a non-existent element in vector
    try {
        easyfind(v1, 20);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "------------------------------" << std::endl;

    // LIST //
    std::list<int> l1;
    for (int i = 10; i >= 0; i--) {
        l1.push_back(i);
    }

    std::cout << "l1 = ";
    for (std::list<int>::iterator it = l1.begin(); it != l1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Finding an existing element in list
    try {
        std::list<int>::iterator it = easyfind(l1, 4);
        std::cout << "Found element in list: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Attempting to find a non-existent element in list
    try {
        easyfind(l1, 100);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "------------------------------" << std::endl;

    // DEQUE //
    std::deque<int> d1;
    for (int i = 5; i <= 10; i++) {
        d1.push_back(i);
    }

    std::cout << "d1 = ";
    for (std::deque<int>::iterator it = d1.begin(); it != d1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Finding an existing element in deque
    try {
        std::deque<int>::iterator it = easyfind(d1, 9);
        std::cout << "Found element in deque: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    // Attempting to find a non-existent element in deque
    try {
        easyfind(d1, -1);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
