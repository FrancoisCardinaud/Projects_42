/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:48:28 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/09 17:10:52 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructor
HumanA::HumanA(std::string name, Weapon &weapon):_weapon(weapon)
{
	this->_name = name;
	std::cout << this->_name <<" grabbed a " << this->_weapon.getType() << std::endl;
}

// Deconstructor
HumanA::~HumanA(void)
{
 	return ;
}

// Public Methods
void HumanA::attack(void)
{
    std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}