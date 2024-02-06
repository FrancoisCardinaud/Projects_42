/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:14:52 by fcardina          #+#    #+#             */
/*   Updated: 2024/02/03 19:32:08 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"

using std::cout;
using std::endl;

AAnimal::AAnimal(void) {
	cout << "AANIMAL default constructor has been called" << endl;
}

AAnimal::AAnimal(const AAnimal &to_copy)
{
	this->type = to_copy.type;
	cout << "AANIMAL copy constructor has been called" << endl;
}

AAnimal& AAnimal::operator=(const AAnimal &to_copy)
{
	if (this != &to_copy)
		this->type = to_copy.type;
	cout << "AANIMAL assignment operator has been called" << endl;
	return *this;
}

AAnimal::~AAnimal(void) {
	cout << "AANIMAL default destructor has been called" << endl;
}

std::string AAnimal::getType(void) const {
	return this->type;
}

void AAnimal::setType(std::string type) {
	this->type = type;
}

void AAnimal::makeSound(void) const {
	cout << "AANIMAL makeSound() has been called" << endl;
}
