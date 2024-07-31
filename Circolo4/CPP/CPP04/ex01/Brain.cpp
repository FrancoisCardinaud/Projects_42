/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:12:53 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 17:57:58 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "BRAIN default constructor has been called" << std::endl;
};

Brain::Brain(const Brain &other)
{
    for (size_t i = 0; i < 100; i++)
    {
        this->ideas[i] = other.ideas[i];
    }
    std::cout << "BRAIN copy constructor has been called" << std::endl;
}

Brain& Brain::operator=(const Brain &other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < 100; i++)
        {
            this->ideas[i] = other.ideas[i];
        }
        std::cout << "BRAIN assignment operator has been called" << std::endl;
    }
    return *this;
}

Brain::~Brain(void) {
	std::cout << "BRAIN default destructor has been called" << std::endl;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return ideas[index];
	else
        return "Invalid Index";
}

void Brain::setIdea(int index, const std::string& idea)
{
    if (index >= 0 && index < 100)
    {
        ideas[index] = idea;
    }
}

const std::string *Brain::getIdeaAddress(size_t i)const
{
	if (i < 100)
	{
		const std::string &stringREF = this->ideas[i];
		return(&stringREF);
	}
	else
		return (NULL);
}
