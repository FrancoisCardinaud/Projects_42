/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:26:49 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/24 16:32:28 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <stdint.h>  // for uintptr_t
# include "Data.hpp"

class Serialization {
    public:
        static uintptr_t serialize(Data *ptr);
        static Data* deserialize(uintptr_t raw);
        
    private:
        Serialization();
        Serialization(const Serialization&);
        Serialization& operator=(const Serialization&);
        ~Serialization() {};
};

#endif // SERIALIZATION_HPP
