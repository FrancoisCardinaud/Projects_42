/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:38:00 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/03 12:38:01 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <stdio.h>
#include <string>

class Zombie 
{
	private:

	std::string name;

	public:

	void announce( void )
	{
		std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	};
	void setname(std::string name)
	{
		this->name = name;
	};
	void distroyz(void)
	{
		std::cout << this->name << ": destroying"<< std::endl;
	};
};

Zombie* zombieHorde( int N, std::string name );

# endif