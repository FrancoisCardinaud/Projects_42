/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:01 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/29 16:27:06 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void print_element(const T &element) {
	std::cout << element << std::endl;
}

template <typename T>
void increment(T &n) {
	n += 1;
}

template <typename T>
void iter(T *array, size_t length, void(*fn)(T&))
{
	for (size_t i = 0; i < length; ++i) {
		fn(array[i]);
	}
}

template <typename T>
void iter(const T *array, size_t length, void(*fn)(const T&))
{
	for (size_t i = 0; i < length; ++i) {
		fn(array[i]);
	}
}

#endif

