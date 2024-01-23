/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:58:45 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 18:58:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

using std::cout;
using std::endl;

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	cout << "Sub Class (FragTrap) constructor has been called" << endl;
}

FragTrap::~FragTrap(void) {
	cout << "Sub Class (FragTrap) destructor has been called" << endl;
}

void FragTrap::highFivesGuys(void) {
	if (this->_energy_points == 0) {
        cout << "FragTrap "<< this->name << " is out of energy points!" << endl;
        return;
    }
	cout << "FragTrap " << this->name << " says: High Fives!" << endl;
    this->_energy_points -= 1;
}