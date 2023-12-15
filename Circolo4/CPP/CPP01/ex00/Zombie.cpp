/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:08:29 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/09 16:42:35 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
    this->_name = "Unnamed";
}

Zombie::Zombie(std::string name)
{
    this->set_name(name);
}

void Zombie::set_name(std::string name)
{
    this->_name = name;
}

Zombie::~Zombie(void)
{
    std::cout << this->_name << ": I'm dead...\n";
}

void Zombie::announce(void)
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ...\n";
}
