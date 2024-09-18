/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:50 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/18 17:26:19 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>

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

int Span::shortestSpan(void) const {
	if (this->storage.size() < 2)
		throw Span::NotEnoughElementsException();
	
	std::vector<int> temp = this->storage;
	std::sort(temp.begin(), temp.end());

	int shortest_span = temp[1] - temp[0];
	for (size_t i = 1; i < temp.size() - 1; ++i) {
		int span = temp[i + 1] - temp[i];
		if (span < shortest_span)
			shortest_span = span;
	}
	return shortest_span;
}

int Span::longestSpan(void) const {
	if (this->storage.size() < 2)
		throw Span::NotEnoughElementsException();
	
	int min_val = *std::min_element(this->storage.begin(), this->storage.end());
	int max_val = *std::max_element(this->storage.begin(), this->storage.end());

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
