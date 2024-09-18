/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:39 by fcardina          #+#    #+#             */
/*   Updated: 2024/09/18 17:22:50 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <iostream>

class EasyFindException : public std::exception {
	public:
		const char* what() const throw() {
			return "easyfind: exception: element not found in the container";
		}
};

template<typename T>
typename T::iterator easyfind(T& container, int to_find)
{
	typename T::iterator it = std::find(container.begin(), container.end(), to_find);
	if (it == container.end()) {
		throw EasyFindException();
	}
	return it;
}

#endif // EASYFIND_HPP
