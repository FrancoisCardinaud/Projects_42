/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:50 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 17:57:58 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include "Span.hpp"




Span::Span(uint32_t N) : max_size(N), storage(0) {};

Span::Span(const Span &other) {
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	this->max_size = other.max_size;
	this->storage = other.storage;
	return *this;
}

Span::~Span(void) {};

void Span::addNumber(int nbr)
{
	if (this->storage.size() == this->max_size)
		throw Span::BeyondMaxSize();
	this->storage.push_back(nbr);
}

void Span::addRandomNumbers(uint32_t quantity)
{
	srand(time(NULL));
	try {
		for (uint32_t i = 0; i < quantity; i += 1)
			this->addNumber(rand());
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

int Span::shortestSpan(void)
{
	std::vector<int> v = this->storage;

	if (v.size() < 2) {
		throw Span::NotEnoughElementsException();
	}

	std::sort(v.begin(), v.end());
	int shortest_gap = v.at(1) - v.at(0);

	std::vector<int>::iterator i;
	for (i = v.begin(); i != v.end() - 1; i += 1)
	{
		if (abs(*(i + 1) - *i) < shortest_gap)
			shortest_gap = abs(*(i + 1) - *i); 
	}
	return shortest_gap;
}

int Span::longestSpan(void)
{
	std::vector<int> v = this->storage;

	if (v.size() < 2)
		throw Span::NotEnoughElementsException();

	int min = *std::min_element(v.begin(), v.end());
	int max = *std::max_element(v.begin(), v.end());

	return abs(max - min);
}

void Span::printStorage(void)
{
	std::vector<int> v = this->storage;
	std::vector<int>::iterator i;

	std::cout << "storage = ";
	for (i = v.begin(); i != v.end(); i += 1)
		std::cout << *i << " ";
	std::cout << std::endl;
}

char const* Span::BeyondMaxSize::what(void) const throw() {
	return "Beyond vector's max size";
}

char const* Span::NotEnoughElementsException::what(void) const throw() {
	return "Vector must have at least 2 elements";
}
