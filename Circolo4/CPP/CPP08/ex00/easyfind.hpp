/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:39 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:29:40 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <string>
# include <exception>
# include <algorithm>

class EasyFindException : public std::exception {
	public:
		const char *what() const throw() {
			return "easyfind: exception: element not found within container";
   		}
};

template<typename T>
bool easyfind(T& container, int to_find)
{
	if (std::find(container.begin(), container.end(), to_find) == container.end())
	{
		throw EasyFindException();
		return false;
	}
	else
		return true;
}

#endif // EASYFIND_HPP