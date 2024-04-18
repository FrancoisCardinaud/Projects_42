/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:26:41 by fcardina          #+#    #+#             */
/*   Updated: 2024/01/02 19:26:48 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

uintptr_t Serialization::serialize(data_t *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

data_t *Serialization::deserialize(uintptr_t raw) {
	return reinterpret_cast<data_t*>(raw);
}
