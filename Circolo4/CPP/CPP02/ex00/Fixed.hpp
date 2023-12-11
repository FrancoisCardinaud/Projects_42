/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 23:38:32 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/11 04:32:46 by fcardina         ###   ########.fr       */
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
		Fixed	&operator=(const Fixed &f2);
        ~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif