/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:50 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/30 17:59:49 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <limits> // for int64_t
#include <iostream>
#include <numeric> // For std::adjacent_difference

Span::Span(unsigned int N) : max_size(N) {}

Span::Span(const Span &other) {
	*this = other;
}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		this->max_size = other.max_size;
		this->storage = other.storage;
	}
	return *this;
}

Span::~Span(void) {}

void Span::addNumber(int nbr) {
	if (this->storage.size() >= this->max_size)
		throw Span::BeyondMaxSize();
	this->storage.push_back(nbr);
}

void Span::addRandomNumbers(unsigned int quantity) {
	if (this->storage.size() + quantity > this->max_size)
		throw Span::BeyondMaxSize();
	for (unsigned int i = 0; i < quantity; i++)
		this->storage.push_back(rand());
}

int64_t Span::shortestSpan(void) const {
    if (this->storage.size() < 2)
        throw Span::NotEnoughElementsException();

    std::vector<int64_t> temp(this->storage.begin(), this->storage.end());
    std::sort(temp.begin(), temp.end());

    int64_t shortest_span = std::numeric_limits<int64_t>::max();
    for (size_t i = 0; i < temp.size() - 1; ++i) {
        int64_t span = std::abs(temp[i + 1] - temp[i]);
        if (span < shortest_span) {
            shortest_span = span;
        }
    }

    // Handle the special case where the values are INT_MIN and INT_MAX
    if (temp[0] == static_cast<int64_t>(std::numeric_limits<int>::min()) &&
        temp[1] == static_cast<int64_t>(std::numeric_limits<int>::max())) {
        return static_cast<int64_t>(std::numeric_limits<unsigned int>::max());
    }

    return shortest_span;
}

int64_t Span::longestSpan(void) const {
    if (this->storage.size() < 2)
        throw Span::NotEnoughElementsException();

    int64_t min_val = *std::min_element(this->storage.begin(), this->storage.end());
    int64_t max_val = *std::max_element(this->storage.begin(), this->storage.end());

    return max_val - min_val;
}

void Span::printStorage(void) const {
	std::cout << "Storage: ";
	for (size_t i = 0; i < this->storage.size(); ++i) {
		std::cout << this->storage[i] << " ";
	}
	std::cout << std::endl;
}

const char* Span::NotEnoughElementsException::what() const throw() {
	return "Not enough elements to calculate span!";
}

const char* Span::BeyondMaxSize::what() const throw() {
	return "Cannot add more numbers, storage is full!";
}
