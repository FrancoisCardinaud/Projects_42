/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:01 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:29:02 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <stdint.h>
# include <iostream>

using std::cout;
using std::endl;

template <typename T>
void print_element(T &array_element) {
	cout << array_element << endl;
}

template <typename T>
void plus_one(T &n) {
	n += 1;
}

template <typename T>
void iter(T *address, size_t length, void(*fn)(T&))
{
	for (size_t i = 0; i < length; i += 1) {
		fn(address[i]);
	}
}

#endif // ITER_HPP