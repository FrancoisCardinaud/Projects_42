/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:31:08 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/18 19:17:03 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <list>

# define MICROSECOND 100000

unsigned int ft_stou(const std::string& str);

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    *this = other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}

static void printVec(const std::vector<unsigned int>& vec) {
	for (std::vector<unsigned int>::const_iterator itr = vec.begin(); itr != vec.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

static std::vector<unsigned int> mergeVecs(std::vector<unsigned int>& left, std::vector<unsigned int>& right) {
    std::vector<unsigned int> result;
    while (!left.empty() && !right.empty()) {
        if (left.front() <= right.front()) {
            result.push_back(left.front());
            left.erase(left.begin());
        } else {
            result.push_back(right.front());
            right.erase(right.begin());
        }
    }
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}

static std::vector<unsigned int> mergeInsertVec(std::vector<unsigned int>& vec) {
    if (vec.size() <= 1)
        return vec;

    int mid = vec.size() / 2;
    std::vector<unsigned int> left(vec.begin(), vec.begin() + mid);
    std::vector<unsigned int> right(vec.begin() + mid, vec.end());

    left = mergeInsertVec(left);
    right = mergeInsertVec(right);

    return mergeVecs(left, right);
}

void PmergeMe::sortVec(int argc, char **argv) {
	std::vector<unsigned int> storage;

	for (int i = 1; i < argc; i++)
		storage.push_back(ft_stou(argv[i]));

	std::cout << "<vec>Before: ";
	printVec(storage);

	std::clock_t start = std::clock();
	storage = mergeInsertVec(storage);
	double time_taken = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC * MICROSECOND;

	std::cout << "<vec>After: ";
	printVec(storage);
	std::cout << "Time to process a range of " << argc - 1
			  << " elements with std::vector<unsigned int>: "
			  << time_taken << " µs" << std::endl;
}

static void printList(const std::list<unsigned int>& lst) {
	for (std::list<unsigned int>::const_iterator itr = lst.begin(); itr != lst.end(); itr++)
		std::cout << *itr << " ";
	std::cout << std::endl;
}

static std::list<unsigned int> mergeLists(std::list<unsigned int>& left, std::list<unsigned int>& right) {
    std::list<unsigned int> result;
    while (!left.empty() && !right.empty()) {
        if (left.front() <= right.front()) {
            result.push_back(left.front());
            left.pop_front();
        } else {
            result.push_back(right.front());
            right.pop_front();
        }
    }
    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}

static std::list<unsigned int> mergeInsertList(std::list<unsigned int>& lst) {
    if (lst.size() <= 1)
        return lst;

    int mid = lst.size() / 2;
    std::list<unsigned int> left, right;
    for (int i = 0; i < mid; i++) {
        left.push_back(lst.front());
        lst.pop_front();
    }
    right = lst;

    left = mergeInsertList(left);
    right = mergeInsertList(right);

    return mergeLists(left, right);
}

void PmergeMe::sortList(int argc, char **argv) {
	std::list<unsigned int> storage;
	for (int i = 1; i < argc; i++)
		storage.push_back(ft_stou(argv[i]));

	std::cout << "<list>Before: ";
	printList(storage);

	std::clock_t start = std::clock();
	storage = mergeInsertList(storage);
	double time_taken = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC * MICROSECOND;

	std::cout << "<list>After: ";
	printList(storage);
	std::cout << "Time to process a range of " << argc - 1
			  << " elements with std::list<unsigned int>: "
			  << time_taken << " µs" << std::endl;
}

const char*	PmergeMe::InvalidElementException::what() const throw() {
	return "PmergeMe exception: invalid element";
}
