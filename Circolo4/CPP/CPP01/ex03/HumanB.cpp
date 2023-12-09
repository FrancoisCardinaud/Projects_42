/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:46:47 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/09 17:09:54 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructor
HumanB::HumanB(std::string name)
{
	this->_name = name;
	this->_is_armed = false;
}

// Deconstructor
HumanB::~HumanB(void)
{
 	return ;
}

// Setter
void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	this->_is_armed = true;
	std::cout << this->_name << " grabbed a " << this->_weapon->getType() << std::endl;
}

// Public Methods
void HumanB::attack(void)
{
    if (this->_is_armed)
    {
        std::cout << this->_name << " attacks with his " << this->_weapon->getType() << std::endl;
    }
    else
    {
        std::cout << this->_name << " attacks with his fists." << std::endl;
    }
}