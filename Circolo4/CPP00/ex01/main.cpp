/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:57:13 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/01 16:55:51 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void ft_sputstr(std::string temp)
{
    const int fieldWidth = 10; // Define the total width of the field

    if (temp.size() > 10)
    {
        temp = temp.substr(0, 9) + "."; // Truncate and add a dot if longer than 10 characters
    }
	std::cout << "|";
    std::cout << std::right << std::setw(fieldWidth) << temp;
}


int	main(void)
{
	PhoneBook PB;
	std::string	command;
	int	selector;

	while (1)
	{
		system("clear");
		std::cout << "command - ADD 1, SEARCH 2, EXIT 3" << std::endl; 
		std::cin >> command;
		
		if (command == "ADD" || command == "1")
		{
			int index = PB.getNum() >= 8 ? PB.getOldestIndex() : PB.getNum();

			if (PB.getNum() >= 8) 
			{
				PB.setOldestIndex((PB.getOldestIndex() + 1) % 8);
			}
			else 
			{
				PB.setNum(PB.getNum() + 1);
			}

			system("clear");
			std::cout << "ADD New Contact"<< std::endl;
			
			std::string input;
			std::cout << "Enter first name: ";
			std::cin >> input;
			PB.getContact(index).setName(input);

			std::cout << "Enter last name: ";
			std::cin >> input;
			PB.getContact(index).setLastName(input);

			std::cout << "Enter nickname: ";
			std::cin >> input;
			PB.getContact(index).setNickname(input);

			std::cout << "Enter number: ";
			std::cin >> input;
			PB.getContact(index).setNumber(input);

			std::cout << "Enter darkest secret: ";
			std::cin >> input;
			PB.getContact(index).setSecret(input);
		}

		else if (command == "SEARCH" || command == "2")
		{
			for (int i = 0; i < PB.getNum(); i++)
			{
				std::cout << i + 1;
				ft_sputstr(PB.getContact(i).getName());
				ft_sputstr(PB.getContact(i).getLastName());
				ft_sputstr(PB.getContact(i).getNickname());
				std::cout << std::endl;
			}
			std::cout << "Choose a contact to display: " << std::endl;
			std::string input;
			std::cin >> input;

			// Check if the input is a valid integer
			if (std::isdigit(input[0])) {
				selector = std::stoi(input);
				selector--; // Adjust the index since we're using 1-based indexing
				system("clear");

				if (selector >= 0 && selector < PB.getNum())
				{
					std::cout << "First name: " << PB.getContact(selector).getName() << std::endl;
					std::cout << "Last name: " << PB.getContact(selector).getLastName() << std::endl;
					std::cout << "Nickname: " << PB.getContact(selector).getNickname() << std::endl;
					std::cout << "Number: " << PB.getContact(selector).getNumber() << std::endl;
					std::cout << "Darkest secret: " << PB.getContact(selector).getSecret() << std::endl;
					std::cout << "\n";
				}
				else
				{
					std::cout << "Invalid index" << std::endl;
					//command = "1";
				}
			}
			else
			{
				std::cout << "Invalid input. Please enter a valid number." << std::endl;
				// Optionally, you can clear the input buffer to prevent further issues
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
