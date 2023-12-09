/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:47:27 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/09 17:08:49 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//Constructor
Weapon::Weapon(const std::string &weapon)
{
	this->setType(weapon);
    return ;
}

//Deconstructor
Weapon::~Weapon()
{
	return ;
}

//Getter
std::string Weapon::getType() const
{
	return (_type);
}

//Setter
void Weapon::setType(const std::string &weapon)
{
	_type = weapon;
}