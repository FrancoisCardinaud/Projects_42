/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:12:42 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 17:57:58 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WRONG CAT default constructor has been called" << std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	this->type = other.type;
	std::cout << "WRONG CAT copy constructor has been called " << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << "WRONG CAT assignment operator has been called " << std::endl;
	return *this;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WRONG CAT default destructor has been called" << std::endl;
}

void WrongCat::makeSound(void) const
{
	std::cout << "\"Wrong Meow...\"" << std::endl;
}
