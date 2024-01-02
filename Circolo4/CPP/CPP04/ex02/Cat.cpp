/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:15:04 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:15:04 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

using std::cout;
using std::endl;

Cat::Cat(void) : AAnimal() {
	cout << "[Cat] default constructor has been called" << endl;
	this->setType("Cat");
	try {
		this->brain = new Brain();
	}
	catch (const std::bad_alloc& e) {
		cout << "[Cat] Brain memory allocation failed: " << e.what() << endl;
	}
}

Cat::Cat(const Cat &to_copy) : AAnimal(to_copy)
{
	this->type = to_copy.type;
	this->brain = new Brain();
	cout << "[Cat] copy constructor has been called " << endl;
}

Cat& Cat::operator=(const Cat &to_copy)
{
	if (this != &to_copy)
		this->type = to_copy.type;
	cout << "[Cat] copy assignment constructor has been called " << endl;
	return *this;
}

Cat::~Cat(void)
{
	cout << "[Cat] default destructor has been called" << endl;
	delete this->brain;
}

void Cat::makeSound(void) const {
	cout << "Miau Miau 🐈" << endl;
}
