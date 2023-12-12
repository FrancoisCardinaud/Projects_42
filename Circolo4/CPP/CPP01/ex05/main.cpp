/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 12:55:21 by fcardina          #+#    #+#             */
/*   Updated: 2023/12/03 12:56:42 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;

    harl.complain("INFO");
    harl.complain("DEBUG");
    harl.complain("ERROR");
    harl.complain("WARNING");
    return 0;
}