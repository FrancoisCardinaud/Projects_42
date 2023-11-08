/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:57:13 by fcardina          #+#    #+#             */
/*   Updated: 2023/11/08 03:08:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "iostream"
#include <string>

void	ft_putstr(std::string temp)
{
	std::cout << " | ";
	if (temp.size() > 10)
	{
		temp.resize(9);
		std::cout << temp;
		std::cout << ".";
	}
	else
		std::cout << temp;
}

int	main(void)
{
	PhoneBook PB;
	std::string	command;
	int	selector;
	PB.num = 0;

	while (1)
	{
		system("clear");
		std::cout << "command - ADD 1, SEARCH 2, EXIT 3" << std::endl;
		std::cin >> command;
		
		if (command == "ADD" || command == "1")
		{
			system("clear");
			std::cout << "ADD New Contact"<< std::endl;
			
			for (int i = PB.num - 1; i >= 0; i--)
    				PB.Cons[i+1] = PB.Cons[i];
			std::cout << "first name of contact  -> last name -> nick name -> number -> darkest secret" << std::endl;
			std::cin >> PB.Cons[0].name;
			while (PB.Cons[0].name.size() < 10)
				PB.Cons[0].name.append(" ");
			system("clear");

			std::cout << "last name number of -> nick name -> number -> darkest secret";
			std::cout << PB.Cons[0].name << std::endl;
			std::cin >> PB.Cons[0].Last_name;
			while (PB.Cons[0].Last_name.size() < 10)
				PB.Cons[0].Last_name.append(" ");
			system("clear");

			std::cout << "nick name number of -> number -> darkest secret";
			std::cout << PB.Cons[0].name << std::endl;
			std::cin >> PB.Cons[0].Nick_name;
			while (PB.Cons[0].Nick_name.size() < 10)
				PB.Cons[0].Nick_name.append(" ");
			system("clear");

			std::cout << "phone number of -> darkest secret";
			std::cout << PB.Cons[0].name << std::endl;
			std::cin >> PB.Cons[0].phone;
			while (PB.Cons[0].phone.size() < 10)
				PB.Cons[0].phone.append(" ");
			system("clear");

			std::cout << "darkest secret of ";
			std::cout << PB.Cons[0].name << std::endl;
			std::cin >> PB.Cons[0].secret;
			while (PB.Cons[0].secret.size() < 10)
				PB.Cons[0].secret.append(" ");
			if (PB.num < 8)
				PB.num++;
		}

		else if (command == "SEARCH" || command == "2")
		{
			for (int i = 0; i < PB.num; i++)
			{
				std::string temp;
				std::cout << i + 1;
				ft_putstr(PB.Cons[i].name);
				ft_putstr(PB.Cons[i].Last_name);
				ft_putstr(PB.Cons[i].Nick_name);
				ft_putstr(PB.Cons[i].phone);
				ft_putstr(PB.Cons[i].secret);
				std::cout << " | " << std::endl;
			}

			std::cin >> selector;
			selector--;
			system("clear");

			if (selector < PB.num || selector < 0)
			{
				std::cout << PB.Cons[selector].name << std::endl;
				std::cout << PB.Cons[selector].Last_name << std::endl;
				std::cout << PB.Cons[selector].Nick_name << std::endl;
				std::cout << PB.Cons[selector].phone << std::endl;
				std::cout << PB.Cons[selector].secret << std::endl;
			}
			else
			{
				std::cout << "invalid" << std::endl;
				command = "1";
			}
			while (1)
			{
				std::cout << "Type BACK - 1 to go back" << std::endl;
				if (command == "BACK" || command == "1")
					break ;
				std::cin >> command;
			}
		}
		else if (command == "EXIT"  || command == "3")
			break ;
		command = "N";
	}
}