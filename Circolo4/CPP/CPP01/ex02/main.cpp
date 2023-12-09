/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:45:37 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/09 16:40:34 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdio.h>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Memory address of the string variable: " << (void*)&str << std::endl;
    std::cout << "Memory address of stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address of stringREF: " << &stringREF << std::endl;

    std::cout << "Value of the string variable: " << str << std::endl;
    std::cout << "String data using stringPTR: " << *stringPTR << std::endl;
    std::cout << "String data using stringREF: " << stringREF << std::endl;
}