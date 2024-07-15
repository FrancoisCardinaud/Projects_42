/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:29:12 by fcardina          #+#    #+#             */
/*   Updated: 2024/07/14 17:26:28 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Array.hpp"

using std::cout;
using std::cerr;
using std::endl;

/* #define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i += 1)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i += 1)
    {
        if (mirror[i] != numbers[i])
        {
            cerr << "didn't save the same value!!" << endl;
            return EXIT_FAIL;
        }
    }
    try {
        numbers[-2] = 0;
    }
    catch(const std::exception& e) {
        cerr << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e) {
        cerr << e.what() << '\n';
    }   
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
    delete[] mirror;//
    return EXIT_SUCCESS;
} */

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	Array<int>	a(3);
	Array<int>	b(3);

	for (size_t i = 0; i < a.size(); i += 1) {
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
	cout << endl;
	for (size_t i = 0; i < b.size(); i += 1) {
		cout << "b[" << i << "] = " << b[i] << "\n";
	}
	a[0] = 1;
	a[1] = 1;
	a[2] = 1;
	cout << endl;
	cout << "AFTER FILLING A WITH 1's" << endl;
	for (size_t i = 0; i < a.size(); i += 1) {
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
	cout << endl;
	for (size_t i = 0; i < b.size(); i += 1) {
		cout << "b[" << i << "] = " << b[i] << "\n";
	}
	b = a;

	cout << "AFTER B = A" << endl;
	for (size_t i = 0; i < a.size(); i += 1) {
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
	cout << endl;
	for (size_t i = 0; i < b.size(); i += 1) {
		cout << "b[" << i << "] = " << b[i] << "\n";
	}


    // Empty Array
    Array<int> empty;

	// OUT OF BOUNDS EXCEPTION
    try {
        cout << a[a.size() + 1] << endl;
    }
    catch (std::exception& e) {
        cerr << e.what() << endl;
    }

	return EXIT_SUCCESS;
}
