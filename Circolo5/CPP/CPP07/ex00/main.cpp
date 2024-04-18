/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:28:54 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:28:54 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>
#include <whatever.hpp>

using std::cout;
using std::endl;

int main(void)
{
	int a = 2;
	int b = 3;

	::swap(a, b);

	cout << "a = " << a << ", b = " << b << endl;
	cout << "min(a, b) = " << ::min(a, b) << endl;
	cout << "max(a, b) = " << ::max(a, b) << endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);

	cout << "c = " << c << ", d = " << d << endl;
	cout << "min(c, d) = " << ::min(c, d) << endl;
	cout << "max(c, d) = " << ::max(c, d) << endl;

	return EXIT_SUCCESS;
}
