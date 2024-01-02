/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:11:41 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:11:50 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

using std::cout;
using std::endl;

Cat::Cat(void) : Animal() {
	cout << "[Cat] default constructor has been called" << endl;
	this->setType("Cat");
}

Cat::Cat(const Cat &to_copy) : Animal(to_copy)
{
	*this = to_copy;
	cout << "[Cat] copy constructor has been called " << endl;
}

Cat& Cat::operator=(const Cat &to_copy)
{
	this->type = to_copy.type;
	cout << "[Cat] copy assignment constructor has been called " << endl;
	return *this;
}

Cat::~Cat(void) {
	cout << "[Cat] default destructor has been called" << endl;
}

void Cat::makeSound(void) const {
	cout << "Miau Miau 🐈" << endl;
}
