/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcardina <fcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:15:14 by fcardina          #+#    #+#             */
/*   Updated: 2024/02/06 20:20:46 by fcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
	//AAnimal *aanimal = new AAnimal();

    // Create an array of Animal pointers
    const int numAnimals = 2;
    AAnimal *aanimals[numAnimals];

    // Fill the array with half Dog and half Cat objects
    for (int i = 0; i < numAnimals; i++)
    {
        if (i < numAnimals / 2)
            aanimals[i] = new Dog();
        else
            aanimals[i] = new Cat();
    }

    // Make some deep copies of animals
    for (int i = 0; i < numAnimals; i++)
    {
        AAnimal *aanimal = aanimals[i];
        if (aanimal->getType() == "Dog")
        {
            std::cout << std::endl;
            Dog *dog = dynamic_cast<Dog*>(aanimal);

            // Testing for deep copy
            Dog dogCopy(*dog);  // Create a copy using the copy constructor
            dogCopy.getBrain()->setIdea(0, "New Dog Idea");  // Modify the copy

            std::cout << "Original Dog's Idea: " << dog->getBrain()->getIdea(0) << std::endl;
            std::cout << "Copied Dog's Idea: " << dogCopy.getBrain()->getIdea(0) << std::endl;
			dog->makeSound();    // "Woof!"
            std::cout << std::endl;

        }
        else if (aanimal->getType() == "Cat")
        {
            std::cout << std::endl;
            Cat *cat = dynamic_cast<Cat*>(aanimal);

            // Testing for deep copy
            Cat catCopy(*cat);  // Create a copy using the copy constructor
            catCopy.getBrain()->setIdea(0, "New Cat Idea");  // Modify the copy
            
            std::cout << "Original Cat's Idea: " << cat->getBrain()->getIdea(0) << std::endl;
            std::cout << "Copied Cat's Idea: " << catCopy.getBrain()->getIdea(0) << std::endl;
			cat->makeSound();    // "Meow!"
            std::cout << std::endl;
        }
    }

    // Delete the original animals and their brains
    for (int i = 0; i < numAnimals; i++)
    {
        delete aanimals[i];
    }

    return (0);
}
