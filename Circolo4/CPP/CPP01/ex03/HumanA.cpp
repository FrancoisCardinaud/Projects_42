/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:48:28 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/24 22:38:49 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructor
HumanA::HumanA(std::string name, Weapon &weapon):_weapon(weapon)
{
	this->name = name;
	std::cout << this->name <<" grabbed a " << this->_weapon.getType() << std::endl;
}

// Deconstructor
HumanA::~HumanA(void)
{
 	return ;
}

// Public Methods
void HumanA::attack(void)
{
    std::cout << this->name << " attacks with his " << this->_weapon.getType() << std::endl;
}