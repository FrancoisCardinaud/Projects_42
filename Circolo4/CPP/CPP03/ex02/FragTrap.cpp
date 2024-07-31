/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:58:45 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 16:29:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"




FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "Default FragTrap constructor "<< name <<" was called!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor "<< name <<" has been called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (this->_energy_points == 0) {
        cout << "FragTrap "<< this->name << " has no more energy points!" << std::endl;
        return;
    }
	std::cout << "FragTrap " << this->name << " says \"High Five!\"" << std::endl;
    this->_energy_points -= 1;
}