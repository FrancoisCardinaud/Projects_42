/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:09:03 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/03 12:33:52 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    public:

    void    set_name(std::string name);

    void    announce(void);

    Zombie(void);
    Zombie(std::string name);
    ~Zombie(void);

    private:

    std::string _name;
};

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

#endif