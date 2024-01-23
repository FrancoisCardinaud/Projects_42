/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:38:32 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/23 16:12:51 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	private:
		int					_RawBits;
		static const int	_bits = 8;
	
	public:
		Fixed(); //Default constructor
		Fixed(const Fixed &f); //Copy constructor
		Fixed &operator=(const Fixed &f_1); //Copy assignment operator
        ~Fixed(); //Destructor

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
