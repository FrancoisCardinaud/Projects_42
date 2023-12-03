/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:08:29 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/03 12:31:34 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie::Zombie(void)
{
    this->_name = "unnamed";
}

Zombie::Zombie(std::string name)
{
    this->set_name(name);
}

Zombie::~Zombie(void)
{
    std::cout << "<" << this->_name << "> " << "Gharrrgl...\n";
}

void Zombie::set_name(std::string name)
{
    this->_name = name;
}

void Zombie::announce(void)
{
    std::cout << "<" << this->_name << "> BraiiiiiiinnnzzzZ...\n";
}

void randomChump(std::string name)
{
    Zombie randomZombie(name); 
    randomZombie.announce();
}

Zombie* newZombie(std::string name)
{
    Zombie *my_zombie = new Zombie;
    my_zombie->set_name(name);
    return (my_zombie);
}