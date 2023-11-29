/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 02:57:13 by fcardina          #+#    #+#             */
/*   Updated: 2023/11/28 16:37:18 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*void	ft_putstr(std::string temp)
{
	std::cout << "|";
	if (temp.size() > 10)
	{
		temp.resize(9);
		std::cout << temp;
		std::cout << ".";
	}
	else
		std::cout << temp;
}*/

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
	PB.num = 0;

	while (1)
	{
		system("clear");
		std::cout << "command - ADD 1, SEARCH 2, EXIT 3" << std::endl; 
		std::cin >> command;
		
		if (command == "ADD" || command == "1")
		{
			int index = PB.num >= 8 ? PB.oldestIndex : PB.num;

			if (PB.num >= 8)  //Check if PB is full
                PB.oldestIndex = (PB.oldestIndex + 1) % 8;  //Update the index of the oldest contact
            else
                PB.num++;

			system("clear");
			std::cout << "ADD New Contact"<< std::endl;
			
			std::cout << "first name -> last name -> nick name -> number -> darkest secret" << std::endl;
			std::cin >> PB.Contact[index].name;
			system("clear");

			std::cout << "last name -> nick name -> number -> darkest secret" << std::endl;
			std::cin >> PB.Contact[index].last_name;
			system("clear");

			std::cout << "nick name -> number -> darkest secret" << std::endl;
			std::cin >> PB.Contact[index].nickname;
			system("clear");

			std::cout << "number -> darkest secret" << std::endl;
			std::cin >> PB.Contact[index].number;
			system("clear");

			std::cout << "darkest secret" << std::endl;
			std::cin >> PB.Contact[index].secret;
			system("clear");
		}

		else if (command == "SEARCH" || command == "2")
		{
			for (int i = 0; i < PB.num; i++)
			{
				std::cout << i + 1;
				ft_sputstr(PB.Contact[i].name);
				ft_sputstr(PB.Contact[i].last_name);
				ft_sputstr(PB.Contact[i].nickname);
				std::cout << "|" << std::endl;
			}
			std::cout << "Choose a contact to display: " << std::endl;
			std::string input;
			std::cin >> input;

			// Check if the input is a valid integer
			if (std::isdigit(input[0])) {
				selector = std::stoi(input);
				selector--; // Adjust the index since we're using 1-based indexing
				system("clear");

				if (selector >= 0 && selector < PB.num)
				{
					std::cout << "First name:      ";
					std::cout << PB.Contact[selector].name << std::endl;
					std::cout << "Last name:       ";
					std::cout << PB.Contact[selector].last_name << std::endl;
					std::cout << "Nickname:        ";
					std::cout << PB.Contact[selector].nickname << std::endl;
					std::cout << "Number:          ";
					std::cout << PB.Contact[selector].number << std::endl;
					std::cout << "Darkest secret:  ";
					std::cout << PB.Contact[selector].secret << std::endl << "\n";
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
