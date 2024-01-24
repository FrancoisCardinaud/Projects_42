/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:09:03 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/24 22:38:49 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    public:

    Zombie(void);
    Zombie(std::string name);
    ~Zombie(void);
    
    void    setname(std::string name);
    void    announce(void);

    private:

    std::string name;
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif