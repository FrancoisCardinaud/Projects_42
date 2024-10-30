/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:28:58 by fcardina          #+#    #+#             */
/*   Updated: 2024/10/29 16:27:01 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
const T& min(const T& a, const T& b)
{
    return (a < b ? a : b);
}

template <typename T>
const T& max(const T& a, const T& b)
{
    return (a > b ? a : b);
}

#endif
