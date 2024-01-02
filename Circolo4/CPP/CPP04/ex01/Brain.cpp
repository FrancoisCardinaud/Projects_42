/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:12:53 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:12:54 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

using std::cout;
using std::endl;

Brain::Brain(void) {
	cout << "[Brain] default constructor has been called" << endl;
};

Brain::Brain(const Brain &to_copy)
{
	*this = to_copy;
	cout << "[Brain] copy constructor has been called" << endl;
}

Brain& Brain::operator=(const Brain &to_copy)
{
	for (size_t i = 0; i < 100; i += 1) {
		this->ideas[i] = to_copy.ideas[i];
	}
	cout << "[Brain] copy assignment constructor has been called" << endl;
	return *this;
}

Brain::~Brain(void) {
	cout << "[Brain] default destructor has been called" << endl;
}
