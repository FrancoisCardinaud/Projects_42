/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:40:26 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/11 04:51:51 by fcardina         ###   ########.fr       */
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

		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream	&operator<<(std::ostream &stream, Fixed const &f);

#endif