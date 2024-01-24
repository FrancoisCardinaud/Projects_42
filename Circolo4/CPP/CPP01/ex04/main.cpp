/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:46:59 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/24 22:38:49 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

std::string replace_str(std::string buffer, const std::string s1, const std::string s2)
{
	size_t	s1_length = s1.length();
	size_t	s2_length = s2.length();
	size_t	s1_pos = 0;

	s1_pos = buffer.find(s1);

	while (s1_pos != std::string::npos)
	{
		buffer.erase(s1_pos, s1_length);
		buffer.insert(s1_pos, s2);
		s1_pos = buffer.find(s1, s1_pos + s2_length);
	}
	return (buffer);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl << "How to use: ./s2 <filename> <s1> <s2>" << std::endl;
	}
	else
	{
		const std::string filename = argv[1];
		const std::string	s1 = argv[2];
		const std::string	s2 = argv[3];
		std::string			buffer;
		std::ifstream		input_file;
		std::ofstream		output_file;

		input_file.open(argv[1]);
		if (input_file.is_open() == true)
		{
			std::string new_filename = filename + ".replace";
			output_file.open(new_filename.c_str(), std::ios::out | std::ios::trunc);
			if (output_file.is_open() == true)
			{
				while (std::getline(input_file, buffer))
				{
					buffer = replace_str(buffer, s1, s2);
					output_file << buffer;
					if (input_file.peek() != EOF)
						output_file << std::endl;
				}
				output_file.close();
			}
			else
			{
				std::perror("Output file error");
				input_file.close();
				return (1);
			}
			input_file.close();
		}
		else
		{
			std::perror("Input file error");
			std::cout << "Output file not created or truncated." << std::endl;
			return (1);
		}
		return (0);
	}
	return (1);
}