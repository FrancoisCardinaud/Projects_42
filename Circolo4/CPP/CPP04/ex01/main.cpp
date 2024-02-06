/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:13:11 by fcardina          #+#    #+#             */
/*   Updated: 2024/02/06 03:43:50 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // Create an array of Animal pointers
    const int numAnimals = 2;
    Animal *animals[numAnimals];

    // Fill the array with half Dog and half Cat objects
    for (int i = 0; i < numAnimals; i++)
    {
        if (i < numAnimals / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    // Make some deep copies of animals
    for (int i = 0; i < numAnimals; i++)
    {
        Animal *animal = animals[i];
        if (animal->getType() == "Dog")
        {
            std::cout << std::endl;
            Dog *dog = dynamic_cast<Dog*>(animal);

            // Testing for deep copy
            Dog dogCopy(*dog);  // Create a copy using the copy constructor
            dogCopy.getBrain()->setIdea(0, "New Dog Idea");  // Modify the copy

            std::cout << "Original Dog's Idea: " << dog->getBrain()->getIdea(0) << std::endl;
            std::cout << "Copied Dog's Idea: " << dogCopy.getBrain()->getIdea(0) << std::endl;
            std::cout << std::endl;

        }
        else if (animal->getType() == "Cat")
        {
            std::cout << std::endl;
            Cat *cat = dynamic_cast<Cat*>(animal);

            // Testing for deep copy
            Cat catCopy(*cat);  // Create a copy using the copy constructor
            catCopy.getBrain()->setIdea(0, "New Cat Idea");  // Modify the copy
            
            std::cout << "Original Cat's Idea: " << cat->getBrain()->getIdea(0) << std::endl;
            std::cout << "Copied Cat's Idea: " << catCopy.getBrain()->getIdea(0) << std::endl;
            std::cout << std::endl;
        }
    }

    // Delete the original animals and their brains
    for (int i = 0; i < numAnimals; i++)
    {
        delete animals[i];
    }

    return (0);
}