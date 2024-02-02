/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:11:41 by fcardina          #+#    #+#             */
/*   Updated: 2024/02/02 16:07:32 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "CAT default constructor has been called" << std::endl;
	this->setType("Cat");
}

Cat::Cat(const Cat &to_copy) : Animal(to_copy)
{
	*this = to_copy;
	std::cout << "CAT copy constructor has been called " << std::endl;
}

Cat& Cat::operator=(const Cat &to_copy)
{
	this->type = to_copy.type;
	std::cout << "CAT copy assignment constructor has been called " << std::endl;
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "CAT default destructor has been called" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "\"Meow...\"" << std::endl;
}
