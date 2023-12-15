/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:56:17 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/03 12:56:20 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>
# include <cstdlib>

using	std::string;
using	std::cout;
using	std::cin;
using	std::endl;

class Harl 
{
	public:

	Harl();
	~Harl();
	void	complain(std::string level);

	private:

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};

#endif