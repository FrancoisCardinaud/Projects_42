/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:26:57 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/14 17:26:28 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Base.hpp"

using std::cout;
using std::cerr;
using std::endl;

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

int	main(int argc, char **argv)
{
    if (argc > 1 && argv)
    {
        cerr << "realtype: error: command-line arguments aren't supported" << endl;
        return EXIT_FAIL;
    }
    Base *c;
    
    cout << "TEST 1" << endl;
    c = generate();

    cout << endl;
    identify(c);
    identify(*c);

    delete c;
    return EXIT_SUCCESS;
}
