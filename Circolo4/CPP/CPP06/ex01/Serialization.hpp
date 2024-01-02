/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:26:49 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:26:51 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <string>
# include <stdint.h>
# include "Data.hpp"

class Serialization {
	public:
		static uintptr_t serialize(data_t *ptr);
		static data_t *deserialize(uintptr_t raw);
};

#endif // SERIALIZATION_HPP