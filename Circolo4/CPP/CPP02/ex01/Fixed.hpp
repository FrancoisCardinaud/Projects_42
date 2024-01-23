/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:40:26 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/23 16:21:20 by fcardina         ###   ########.fr       */
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
		Fixed();
		Fixed(const Fixed &f);
		Fixed &operator=(const Fixed &f2);
        ~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed(const int integer);
		Fixed(const float floating_point);

		int		toInt( void ) const;
		float	toFloat( void ) const;
};

std::ostream	&operator<<(std::ostream &stream, Fixed const &f);

#endif