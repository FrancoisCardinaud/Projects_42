/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:57:01 by fcardina          #+#    #+#             */
/*   Updated: 2023/11/08 02:57:02 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>

class Contact
{
	public:
	std::string		name;
	std::string		last_name;
	std::string		nickname;
	std::string		number;
	std::string		secret;

	void	display(void)
	{
		std::cout << name;
		std::cout << " : ";
		std::cout << number << std::endl;
	}
};

class PhoneBook
{
    public:
        Contact Contact[8];
        int num;
        int oldestIndex; // Index of the oldest contact

        PhoneBook() : num(0), oldestIndex(0) {} // Constructor to initialize
};

#endif