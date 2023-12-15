/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:21:04 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/03 12:35:15 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main(void) 
{
	Zombie	*heap;
	heap = newZombie("Heap Zombie");
	heap->announce();
	randomChump("Stack Zombie");
	delete heap;
	return (0);
}
