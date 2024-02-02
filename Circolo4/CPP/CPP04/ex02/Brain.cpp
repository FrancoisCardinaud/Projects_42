/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:12:53 by fcardina          #+#    #+#             */
/*   Updated: 2024/02/02 19:09:59 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

using std::cout;
using std::endl;

Brain::Brain(void) {
	cout << "BRAIN default constructor has been called" << endl;
};

Brain::Brain(const Brain &to_copy)
{
    for (size_t i = 0; i < 100; i++)
    {
        this->ideas[i] = to_copy.ideas[i];
    }
    cout << "BRAIN copy constructor has been called" << endl;
}

Brain& Brain::operator=(const Brain &to_copy)
{
    if (this != &to_copy)
    {
        for (size_t i = 0; i < 100; i++)
        {
            this->ideas[i] = to_copy.ideas[i];
        }
        cout << "BRAIN copy assignment constructor has been called" << endl;
    }
    return *this;
}

Brain::~Brain(void) {
	cout << "BRAIN default destructor has been called" << endl;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return ideas[index];
	else
        return "Invalid Index";
}
