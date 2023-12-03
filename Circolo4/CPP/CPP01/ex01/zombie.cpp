/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:37:28 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/03 12:40:21 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *zom;
    std::string n;

    zom = (Zombie *)malloc(sizeof(Zombie) * N);
    for (int i = 0; i < N; i++)
        zom[i].setname(name + " (" + std::to_string(i+1)+")");
    return (zom);
}