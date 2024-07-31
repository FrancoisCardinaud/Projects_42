/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:14:52 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 17:57:58 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"

AAnimal::AAnimal(void) {
	std::cout << "AANIMAL default constructor has been called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	this->type = other.type;
	std::cout << "AANIMAL copy constructor has been called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "AANIMAL assignment operator has been called" << std::endl;
	return *this;
}

AAnimal::~AAnimal(void) {
	std::cout << "AANIMAL default destructor has been called" << std::endl;
}

std::string AAnimal::getType(void) const {
	return this->type;
}

void AAnimal::setType(std::string type) {
	this->type = type;
}

void AAnimal::makeSound(void) const {
	std::cout << "AANIMAL makeSound() has been called" << std::endl;
}
