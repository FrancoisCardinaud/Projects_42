/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:26:57 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/29 16:29:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Base.hpp"


using std::cerr;


Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int	main(int argc, char **argv)
{
    if (argc > 1 && argv)
    {
        cerr << "realtype: error: command-line arguments aren't supported" << std::endl;
        return EXIT_FAIL;
    }
    Base *c;
    
    cout << "TEST 1" << std::endl;
    c = generate();

    cout << std::endl;
    identify(c);
    identify(*c);

    delete c;
    return EXIT_SUCCESS;
}
